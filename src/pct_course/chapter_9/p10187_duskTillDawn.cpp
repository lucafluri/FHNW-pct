#include <iostream>
#include <unistd.h>
#include <cstring>
#include <string>
#include <map>

#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

int n, c, res;
string start, dest;
map<string, int> cities; //map string city to int for adj list
int conns[100][100]; //adj list



int main() {
    prepare_ide("p10187");     // For IDE only
    
    cin >> n;
    while(n--){ //foreach testcase
        cin >> c;
        int cityCounter = 0;
        while(c--){ //for each connection
            string c1, c2;
            int dep, dur;
            cin >> c1 >> c2 >> dep >> dur;
            
            // Discard invalid cases
            if(dep > 6 && dep < 18) continue;
            else if(dur>12) continue;
            else if(dur==12 && dep != 18) continue;
            else if((dep+dur)%24 > 6 && (dep+dur)%24 < 18) continue;

            // Save connection
            cities[c1] = cityCounter++;
            cities[c2] = cityCounter++;

            cout << c1 << " " << c2 << endl;


        }

    }


    execute_tests();     // For IDE only
}   
