#include <stdlib.h>
#include <assert.h>
#include <values.h>

#include "graph.h"

/* basic directed graph type */
/* the implementation uses adjacency lists
 * represented as variable-length arrays */

/* these arrays may or may not be sorted: if one gets long enough
 * and you call graph_has_edge on its source, it will be */


struct graph {
    int n;              /* number of vertices */
    int m;              /* number of edges */
    struct successors {
        int d;          /* number of successors */
        int len;        /* number of slots in array */
        char is_sorted; /* true if list is already sorted */
        struct edge {
            int sink;           /* other end of edge */
            int weight;         /* used for shortest-path algorithms */
        } list[1];    /* actual list of successors */
    } *alist[1];
};

/* create a new graph with n vertices labeled 0..n-1 and no edges */
Graph
graph_create(int n)
{
    Graph g;
    int i;

    g = malloc(sizeof(struct graph) + sizeof(struct successors *) * (n-1));
    assert(g);

    g->n = n;
    g->m = 0;

    for(i = 0; i < n; i++) {
        g->alist[i] = malloc(sizeof(struct successors));
        assert(g->alist[i]);

        g->alist[i]->d = 0;
        g->alist[i]->len = 1;
        g->alist[i]->is_sorted= 1;
    }
    
    return g;
}

/* free all space used by graph */
void
graph_destroy(Graph g)
{
    int i;

    for(i = 0; i < g->n; i++) free(g->alist[i]);
    free(g);
}

/* add an edge to an existing graph */
void
graph_add_weighted_edge(Graph g, int u, int v, int wt)
{
    assert(u >= 0);
    assert(u < g->n);
    assert(v >= 0);
    assert(v < g->n);

    /* do we need to grow the list? */
    while(g->alist[u]->d >= g->alist[u]->len) {
        g->alist[u]->len *= 2;
        g->alist[u] =
            realloc(g->alist[u], 
                sizeof(struct successors) + sizeof(struct edge) * (g->alist[u]->len - 1));
    }

    /* now add the new sink */
    g->alist[u]->list[g->alist[u]->d].sink = v;
    g->alist[u]->list[g->alist[u]->d].weight = wt;
    g->alist[u]->d++;
    g->alist[u]->is_sorted = 0;

    /* bump edge count */
    g->m++;
}

void
graph_add_edge(Graph g, int u, int v)
{
    graph_add_weighted_edge(g, u, v, GRAPH_DEFAULT_EDGE_WEIGHT);
}

/* return the number of vertices in the graph */
int
graph_vertex_count(Graph g)
{
    return g->n;
}

/* return the number of vertices in the graph */
int
graph_edge_count(Graph g)
{
    return g->m;
}

/* return the out-degree of a vertex */
int
graph_out_degree(Graph g, int source)
{
    assert(source >= 0);
    assert(source < g->n);

    return g->alist[source]->d;
}

/* when we are willing to call bsearch */
#define BSEARCH_THRESHOLD (10)

static int
edgecmp(const void *a, const void *b)
{
    return ((const struct edge *) a)->sink - ((const struct edge *) b)->sink;
}

/* return 1 if edge (source, sink) exists), 0 otherwise */
static
int
graph_has_edge_internal(Graph g, int source, int sink, int *weight)
{
    int i;
    struct edge sinkedge;
    struct edge *bsearch_result;

    assert(source >= 0);
    assert(source < g->n);
    assert(sink >= 0);
    assert(sink < g->n);

    /* default if not found */
    *weight = MAXINT;

    if(graph_out_degree(g, source) >= BSEARCH_THRESHOLD) {
        /* make sure it is sorted */
        if(! g->alist[source]->is_sorted) {
            qsort(g->alist[source]->list,
                    g->alist[source]->d,
                    sizeof(struct edge),
                    edgecmp);
        }
        
        /* call bsearch to do binary search for us */
        sinkedge.sink = sink;
        sinkedge.weight = GRAPH_DEFAULT_EDGE_WEIGHT;
        bsearch_result =
            bsearch(&sinkedge,
                    g->alist[source]->list,
                    g->alist[source]->d,
                    sizeof(struct edge),
                    edgecmp);
        if(bsearch_result != 0) {
            *weight = bsearch_result->weight;
            return 1;
        } else {
            return 0;
        }
    } else {
        /* just do a simple linear search */
        /* we could call lfind for this, but why bother? */
        for(i = 0; i < g->alist[source]->d; i++) {
            if(g->alist[source]->list[i].sink == sink) {
                *weight = g->alist[source]->list[i].weight;
                return 1;
            }
        }
        /* else */
        return 0;
    }
}

int
graph_has_edge(Graph g, int source, int sink)
{
    int dummy;

    return graph_has_edge_internal(g, source, sink, &dummy);
}

int
graph_edge_weight(Graph g, int source, int sink)
{
    int weight;

    graph_has_edge_internal(g, source, sink, &weight);
    
    return weight;
}

/* invoke f on all edges (u,v) with source u */
/* supplying data as final parameter to f */
void
graph_foreach(Graph g, int source,
    void (*f)(Graph g, int source, int sink, void *data),
    void *data)
{
    int i;

    assert(source >= 0);
    assert(source < g->n);

    for(i = 0; i < g->alist[source]->d; i++) {
        f(g, source, g->alist[source]->list[i].sink, data);
    }
}

/* invoke f on all edges (u,v) with source u */
/* supplying data as final parameter to f */
void
graph_foreach_weighted(Graph g, int source,
    void (*f)(Graph g, int source, int sink, int weight, void *data),
    void *data)
{
    int i;

    assert(source >= 0);
    assert(source < g->n);

    for(i = 0; i < g->alist[source]->d; i++) {
        f(g, source, 
                g->alist[source]->list[i].sink,
                g->alist[source]->list[i].weight,
                data);
    }
}
