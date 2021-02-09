#include <iostream>
#include <unistd.h>
#include <string>


#include "../../my_libs/local_testing/string_in_out_testing.h" //IDE ONLY


using namespace std;

int cases;
string ram[1000];
int reg[10];

int nxt = 1;
int count = 0;

string int2string(int i){
    string c = "000";
    c[0] = '0' + (i/100);
    c[1] = '0' + ((i/10) % 10);
    c[2] = '0' + (i % 10);
    return c;
}

void execute(int idx){
    string in = ram[idx];

    int tmp = stoi(in);
    int a = tmp / 100;
    int b = (tmp / 10 ) % 10;
    int c = tmp % 10;

    if(in != "100"){
        switch(a){
            case 2:
                reg[b] = c;
                break;
            case 3:
                reg[b] = (reg[b] + c) % 1000;
                break;
            case 4:
                reg[b] = (reg[b] * c) % 1000;
                break;
            case 5:
                reg[b] = reg[c];
                break;
            case 6:
                reg[b] = (reg[b] + reg[c]) % 1000;
                break;
            case 7:
                reg[b] = (reg[b] * reg[c]) % 1000;
                break;
            case 8:
                reg[b] = 0;
                reg[b] += (ram[reg[c]][0] - '0') * 100;
                reg[b] += (ram[reg[c]][1] - '0') * 10;
                reg[b] += (ram[reg[c]][2] - '0');
                break;
            case 9:
                ram[reg[c]] = int2string(reg[b]);
                break;
            case 0:
                if(reg[c]!=0){
                    nxt = reg[b];
                }
                break;
        }
        count++;
        execute(nxt++);

    }
}

int main() {
    prepare_ide("p10033");     // For IDE only

    //read in case number
    cin >> cases;
    string tmp;
    getline(cin, tmp); //read rest of line
    getline(cin, tmp); //throw away empty line
    
    int current = 1;
    while(current <= cases){
        nxt = 1;
        count = 0;

        //init RAM
        fill(ram, ram+1000, "000");
        fill(reg, reg+10, 0);

        //read in ram until empty line
        int i = 0;
        getline(cin, tmp);
        while(!tmp.empty() && !cin.eof()){
            ram[i++] = tmp;
            getline(cin, tmp);
        }

        // Execute instructions and keep count
        execute(0);

        count += 1;

        if( current < cases) cout << count << endl << endl;
        else cout << count << endl;
        current++;
    }
    



    

    execute_tests();     // For IDE only
}

