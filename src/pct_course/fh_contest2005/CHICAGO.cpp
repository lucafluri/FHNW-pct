#include <iostream>
#include <unistd.h>
#include <algorithm>
#include <climits>
#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

int n, m, i, j, k;
float best;
float s[100][5000];

void readEdge(){
    cin >> i >> j >> k;
    s[i-1][j-1] = k / 100.0;
    s[j-1][i-1] = k / 100.0;
}

void printResult(float i){
    printf("%.6f percent\n", i);
}


int maxDistance(float dist[], bool sptSet[])
{
    int min = 0, min_index;

    for (int v = 0; v < n; v++)
        if (sptSet[v] == false && dist[v] >= min)
            min = dist[v], min_index = v;

    return min_index;
}

void dijkstra(){
    float dist[n]; // The output array.  dist[i] will hold the shortest
    // distance from src to i

    bool sptSet[n]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < n; i++)
        dist[i] = 0, sptSet[i] = false;

    // Distance of source vertex from itself is always 1
    dist[1] = 1;

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = maxDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < n; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && s[u][v] && dist[u] != 0
                && dist[u] + s[u][v] > dist[v])
                dist[v] = dist[u] * s[u][v];
            
            cout  << dist[n-1] << endl;
    }

    best = dist[n-1];
}

int main() {
    prepare_ide("CHICAGO");     // For IDE only

    while(true){
        // clear();
        cin >> n;
        if(n==0) break;
        cin >> m;
        while(m--){
            readEdge();
        }

        dijkstra();
        printResult(best*100.0);

    }

    execute_tests();     // For IDE only
}

