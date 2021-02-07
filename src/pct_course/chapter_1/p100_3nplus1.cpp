#include <iostream>
#include <unistd.h>
#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

// Init min iteration length
int n = 1;

// Recursively find iteration length for 3n+1
int length(int x){
    if(x!=1){
        if(x%2==0) length(x/2);
        else length(3*x + 1);
        n++;
    }
    return n;
}

void swap(int &x, int &y)
{
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}


int main() {
    prepare_ide("p100");     // For IDE only


    long long i, j;

    while (cin >> i >> j) {
        long a = i;
        long b = j;
        // Swap ints to always have them sorted.
        if(a > b) swap(a, b);
        int max = 0;
        for(; a<=b; a++){
            int count = length(a);
            if(count>max) max = count;
            // reset min interation length
            n=1;
        }
        cout << i << " " << j << " " << max << endl;
    }

    


    execute_tests();     // For IDE only
}

