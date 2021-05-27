#include <iostream>
#include <unistd.h>
#include <math.h>
#include <cstring>
#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

int N=1, R=1, S, D, T, i, j, tmp;
int adj[101][101]; //Adjacency Matrix, Row 0 used as marked


void readEdge(){
    cin >> i >> j >> tmp;
    adj[i][j] = tmp;
    adj[j][i] = tmp;
}

void printMatrix(){
    for(i = 0; i<N+1; i++){
        for(j=0; j<N+1; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(int v){
    adj[0][v] = 1; //visited
    for(i = 1; i<=N; i++){
        if(adj[0][i] && adj[v][i]){ //Not marked and edge present
            dfs(i);
        }
    }

}

void printResult(int i, int j){
    cout << "Scenario #" << i << endl;
    cout << "Minimum Number of Trips = " << j << endl << endl;
}

int minTrips(int m){
    return ceil(T / (m-1));
}

int main() {
    prepare_ide("p10099");     // For IDE only
    // Fill adjacency matrix
    for(i = 0; i<100; i++){
        memset(adj[i], 0, sizeof(adj[i]));
    }

    while(true){
        cin >> N >> R;
        if(N==0 && R==0) break;
        while(R--){
            readEdge();
        }
        cin >> S >> D >> T;

        // printMatrix();
    }
    

    execute_tests();     // For IDE only
}

