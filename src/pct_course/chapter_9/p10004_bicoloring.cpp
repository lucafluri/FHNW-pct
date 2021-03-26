#include <iostream>
#include <unistd.h>
#include <list>
#include <string>
#include <vector>
#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

// #define MAXV    200
// #define MAXDEG  200

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
    // Mark all the vertices as not visited
    bool *visited = new bool[g->nvertices];
    int *colored = new int[g->nvertices];
    for(int i = 0; i < g->nvertices; i++){
        visited[i] = false;
        colored[i] = 0;
    }

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[start] = true;
    colored[start] = 1; //red=1, black=2
    queue.push_back(start);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    vector<int>::iterator i;
    bool parent_color;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        start = queue.front();

        // parent_color = colored[start];
        // printf("parent %d: %d\n", start, colored[start]);
        // cout << start << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = g->edges[start].begin(); i != g->edges[start].end(); ++i)
        {
            if(colored[*i] == colored[start]) return false;
            else colored[*i] = colored[start] == 1 ? 2 : 1;
            // printf("%d:%d, ", *i, colored[*i]);

            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
        // printf("\n");

        
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

        // cout << (char) cin.peek() << endl;

        if(bfs(&g, 0)){
            printf("BICOLORABLE.\n");
        }else{
            printf("NOT BICOLORABLE.\n");
        }

        // printf(cin.peek());
    }

    execute_tests();     // For IDE only
}

