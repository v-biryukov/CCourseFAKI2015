/* basic directed graph type */

typedef struct graph *Graph;

/* create a new graph with n vertices labeled 0..n-1 and no edges */
Graph graph_create(int n);

/* free all space used by graph */
void graph_destroy(Graph);

/* add an edge to an existing graph */
/* doing this more than once may have unpredictable results */
/* second version specifies edge weight */
/* (first version defaults to GRAPH_DEFAULT_EDGE_WEIGHT) */
#define GRAPH_DEFAULT_EDGE_WEIGHT (1)
void graph_add_edge(Graph, int source, int sink);
void graph_add_weighted_edge(Graph, int source, int sink, int weight);

/* return the number of vertices/edges in the graph */
int graph_vertex_count(Graph);
int graph_edge_count(Graph);

/* return the out-degree of a vertex */
int graph_out_degree(Graph, int source);

/* return 1 if edge (source, sink) exists), 0 otherwise */
int graph_has_edge(Graph, int source, int sink);

/* return weight of edge, or MAXINT (from values.h) if edge doesn't exist */
int graph_edge_weight(Graph, int source, int sink);

/* invoke f on all edges (u,v) with source u */
/* supplying data as final parameter to f */
/* no particular order is guaranteed */
void graph_foreach(Graph g, int source,
        void (*f)(Graph g, int source, int sink, void *data),
        void *data);

/* like above but also supplies weight */
void graph_foreach_weighted(Graph g, int source,
        void (*f)(Graph g, int source, int sink, int weight, void *data),
        void *data);
