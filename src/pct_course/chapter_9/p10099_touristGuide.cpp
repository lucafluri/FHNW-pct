#include <iostream>
#include <unistd.h>
#include <climits>
#include <math.h>
#include <cstring>
#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

int N=1, R=1, S, D, T, i, j, k, c=1, p=0;
int adj[101][101]; //Adjacency Matrix, Row 0 used as marked


void readEdge(){
    cin >> i >> j >> k;
    adj[i][j] = k;
    adj[j][i] = k;
}


void dfs(int v, int cmin){
    if(v == D) { //Found destination
        if(cmin > p) p = cmin;
        return; 
    }

    adj[0][v] = 1; //Mark current node as visited

    //Loop though all neighbours not visited
    for(int i=1; i<=N; i++){
        if(!adj[0][i] && adj[v][i]){
            dfs(i, adj[v][i] < cmin? adj[v][i] : cmin);
            adj[0][i] = 0; //Mark visited node as unvisited after visit
        }
    }
    
}

void fw(){
    for(k=1; k<=N; k++){
        for(i=1; i<=N; i++){
            for(j=1; j<=N; j++){
                adj[i][j] = adj[j][i] = max(adj[i][j], min(adj[i][k], adj[k][j]));
            }
        }
    }
    p = adj[S][D];
}

void printResult(int i, int j){
    cout << "Scenario #" << i << endl;
    cout << "Minimum Number of Trips = " << j << endl << endl;
}

int minTrips(){
    return ceil(T / (double) (p-1));
}

void clear(){
    for(i = 0; i<101; i++){
        memset(adj[i], 0, sizeof(adj[i]));
    }
    p=0;
}

int main() {
    prepare_ide("p10099");     // For IDE only

    while(true){
        clear();
        cin >> N >> R;
        if(N==0 && R==0) break;
        while(R--){
            readEdge();
        }
        cin >> S >> D >> T;

        // dfs(S, INT_MAX);
        fw();

        printResult(c, minTrips());

        c++;
    }

    execute_tests();     // For IDE only
}

