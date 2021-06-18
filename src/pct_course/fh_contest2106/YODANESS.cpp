#include <iostream>
#include <unistd.h>
#include <string>
#include <map>
#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

int t, n;


int main() {
    prepare_ide("YODANESS");     // For IDE only

    cin >> t;
    while(t--){
        cin >> n;
        string org[n], yoda[n];
        map<string, int> idxs; //array indexes yoda

        // Read in words to string arrays
        for(int i = 0; i < n; i++){
            cin >> yoda[i];
            idxs[yoda[i]] = i;
        }
        for(int i = 0; i < n; i++){
            cin >> org[i];
        }

        // Find swap count
        // Iterate over yoda -> find right pos in org and swap => count swaps
        int count = 0;

        for(int i = 0; i<n; i++){ //iterate over all words
            if(yoda[i] != org[i]){
                // Find correct word idx in yoda
                int idx = 0;
                for(int j = i; j<n; j++){
                    if(yoda[j] == org[i]) idx = j;
                }
                // swap items at idx and i in yoda
                string tmp;
                tmp = yoda[i];
                yoda[i] = yoda[idx];
                yoda[idx] = tmp;
                
                count++;
            }
        }
        cout << count << endl;

    }


    execute_tests();     // For IDE only
}

