#define DIJKSTRA_NULL_PARENT (-1)

/* Computes distance of each node from starting node */
/* and stores results in dist (length n, allocated by the caller) */
/* unreachable nodes get distance MAXINT */
/* If parent argument is non-null, also stores parent pointers in parent */
/* Assumes no negative-weight edges */
/* Runs in O(n + m log m) time. */
/* Note: uses pq structure from pq.c */
void dijkstra(Graph g, int source, int *dist, int *parent);
