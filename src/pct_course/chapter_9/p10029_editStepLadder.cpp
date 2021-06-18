#include <iostream>
#include <unistd.h>
#include <map>
#include <string>
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
    
    while(cin >> a){
        length = 1;
        // Add char (before i => go to <= a.size() to add last after)
        if(a.size() < 16){
            for(i = 0; i<=a.size(); i++){
                for(c = 'a'; c <= 'z'; c++){
                    b = string(a);
                    b.insert(i, 1, c);
                    if(lengths.count(b)){ //word already exists in map
                        length = lengths[b]+1 > length ? lengths[b]+1 : length;
                    }
                }
            }         
        }

        // Delete char
        for(i = 0; i<a.size(); i++){
            b = string(a);
            b.erase(i);
            if(lengths.count(b)){ //word already exists in map
                length = lengths[b]+1 > length ? lengths[b]+1 : length;
            }
        }  

        // Edit char
        for(i = 0; i<a.size(); i++){
            for(c = 'a'; c <= 'z'; c++){
                if(c == b[i]) continue;
                b = string(a);
                b[i] = c;
                if(lengths.count(b)){ //word already exists in map
                    length = lengths[b]+1 > length ? lengths[b]+1 : length;
                }
            }
        }  

        lengths[a] = length;
        maxLength = length > maxLength ? length : maxLength;
    }
    
    cout << maxLength << endl;
    

    execute_tests();     // For IDE only
}   
