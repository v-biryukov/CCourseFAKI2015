/* generic priority queue */

typedef struct pq *PQ;

/* create a new empty priority queue */
/* element_length is the size of an element in bytes */
/* compare is a comparision function that returns
 * <0 if its first argument is less than its second
 *  0 if they are equal
 * >0 if the first argument is greater than the second. */ 
PQ pq_create(int element_length, int (*compare)(const void *, const void *));

/* free a priority queue */
void pq_destroy(PQ);

/* add an element to the priority queue */
/* the contents of the element are COPIED from elt */
void pq_insert(PQ, const void *elt);

/* returns nonzero if PQ is empty */
int pq_is_empty(PQ);

/* delete the minimum element of the priority queue */
/* and COPY its contents to retval */
/* it is an error to call this on an empty queue */
void pq_delete_min(PQ, void *retval);

/* utility function: blows up if heap invariant is violated */
void pq_sanity_check(PQ);
