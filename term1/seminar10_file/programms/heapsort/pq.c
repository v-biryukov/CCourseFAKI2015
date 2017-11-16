#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "pq.h"

struct pq {
    int element_length;
    int (*compare)(const void *, const void *);
    int n;      /* number of elements */
    int size;   /* number of slots in data */
    void *swap_space;   /* element_length bytes used for swapping */
    void *data;
};

#define PQ_INITIAL_SIZE (128)

PQ
pq_create(int element_length, int (*compare)(const void *, const void *))
{
    PQ pq;

    pq = malloc(sizeof(*pq));
    assert(pq);

    pq->element_length = element_length;
    pq->compare = compare;
    pq->n = 0;
    pq->size = PQ_INITIAL_SIZE;

    pq->swap_space = malloc(pq->element_length);
    assert(pq->swap_space);

    pq->data = malloc(pq->element_length * pq->size);
    assert(pq->data);

    return pq;
}

void
pq_destroy(PQ pq)
{
    free(pq->data);
    free(pq->swap_space);
    free(pq);
}

int
pq_is_empty(PQ pq)
{
    return pq->n == 0;
}

/* Child(i, 0) and Child(i, 1) are children of i */
/* Parent(i) is parent of i */
#define Child(i, x) (2*(i)+1+(x))
#define Parent(i) (((i)-1)/2)

#define NUM_CHILDREN (2)

/* compute the address of position i in the data field */
#define REF(pq, i) ((void *) (((char *) (pq)->data) + (pq)->element_length * i))

/* swap elements at indexes i1 and i2 */
static void
pq_swap(PQ pq, int i1, int i2)
{
    memcpy(pq->swap_space, REF(pq, i1), pq->element_length);
    memcpy(REF(pq, i1), REF(pq, i2), pq->element_length);
    memcpy(REF(pq, i2), pq->swap_space, pq->element_length);
}

void
pq_insert(PQ pq, const void *elt)
{
    int floater;                /* new element */

    while(pq->n + 1 > pq->size) {
        pq->size *= 2;
        pq->data = realloc(pq->data, pq->element_length * pq->size);
        assert(pq->data);
    }

    /* copy the new element in */
    floater = pq->n++;
    memcpy(REF(pq, floater), elt, pq->element_length);

    /* float it up until it is at the top */
    /* or it is no smaller than its parent */
    while(floater > 0 && pq->compare(REF(pq, floater), REF(pq, Parent(floater))) <= 0) {
        /* it's smaller than its parent */
        pq_swap(pq, floater, Parent(floater));
        floater = Parent(floater);
    }
}

void
pq_delete_min(PQ pq, void *retval)
{
    int floater;        /* previous loser floating down */
    int small_child;    /* smaller child of floater */
    
    assert(!pq_is_empty(pq));

    /* first copy out the winner */
    memcpy(retval, REF(pq, 0), pq->element_length);

    --(pq->n);

    if(pq_is_empty(pq)) {
        /* pq empty, nothing to do */
        return;
    }

    /* else */
    memcpy(REF(pq, 0), REF(pq, pq->n), pq->element_length);

    floater = 0;

    for(;;) {
        /* find smaller child of floater */
        if(Child(floater, 0) >= pq->n) {
            return;     /* no children, bail out */
        } else if(Child(floater, 1) >= pq->n) {
            small_child = Child(floater, 0);
        } else if(pq->compare(REF(pq, Child(floater, 0)), REF(pq, Child(floater, 1))) < 0) {
            small_child = Child(floater, 0);
        } else {
            small_child = Child(floater, 1);
        }

        /* is floater <= small_child? */
        if(pq->compare(REF(pq, floater), REF(pq, small_child)) <= 0) {
            /* yes, we are done */
            return;
        } else {
            /* no, swap and continue floating down */
            pq_swap(pq, floater, small_child);
            floater = small_child;
        }
    }
}

void
pq_sanity_check(PQ pq)
{
    int i;
    int j;

    assert(pq->n >= 0);
    assert(pq->n <= pq->size);

    for(i = 0; i < pq->n; i++) {
        for(j = 0; j < NUM_CHILDREN; j++) {
            if(Child(i, j) < pq->n) {
                assert(pq->compare(REF(pq, i), REF(pq, Child(i, j))) <= 0);
            }
        }
    }
}
