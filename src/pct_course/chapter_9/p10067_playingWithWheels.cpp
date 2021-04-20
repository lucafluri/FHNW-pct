#include <iostream>
#include <unistd.h>
#include <list>
#include <string>
#include <vector>
#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

// Graph
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



int main() {
    prepare_ide("p10067");     // For IDE only

    

    execute_tests();     // For IDE only
}

