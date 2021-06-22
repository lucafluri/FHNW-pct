#include <iostream>
#include <unistd.h>
#include <cstring>
#include <string>

#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;


int n, w, h, k;
string tmp;

int maze[225][225]; //maze matrix
int adj[22000][8]; //adjacency list, 8 slots, only 2 can be 1


void clear(){
    for(int i = 0; i<225; i++){
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
                if(tmp[j] == '\\'){
                    maze[i*3][j*3] = maze[i*3+1][j*3+1] = maze[i*3+2][j*3+2] = 1;
                }
                else if(tmp[j] == '/'){
                    maze[i*3][j*3+2] = maze[i*3+1][j*3+1] = maze[i*3+2][j*3] = 1;
                }
            }
        }

        // Floodfill and count cycles => /=3
        
        // // Print adj list
        // for(int i = 0; i<h*3; i++){
        //     // cout << i << ": ";
        //     for(int j = 0; j<w*3; j++){
        //         cout << maze[i][j] << " ";
        //     }
        //     cout << endl;
        // }


    }

    

    execute_tests();     // For IDE only
}   
