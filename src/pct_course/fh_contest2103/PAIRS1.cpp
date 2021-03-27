#include <iostream>
#include <unistd.h>
#include <algorithm>
#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;


int main() {
    prepare_ide("PAIRS1");     // For IDE only
    
    int n, k;
    int c = 0;
    cin >> n >> k;

    int nums[n];

    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }

    sort(nums, nums + n);

    for(int i=0; i<n-1; i++){
        if(binary_search(nums, nums+n, nums[i]+k)) c++;
    }

    cout << c;

    execute_tests();     // For IDE only
}

