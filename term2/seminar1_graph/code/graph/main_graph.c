#include <stdio.h>
#include <assert.h>

#include "graph.h"


int
main(int argc, char **argv)
{
    Graph g;
    int i;
    int j;

    g = graph_create(10);

    /* fill in the diagonal */
    for(i = 0; i < 10; i++) {
        graph_add_edge(g, i, (i + 1) % 10);
        graph_add_edge(g, (i + 1) % 10, i);
    }

    graph_add_edge(g, 3, 7);
    graph_add_edge(g, 6, 2);

    printf("Numer of vertices = %d\n", graph_vertex_count(g));
    printf("Numer of edges = %d\n", graph_edge_count(g));

    printf("Out deegree of vertex #3 = %d\n", graph_out_degree(g, 3));
    printf("Out deegree of vertex #4 = %d\n", graph_out_degree(g, 4));



    /* free it */
    graph_destroy(g);

    return 0;
}
