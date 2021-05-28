#include <iostream>
#include <unistd.h>
#include <algorithm>
#include <cstring>
#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

int N, h, w, i, j, best;
int m[100][100];


int main() {
    prepare_ide("BYTESM2");     // For IDE only

    cin >> N;
    while(N--){
        for(i = 0; i<100; i++){
            memset(m[i], 0, sizeof(m[i]));
        }

        cin >> h >> w;
        for(i=0;i<h;i++){
            for(j=0; j<w; j++){
                cin >> m[i][j];
            }
        }

        for(i=1;i<h;i++){
            for(j=0; j<w; j++){
                if(j==0){
                    m[i][j] += max(m[i-1][j], m[i-1][j+1]);
                }else if(j==w-1){
                    m[i][j] += max(m[i-1][j], m[i-1][j-1]);
                }else{
                    m[i][j] += max(m[i-1][j+1], max(m[i-1][j], m[i-1][j-1]));
                }

            }
        }

        best = *max_element(m[h-1], m[h-1]+w);

        cout << best << endl;
    }


    execute_tests();     // For IDE only
}

