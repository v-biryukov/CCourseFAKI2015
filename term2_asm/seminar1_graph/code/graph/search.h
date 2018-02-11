/* Typical usage:
 *
 *    struct search_info *s;
 *    int n;
 *
 *    s = search_info_create(g);
 *
 *    n = graph_vertices(g);
 *    for(i = 0; i < n; i++) {
 *        dfs(s, i);
 *    }
 *
 *    ... use results in s ...
 *
 *    search_info_destroy(s);
 *
 */

/* summary information per node for dfs and bfs */
/* this is not intended to be opaque---user can read it */
/* (but should not write it!) */

#define SEARCH_INFO_NULL (-1) /* for empty slots */

struct search_info {
    Graph graph;
    int reached;        /* count of reached nodes */
    int *preorder;      /* list of nodes in order first reached */
    int *time;          /* time[i] == position of node i in preorder list */
    int *parent;        /* parent in DFS or BFS forest */
    int *depth;         /* distance from root */
};

/* allocate and initialize search results structure */
/* you need to do this before passing it to dfs or bfs */
struct search_info *search_info_create(Graph g);

/* free search_info data---does NOT free graph pointer */
void search_info_destroy(struct search_info *);

/* perform depth-first search starting at root, updating results */
void dfs(struct search_info *results, int root);

/* perform breadth-first search starting at root, updating results */
void bfs(struct search_info *results, int root);
