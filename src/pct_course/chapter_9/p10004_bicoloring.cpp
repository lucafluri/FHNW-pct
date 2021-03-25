#include <iostream>
#include <unistd.h>
#include <list>
#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

#define MAXV    200
#define MAXDEG  200

typedef struct {
    int edges[MAXV+1][MAXDEG];
    int degree[MAXV+1];
    int nvertices = 0;
    int nedges = 0;
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

void bfs(graph *g, int start) {
    // Mark all the vertices as not visited
    bool *visited = new bool[g->nvertices];
    for(int i = 0; i < g->nvertices; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[start] = true;
    queue.push_back(start);
 
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        start = queue.front();
        cout << start << " ";
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = g->edges[start].begin(); i != g->edges[start].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }

}

int main() {
    prepare_ide("p10004");     // For IDE only

    graph g;
    read_graph(&g, false);
    // print_graph(&g);

    bfs(&g, 0);

    execute_tests();     // For IDE only
}

