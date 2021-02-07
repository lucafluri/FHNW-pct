#include <iostream>
#include <unistd.h>
#include "../../my_libs/local_testing/string_in_out_testing.h" //IDE ONLY

using namespace std;



int main() {
    prepare_ide("p10189");     // For IDE only

    
    // Read in dimensions
    int n, m;
    int fieldCount = 1;
    while(cin >> n >> m && (n!=0 && m!=0)){
        char field[n][m];

        // Read in field
        for(int i = 0; i<n; i++){
            char line[m];
            cin >> line;
            for(int j = 0; j < m; j++){
                field[i][j] = line[j];
            }
        }

        if(fieldCount>1) printf("\n");
        printf("Field #%d:\n", fieldCount++);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(field[i][j] == '*'){
                    printf("*");
                }
                else{
                    int count = 0;
                    // Row above
                    if(i > 0){
                        // Top Left
                        if(j>0 && field[i-1][j-1] == '*') count++;
                        // Top
                        if(field[i-1][j] == '*') count++;
                        // Top Right
                        if(j<m-1 && field[i-1][j+1] == '*') count++;
                    }
                    // Mid Row
                    if(j>0 && field[i][j-1] == '*') count++;
                    if(j<m-1 && field[i][j+1] == '*') count++;
                    // Row below
                    if(i < n-1){
                        // Bottom Left
                        if(j>0 && field[i+1][j-1] == '*') count++;
                        // Bottom
                        if(field[i+1][j] == '*') count++;
                        // Bottom Right
                        if(j<m-1 && field[i+1][j+1] == '*') count++;
                    }
                    cout << count;
                }
            }
            // if(i != n-1)  printf("\n");
            printf("\n");
        }
    }



    


    execute_tests();     // For IDE only
}

