/*
 * Created by AndiSwiss on 28.09.20.
 */

/*
 * This file is intended to check my custom test Framework. 
 * 
 * Run with:
 *    cd src/pct_course/chapter_1/
 *    make p000_check_my_testing_framework && ./out/p000_check_my_testing_framework
 *   
 *   
 * It should produce the following (colored) output:
 *
 *    Executing tests:
 *    ----------------
 *    Error: Line 3:  Expected: 201 and 270   Your output: 201 and 210
 *    You failed to produce expected line 5:  3455 and 3423485933
 *    You have 2 wrong lines!
 */


#include <iostream>
#include <unistd.h>
#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;


int main() {
    prepare_ide("p000");     // For IDE only


    long long i, j;
    while (cin >> i >> j) {
        cout << i << " and " << j << endl;
    }


    execute_tests();     // For IDE only
}

