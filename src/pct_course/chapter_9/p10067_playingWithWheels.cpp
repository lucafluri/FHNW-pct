#include <iostream>
#include <unistd.h>
#include <queue>
#include <cstring>
#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

int N, s, t, F, tmp, d, v, i;
int c[10000];

int p(int b){
    if(b==0) return 1;
    else if(b==1) return 10;
    else if(b==2) return 100;
    else if(b==3) return 1000;
    else return 10000;
}

int bfs() {
    queue<int> queue;

    c[s] = 1;
    queue.push(s);

    while(!queue.empty()){
        v = queue.front();
        queue.pop();

        if(v == t) return c[v] -1;

        // Find all nums differing by 1 digit
        for(i = 0; i < 4 ; i++){
            d =(int)(v / p(i)) % 10; //digit

            if(d < 9) tmp = v + p(i);
            if(d == 9) tmp = v + p(i) - p(i+1);

            if(c[tmp] == 0){
                c[tmp] = c[v] + 1;
                queue.push(tmp);
            } 
            
            if(d > 0) tmp = v - p(i);
            if(d == 0) tmp = v + 9*p(i);

            if(c[tmp] == 0){
                c[tmp] = c[v] + 1;
                queue.push(tmp);
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
        d += tmp * p(i);
    }
    return d;
}


int main() {
    prepare_ide("p10067");     // For IDE only

    cin >> N;

    while(N--){
        memset(c, 0, sizeof(c));

        s = getNum();
        t = getNum();

        cin >> F;
        while(F--) c[getNum()] = -1;

        if(s == t){
            cout << 0 << endl;
            continue;
        }
        cout << bfs() << endl;
    }

    execute_tests();     // For IDE only
}

