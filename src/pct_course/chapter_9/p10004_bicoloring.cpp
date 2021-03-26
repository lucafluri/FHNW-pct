#include <iostream>
#include <unistd.h>
#include <list>
#include <string>
#include <vector>
#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

typedef struct {
    vector<int> *adj;
    int nvertices;
} graph;

void initialize_graph(graph *g, int vertices) {
    g -> nvertices = vertices;
    g -> adj = new vector<int>[vertices];
}

void insert_edge(graph *g, int x, int y) {
    g->adj[x].push_back(y);
    g->adj[y].push_back(x); //All graphs are undirected
}

bool read_graph(graph *g){
    if((char) cin.peek() == '0') return false;

    string buffer;
    int e=0; // number of edges 
    int v=0; // number of vertices 
    int x, y; // edge (x,y) 
    
    // Read in nums
    scanf("%d",&v);
    scanf("%d",&e);

    initialize_graph(g, v);

    // Read and insert edges into graph
    for (int i=0; i<e; i++) {
        scanf("%d %d",&x,&y);
        insert_edge(g,x,y);
    }
    getline(cin, buffer); //Read rest of line
    return true;
}

bool bfs_coloring(graph *g, int start) {
    bool *visited = new bool[g->nvertices];
    int *colored = new int[g->nvertices];
    for(int i = 0; i < g->nvertices; i++){
        visited[i] = false;
        colored[i] = 0;
    }

    list<int> queue;
    int vertex = start;

    // Mark vertex as visited, add to queue
    visited[vertex] = true;
    queue.push_back(vertex);

    // Color first vertex red
    colored[vertex] = 1; //red=1, black=2
    
    // adjacent vertices of a vertex
    vector<int>::iterator adj;

    while(!queue.empty())
    {
        vertex = queue.front();
        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex
        for (adj = g->adj[vertex].begin(); adj != g->adj[vertex].end(); ++adj) {
            // Not Bicolorable if neighbouring nodes have same color
            // => stop bfs, else color neighbours in opposite color
            if(colored[*adj] == colored[vertex]) return false;
            else colored[*adj] = colored[vertex] == 1 ? 2 : 1;

            if (!visited[*adj]) {
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

    while(read_graph(&g)){
        if(bfs_coloring(&g, 0)){
            printf("BICOLORABLE.\n");
        }else{
            printf("NOT BICOLORABLE.\n");
        }
    }

    execute_tests();     // For IDE only
}

