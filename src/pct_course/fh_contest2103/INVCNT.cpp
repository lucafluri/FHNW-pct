#include <iostream>
#include <unistd.h>
#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

int count;

void merge(int *a, int beg, int m, int end){
    int b[end-beg];
	int i = 0, j = beg, k = m;
	while (j < m && k < end)
		if (a[j] <= a[k]){
			b[i++] = a[j++];

            
        }
		else{
			b[i++] = a[k++];
            count += m- i;

        }
	
	while (j < m)
		b[i++] = a[j++];

	while(i>0) {
		--i;
		a[beg + i] = b[i];
	}
}

void sort(int *a, int beg, int end){
    if (end - beg > 1) {
		uint64_t m = (beg + end) >> 1;
		sort(a, beg, m);
		sort(a, m, end);
		merge(a, beg, m, end);
	}
}

int main() {
    prepare_ide("INVCNT");     // For IDE only
    
    int t, n;
    cin >> t;

    while(t--){
        cin >> n;
        count = 0;
        
        int a[n];
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }

        sort(a, 0, n);

        cout << count << endl;
    }

    execute_tests();     // For IDE only
}

