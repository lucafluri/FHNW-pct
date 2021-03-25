#include <iostream>
#include <unistd.h>
#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

#define MAXV    200
#define MAXDEG  200

typedef struct {
    int edges[MAXV+1][MAXDEG];
    int degree[MAXV+1];
    int nvertices;
    int nedges;
} graph;

void initialize_graph(graph *g)
{
    int i; /* counter */
    g -> nvertices = 0;
    g -> nedges = 0;
    for (i=1; i<=MAXV; i++) g->degree[i] = 0;
}

void insert_edge(graph *g, int x, int y, bool directed)
{
    if (g->degree[x] > MAXDEG)
        printf("Warning: insertion(%d,%d) exceeds max degree\n",x,y);
    g->edges[x][g->degree[x]] = y;
    g->degree[x] ++;
    if (directed == false)
        insert_edge(g,y,x,true);
    else
        g->nedges ++;
}

void read_graph(graph *g, bool directed){
    int i=0; /* counter */
    int m=0; /* number of edges */
    int x, y; /* vertices in edge (x,y) */
    initialize_graph(g);
    
    scanf("%d",&(g->nvertices));
    scanf("%d",&m);

    // printf("%d, %d\n", g->nvertices, m);

    for (i=0; i<m; i++) {
        scanf("%d %d",&x,&y);
        // printf("%d, %d\n", x, y);
        insert_edge(g,x,y,directed);
    }
}

void print_graph(graph *g)
{
    printf("%d::%d\n", g->nvertices, g->nedges);
    int i,j; /* counters */
    for (i=0; i<g->nvertices; i++) {
        printf("%d: ",i);
        for (j=0; j<g->degree[i]; j++)
            printf(" %d",g->edges[i][j]);
        printf("\n");
    }
}



int main() {
    prepare_ide("p10004");     // For IDE only

    graph g;
    read_graph(&g, false);
    print_graph(&g);

    execute_tests();     // For IDE only
}

