#include <iostream>
#include <unistd.h>
#include <cstring>
#include <math.h>

#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

int T, N, pegs[50];

bool isSquare(int x){
    int sr = sqrt(x);
    return sr * sr == x;
}

int main() {
    prepare_ide("p10276");     // For IDE only
    
    cin >> T;
    while(T--){
        memset(pegs, 0, sizeof(pegs));
        cin >> N; //# of allowed pegs to use

        // Simulate
        int i = 1;
        while(true){
            bool placed = false;
            for(int j = 0; j < N; j++){
                if(pegs[j] && isSquare(pegs[j]+i)){
                    pegs[j] = i++;
                    placed = true;
                    break;
                }
                if(!pegs[j]) {
                    pegs[j] = i++;
                    placed = true;
                    break;
                }
            }
            if(!placed) break; //no spot found
        }

        i--;
        cout << i << endl;

    }

    execute_tests();     // For IDE only
}   
