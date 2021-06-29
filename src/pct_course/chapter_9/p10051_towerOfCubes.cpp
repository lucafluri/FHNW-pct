#include <iostream>
#include <unistd.h>
#include <string>

#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

int N, c1, c2;
int ht[101]; //height of towers with color i on top
string l[101][101]; // Descr of tower, to be directrly output - [color i on top][array of strings]

// Cube: Front Back Left Right Top Bottom
//(0-FR, 1-BA), (2-LE, 3-RI), (4-TO, 5-BO)

void addCube(int hti, int idx, int c, int f){
    string s = to_string(c) + " ";
    if(f==0) s += "front";
    else if(f==1) s += "back";
    else if(f==2) s += "left";
    else if(f==3) s += "right";
    else if(f==4) s += "top";
    else if(f==5) s += "bottom";
    l[hti][idx] = s;
}

int main() {
    prepare_ide("p10051");     // For IDE only
    
    while(true){
        cin >> N;
        if(N==0) break;

        // Input cubes
        for(int i = 1; i<=N; i++){
            if(i==1){ //First cube
                for(int j = 0; j < 6; j++){ 
                    cin >> c1;
                    if(!ht[c1]) ht[c1]++;
                    addCube(c1, 0, i, j);
                }
                continue;
            }

            for(int j = 0; j < 6; j+=2){ //0, 2, 4 
                cin >> c1; //color of face j
                cin >> c2; //opposite color of face j

                // c1 is bottom color => check if tower with c2 on top is bigger than current ht[c2]
                if(ht[c1] && ht[c1]+1 > ht[c2]){
                    ht[c2]++;
                    // l[c2] = l[c1];
                    for(int k = 0; k<100; k++){
                        l[c2][k] = l[c1][k];
                    }
                    addCube(c2, ht[c2]-1, i, j+1);
                }
                // c2 is bottom color => check if tower with c1 on top is bigger than current ht[c1]
                if(ht[c2] && ht[c2]+1 > ht[c1]){
                    ht[c1]++;
                    // l[c1] = l[c2];
                    for(int k = 0; k<100; k++){
                        l[c1][k] = l[c2][k];
                    }
                    addCube(c1, ht[c1]-1, i, j);
                }
                // Transfer string list in l[] if bigger


            }
        }

        for(int j = 0; j < 101; j++){
            for(int k = 0; k<101; k++){
                cout << l[j][k] << " ";
            }
            cout << endl;
        } 



    }

    execute_tests();     // For IDE only
}   
