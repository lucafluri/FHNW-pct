#include <iostream>
#include <unistd.h>
#include <list>
#include <cstring>
#include <math.h>
#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

int N, s, t, F, tmp, d, v, i;
int c[10000];
int f[10000];

int bfs() {
    list<int> queue;

    c[s] = 1;
    queue.push_back(s);

    while(!queue.empty()){
        v = queue.front();
        queue.pop_front();

        if(v == t) return c[v] -1;

        // Find all nums differing by 1 digit
        for(i = 0; i < 4 ; i++){
            d =(int)(v / pow(10, i)) % 10; //digit
            if(d < 9) tmp = v + pow(10, i);
            if(d == 9) tmp = v + pow(10, i) - pow(10, i+1);

            if(!c[tmp] && tmp < 10000 && !f[tmp]){
                c[tmp] = c[v] + 1;
                queue.push_back(tmp);
            } 
            
            if(d > 0) tmp = v - pow(10, i);
            if(d == 0) tmp = v + 9*pow(10, i);

            if(!c[tmp] && tmp >= 0 && !f[tmp]){
                c[tmp] = c[v] + 1;
                queue.push_back(tmp);
            }
            
            
        }

    }
    return -1;
}

int getNum(){
    tmp = 0;
    d = 0;
    for(i = 3; i>=0; i--){
        cin >> tmp;
        d += tmp * pow(10, i);
    }
    return d;
}


int main() {
    prepare_ide("p10067");     // For IDE only

    cin >> N;

    while(N--){
        memset(c, 0, sizeof(c));
        memset(f, 0, sizeof(f));

        s = getNum();
        t = getNum();

        cin >> F;
        while(F--) f[getNum()] = 1;

        if(s == t){
            cout << 0 << endl;
            continue;
        }
        cout << bfs() << endl;
    }

    execute_tests();     // For IDE only
}

