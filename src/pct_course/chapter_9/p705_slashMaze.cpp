#include <iostream>
#include <unistd.h>
#include <cstring>
#include <string>

#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

int n, w, h, k=0, c, mc=0, t;
bool cycle = true;
string tmp;

int maze[230][230]; //maze matrix

void clear(){
    for(int i = 0; i<230; i++){
        memset(maze[i], 0, sizeof(maze[i]));
    }
    k = 0; //# of loops
    mc = 0;
    t=1;
}

void printResult(int l){
    cout << "Maze #" << n  << ":" << endl;
    cout << k << " Cycles; the longest has length " << l/3 << "." << endl << endl;
}

void printNoCycles(){
    cout << "Maze #" << n  << ":" << endl;
    cout << "There are no cycles." << endl << endl;
}

void floodfill(int x, int y){
    
    if(x < 0 || y < 0 || x > (h*3)|| y > (w*3) ) { // Out of bounds
        cycle = false;
        return;
    }
    else if(maze[x][y] == -1 || maze[x][y] == t) return; //If wall or way back

    maze[x][y] = t; // Color square, 1 as visited, 0 not and -1 wall
    c++;

    floodfill(x+1, y);
    floodfill(x-1, y);
    floodfill(x, y+1);
    floodfill(x, y-1);
}

int main() {
    prepare_ide("p705");     // For IDE only
    
    // Read in vars
    while(true){
        cin >> w >> h;
        n++;
        if(w==0 && h==0) break;
        
        // Clear adj matrix and matrix
        clear();

        // Build Maze Matrix
        for(int i = 0; i < h; i++){
            cin >> tmp; // get line
            for(int j = 0; j < w; j++){
                if(tmp[j] == '\\'){
                    maze[i*3][j*3] = maze[i*3+1][j*3+1] = maze[i*3+2][j*3+2] = -1;
                }
                else if(tmp[j] == '/'){
                    maze[i*3][j*3+2] = maze[i*3+1][j*3+1] = maze[i*3+2][j*3] = -1;
                }
            }
        }
        if(w!=1 && h!=1) {
            // Floodfill and count cycles => /=3
            // Loop through all squares and floodfill 
            // after that check cc (cycle count) and mc (max count)
            for(int i = 2; i<h*3 - 2; i++){
                for(int j = 2; j<w*3 - 2; j++){
                    if(maze[i][j] == 0){
                        floodfill(i, j);
                        t++;
                        if(cycle){
                            k++;
                            if(c > mc) mc = c; //set new max cycle 
                        }
                        c=0;
                        cycle = true;
                    }
                }
            }
        }

        if(k > 0) printResult(mc);
        else printNoCycles();
    }

    execute_tests();     // For IDE only
}   
