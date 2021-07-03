#include <iostream>
#include <unistd.h>
#include <map>
#include <string>
#include <algorithm>
#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

// https://www.cplusplus.com/reference/string/string/
// Edit step: add, delete, change

string a, b;
int maxLength = 0, length, i;
char c;

// Maps dict word to edit dist from another dict word
map<string, int> lengths; 

int main() {
    prepare_ide("p10029");     // For IDE only
    // Ignore first edit distance and just enter word into map
    cin >> a;
    lengths[a] = 1;
    while(cin >> a) lengths[a] = 1;
    
    for(int i = 0; i < lengths.size(); i++){
        a
        length = 1;
        int size = a.size();
        // Add char (at i => go to <= a.size() to add last after)
        if(size < 16){
            for(i = 0; i<=size; i++){
                for(c = 'a'; c <= 'z'; c++){
                    b = string(a);
                    b.insert(i, 1, c);

                    if(lengths.count(b)){ //word already exists in map
                        length = max(length, lengths[b]+1);
                    }
                }
            }         
        }

        // Delete char
        if(size > 1){
            for(i = 0; i<size; i++){
                b = string(a);
                b.erase(i, 1);

                if(lengths.count(b)){ //word already exists in map
                    length = max(length, lengths[b]+1);
                }
            }  
        }
        

        // Edit char
        for(i = 0; i<size; i++){
            for(c = 'a'; c <= 'z'; c++){
                if(c == b[i]) continue;
                b = string(a);
                b[i] = c;

                if(lengths.count(b)){ //word already exists in map
                    length = max(length, lengths[b]+1);
                }
            }
        }  

        lengths[a] = length;
        maxLength = max(length, maxLength);
    }
    
    cout << maxLength << endl;
    

    execute_tests();     // For IDE only
}   
