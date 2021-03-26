#include <iostream>
#include <unistd.h>
#include <list>
#include <string>
#include <vector>
#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;


typedef struct {
    vector<int> *edges;
    // vector<int> *degree;
    int nvertices;
    int nedges;
} graph;

void initialize_graph(graph *g, int vertices, int edges)
{
    g -> nvertices = vertices;
    g -> nedges = edges;
    // for (int i=1; i<=vertices; i++) g->degree[i] = 0;
    // g -> degree = new vector<int>(vertices, 0);
    g -> edges = new vector<int>[vertices];
}

void insert_edge(graph *g, int x, int y)
{
    // if (g->degree[x] > MAXDEG)
        // printf("Warning: insertion(%d,%d) exceeds max degree\n",x,y);
    g->edges[x].push_back(y);
    g->edges[y].push_back(x);
    // (g->degree)[x]++;
}

bool read_graph(graph *g){
    string buffer;

    int e=0; /* number of edges */
    int v=0; /* number of vertces */
    int x, y; /* vertices in edge (x,y) */
    
    scanf("%d",&v);
    scanf("%d",&e);

    initialize_graph(g, v, e);
    // printf("%d, %d\n", g->nvertices, m);

    for (int i=0; i<e; i++) {
        scanf("%d %d",&x,&y);
        // printf("%d, %d\n", x, y);
        insert_edge(g,x,y);
    }
    getline(cin, buffer);
    // bool end = (char) cin.peek() == '0';
    // cout << end << endl;
    return ((char) cin.peek()) != '0';
    // return true;
}

void print_graph(graph *g)
{
    printf("%d::%d\n", g->nvertices, g->nedges);
    int i,j; /* counters */
    for (i=0; i<g->nvertices; i++) {
        printf("%d: ",i);
        for (j=0; j<g->edges[i].size(); j++)
            printf(" %d",g->edges[i][j]);
        printf("\n");
    }
}

bool bfs(graph *g, int start) {
    bool *visited = new bool[g->nvertices];
    int *colored = new int[g->nvertices];
    for(int i = 0; i < g->nvertices; i++){
        visited[i] = false;
        colored[i] = 0;
    }

    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[start] = true;
    colored[start] = 1; //red=1, black=2
    queue.push_back(start);

    // adjacent vertices of a vertex
    vector<int>::iterator adj;
    bool parent_color;

    while(!queue.empty())
    {
        start = queue.front();

        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex
        for (adj = g->edges[start].begin(); adj != g->edges[start].end(); ++adj)
        {
            if(colored[*adj] == colored[start]) return false;
            else colored[*adj] = colored[start] == 1 ? 2 : 1;

            if (!visited[*adj])
            {
                visited[*adj] = true;
                queue.push_back(*adj);
            }
        }
    }
    return true;
}

int main() {
    prepare_ide("p10004");     // For IDE only

    graph g;

    bool more = true;
    while(more){
        more = read_graph(&g);
        // print_graph(&g);

        if(bfs(&g, 0)){
            printf("BICOLORABLE.\n");
        }else{
            printf("NOT BICOLORABLE.\n");
        }
    }

    execute_tests();     // For IDE only
}

