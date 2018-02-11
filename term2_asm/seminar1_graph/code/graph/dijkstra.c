#include <stdlib.h>
#include <assert.h>
#include <values.h>

#include "graph.h"
#include "pq.h"
#include "dijkstra.h"

/* internal edge representation for dijkstra */
struct pq_elt {
    int d;      /* distance to v */
    int u;      /* source */
    int v;      /* sink */
};

static int
pq_elt_cmp(const void *a, const void *b)
{
    return ((const struct pq_elt *) a)->d - ((const struct pq_elt *) b)->d;
}

struct push_data {
    PQ pq;
    int *dist;
};

static void push(Graph g, int u, int v, int wt, void *data)
{
    struct push_data *d;
    struct pq_elt e;

    d = data;

    e.d = d->dist[u] + wt;
    e.u = u;
    e.v = v;

    pq_insert(d->pq, &e);
}

void
dijkstra(Graph g, int source, int *dist, int *parent)
{
    struct push_data data;
    struct pq_elt e;
    int n;
    int i;

    assert(dist);

    data.dist = dist;
    data.pq = pq_create(sizeof(struct pq_elt), pq_elt_cmp);
    assert(data.pq);

    n = graph_vertex_count(g);

    /* set up dist and parent arrays */
    for(i = 0; i < n; i++) {
        dist[i] = MAXINT;
    }
        
    if(parent) {
        for(i = 0; i < n; i++) {
            parent[i] = DIJKSTRA_NULL_PARENT;
        }
    }

    /* push (source, source, 0) */
    /* this will get things started with parent[source] == source */
    /* and dist[source] == 0 */
    push(g, source, source, -MAXINT, &data);

    while(!pq_is_empty(data.pq)) {
        /* pull the min value out */
        pq_delete_min(data.pq, &e);

        /* did we reach the sink already? */
        if(dist[e.v] == MAXINT) {
            /* no, it's a new edge */
            dist[e.v] = e.d;
            if(parent) parent[e.v] = e.u;

            /* throw in the outgoing edges */
            graph_foreach_weighted(g, e.v, push, &data);
        }
    }

    pq_destroy(data.pq);
}
