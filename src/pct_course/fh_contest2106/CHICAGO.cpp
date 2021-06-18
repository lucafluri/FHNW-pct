#include <iostream>
#include <unistd.h>
#include <algorithm>
#include <cstring>
#include <climits>
#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

int n, m, i, j, k;
double s[100][100];

int main() {
    prepare_ide("CHICAGO");     // For IDE only

    while(true){
        cin >> n;
        if(n==0) break;
        cin >> m;

        // Clear
        for(i = 0; i<100; i++){
            memset(s[i], 0, sizeof(s[i])); 
        }
        
        while(m--){
            cin >> i >> j >> k;
            s[i][j] = s[j][i] = (k / 100.0);
        }

        // Floyd Warshall
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    s[i][j] = s[j][i] = max(s[i][j],s[i][k]*s[k][j]);
                }
            }
        }
        printf("%.6f percent\n", s[1][n]*100);
    }
    execute_tests();     // For IDE only
}

