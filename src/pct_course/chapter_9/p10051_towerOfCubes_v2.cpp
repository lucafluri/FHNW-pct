#include <iostream>
#include <unistd.h>
#include <string.h>
#include <cmath>
#include <cstring>

#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;
char f[6][10] = { "front", "back", "left", "right", "top", "bottom"};


int ht[3001], p[3001], cu[6], top[3001], bot[3001], c[3001], df[3001];
int N, idx;

void printTower( int i){
    if ( i == -1)
        return ;
    printTower( p[i] );
    printf("%d %s\n", c[i], f[df[i]]);
}

int main() {
    prepare_ide("p10051");     // For IDE only

    int t = 1, first = 1;
    while ( cin >> N && N)
    {
        if ( !first)
            cout << endl;
        else
            first = 0;

        idx = 0;

        int i, j;
        for ( i = 0; i < N; i++)
        {
            for ( j = 0; j < 6; j++)
                // scanf("%d", &cu[j]);
                cin >> cu[j];
            for ( j = 0; j < 6; j++)
            {
                df[idx] = j;
                c[idx] = i + 1;
                top[idx] = cu[j];
                if ( j % 2)
                    bot[idx] = cu[j - 1];
                else
                    bot[idx] = cu[j + 1];
                idx++;
            }
        }
        // Clear
        memset( ht, 0, sizeof( ht));
        memset( p, -1, sizeof( p));
        for ( i = 0; i < idx; i++)
            for ( j = i + 1; j < idx; j++)
                if ( c[j] > c[i] && bot[i] == top[j] && ht[j] < ht[i] + 1)
                {
                    ht[j] = ht[i] + 1;   p[j] = i;
                }
        int max = 0, k = 0;
        for ( i = 1; i < idx; i++)
            if ( ht[i] > max)
            {
                max = ht[i];
                k = i;
            }

        // Output
        printf("Case #%d\n%d\n", t++, max + 1);
        printTower(k );
    }

    execute_tests();     // For IDE only
}   
