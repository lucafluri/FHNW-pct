#include <iostream>
#include <unistd.h>
#include <map>
#include <string>
#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

int main() {
    prepare_ide("p27");     // For IDE only
    
    string buffer;
    unsigned int numTests;
    cin >> numTests;
    getline(cin, buffer);
    int n;
    map<string, int> c;

    while(numTests--){
        cin >> n;

        c.clear();
        getline(cin, buffer);

        for(int i = 0; i<n; i++){
            getline(cin, buffer);
            c[buffer]++;
        }

        map<string, int>::iterator it = c.begin();
		while(it!=c.end()) {
			cout<<it->first<<it->second<<endl;
            it++;
		}
        if(numTests != 0) cout << endl;

    }

    execute_tests();     // For IDE only
}

