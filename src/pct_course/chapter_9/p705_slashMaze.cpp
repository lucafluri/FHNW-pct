#include <iostream>
#include <unistd.h>
#include <cstring>
#include <string>

#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;


int n, w, h, k;
string tmp;

int maze[150][150]; //adjacency list
int adj[22000][2]; //adjacency list


void clear(){
    for(int i = 0; i<75; i++){
        memset(maze[i], 0, sizeof(maze[i]));
    }
    k=0; //# of loops
}

void printResult(int l){
    cout << "Maze #" << n  << ":" << endl;
    cout << k << "Cycles; the longest has length " << l << "." << endl;
}

void printNoCycles(){
    cout << "Maze #" << n  << ":" << endl;
    cout << "There are no cycles." << endl;
}


int main() {
    prepare_ide("p705");     // For IDE only
    
    // Read in vars
    while(true){
        cin >> w >> h;
        n++;
        if(w==0 && h==0) break;
        else if(w==1 ||  h==1) printNoCycles();

        // Clear adj matrix and matrix
        clear();
        // cout << (int) '/' << " " << (int) '\\';

        // Build Maze Matrix
        for(int i = 0; i < h; i++){
                cin >> tmp; // get line
                for(int j = 0; j < w; j++){
                    if(tmp[j] == '/'){
                        //  |1 2| 
                        //  |3 4|
                        maze[i*2][j*2] = 1;
                        maze[i*2][j*2+1] = 0;
                        maze[i*2+1][j*2] = 1;
                        maze[i*2+1][j*2+1] = 0;
                    }
                    else if(tmp[j] == '\\'){
                        maze[i*2][j*2] = 0;
                        maze[i*2][j*2+1] = 1;
                        maze[i*2+1][j*2] = 0;
                        maze[i*2+1][j*2+1] = 1;
                    }
                }
        }

        // Build adj list?
        for(int i = 1; i < h-1; i++){
            for(int j = 1; j < w-1; j++){
                
                if(maze[i][j]){
                    // Check all 4 directions
                    if()
                    // Check diagonals, check for wall
                }
                
            }
        }

        // Use DFS to find longest cycle

    }

    

    execute_tests();     // For IDE only
}   
