#include <iostream>
#include <unistd.h>
#include <climits>
#include <math.h>
#include <cstring>
#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

int N=1, R=1, S, D, T, i, j, tmp, c=1, p=0;
int adj[101][101]; //Adjacency Matrix, Row 0 used as marked


void readEdge(){
    cin >> i >> j >> tmp;
    adj[i][j] = tmp;
    adj[j][i] = tmp;
}


int dfs(int v, int cmin){
    if(v == D) { //Found destination
    // cout << "FOUND" << endl;
        return cmin; 
    }

    adj[0][v] = 1; //Mark current node as visited

    //Loop though all neighbours not visited
    for(int i=1; i<=N; i++){
        if(!adj[0][i] && adj[v][i]){
            // cout << v << " " << i << " " << adj[v][i] << endl;
            if(adj[v][i] < cmin) cmin = adj[v][i];
            int tmp = dfs(i, cmin);
            if(tmp && tmp > p){
                p = tmp;                
            } 
            adj[0][i] = 0;
        }
    }
    
    return p > 0? p : 0;
}

void printResult(int i, int j){
    cout << "Scenario #" << i << endl;
    cout << "Minimum Number of Trips = " << j << endl << endl;
}

int minTrips(int m){
    return ceil(T / (double) (m-1));
}

void clear(){
    for(i = 0; i<101; i++){
        memset(adj[i], 0, sizeof(adj[i]));
    }
    p=0;
}

int main() {
    prepare_ide("p10099");     // For IDE only
    // Fill adjacency matrix
    

    while(true){
        clear();
        cin >> N >> R;
        if(N==0 && R==0) break;
        while(R--){
            readEdge();
        }
        cin >> S >> D >> T;
        tmp = dfs(S, INT_MAX);
        // cout << tmp << ": ";
        printResult(c, minTrips(tmp));



        c++;
    }
    

    execute_tests();     // For IDE only
}

