#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>


#include "../../my_libs/local_testing/string_in_out_testing.h" //IDE ONLY


using namespace std;

// Segments to turn on per number (idx)
// a, b, c, d, e, f, g, in clockwise direction starting from top
//Idx 0, 3, 6 are horizontal!
// 
//Top to bottom traversal:
//Idxs: 0, 5, 1, 6, 4, 2, 3
//0      0
//1  5       1
//2      6   
//3  4       2
//4      3
bool segments[][7] = {
    {1, 1, 1, 1, 1, 1, 0}, //0
    {0, 1, 1, 0, 0, 0, 0}, //1
    {1, 1, 0, 1, 1, 0, 1}, //2
    {1, 1, 1, 1, 0, 0, 1}, //3
    {0, 1, 1, 0, 0, 1, 1}, //4
    {1, 0, 1, 1, 0, 1, 1}, //5
    {1, 0, 1, 1, 1, 1, 1}, //6
    {1, 1, 1, 0, 0, 0, 0}, //7
    {1, 1, 1, 1, 1, 1, 1}, //8
    {1, 1, 1, 1, 0, 1, 1}, //9
};

void drawNumbers(vector<int> &digits, int s){
    int it[] = {0, 5, 1, 6, 4, 2, 3}; //Iteration direction Top-Bottom
    int len = *(&it + 1) - it;
    for(int j = 0; j < len; j++){ //Iterate over all 5 segment depths
        int segment = it[j];
         //Iterate over numbers
        if((segment == 0 || segment == 3 || segment== 6)){ //horizontal segments
            for(int i = 0; i<digits.size(); i++){
                cout << " ";
                if(segments[digits[i]][segment]){
                    for(int k = 0; k<s; k++) cout << "-";
                }else{
                    for(int k = 0; k<s; k++) cout << " ";
                }
                if(i != digits.size()-1) cout << "  ";
                else cout << " ";
            }
            cout << endl;
        }else if(segment == 5 || segment == 4){ // vertical segments
            for(int k = 0; k<s; k++){
                for(int i = 0; i<digits.size(); i++){
                    // Segment Left
                    if(segments[digits[i]][segment]){
                        cout << "|";
                    }else{
                        cout << " ";
                    }
                    for(int k = 0; k<s; k++) cout << " ";
                    // Segment Right
                    if(segments[digits[i]][it[j+1]]){
                        if(i != digits.size()-1) cout << "| ";
                        else cout << "|";
                    }else{
                        if(i != digits.size()-1) cout << "  ";
                        else cout << " ";
                    }
                }
                cout << endl;
            }
        }else continue;        
    }
}

int main() {
    prepare_ide("p706");     // For IDE only

    int s;
    char n[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> digits;

    while(cin >> s >> n){
        if(s==0 && n==0) break;
        // Get seperate digits, from back to front
        for(int i = 0; i < 8; i++) {
            if(n[i] != 0)
            digits.push_back(n[i] - '0');
        }

        drawNumbers(digits, s);
        cout << endl;
        // Reset char array
        fill(n, n + 8, 0);
        digits.clear();
    }

    execute_tests();     // For IDE only
}

