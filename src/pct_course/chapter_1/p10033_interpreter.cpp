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

void execute(int idx){
    string in = ram[idx];

    int tmp = stoi(in);
    int a = tmp / 100;
    int b = (tmp / 10 ) % 10;
    int c = tmp % 10;

    cout << in << endl;
    // int a = in[0] - '0', b = in[1] - '0', c = in[2] - '0';
    // int a = 0, b = 0, c=0;
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
                char tmp[3];
                tmp[0] = reg[b] / 100;
                tmp[1] = (reg[b] / 10) % 10;
                tmp[2] = reg[b] % 10;
                ram[reg[c]] = tmp;
                break;
            case 0:
                if(c!=0){
                    nxt = reg[b];
                    nxt--;
                }
                break;
        }
        count++;
        execute(nxt++);

    }
    count++;
}

int main() {
    prepare_ide("p10033");     // For IDE only

    //read in case number
    cin >> cases;
    string tmp;
    getline(cin, tmp); //read rest of line
    getline(cin, tmp); //throw away empty line
    
    int current = 0;
    while(current < cases){
        //init RAM
        fill(ram, ram+1000, "000");
        fill(reg, reg+10, 0);

        //read in ram until empty line
        int i = 0;
        tmp = "000";
        while(!tmp.empty() && !cin.eof()){
            getline(cin, tmp);
            // cout << tmp << endl;
            ram[i++] = tmp;
        }

        // Execute instructions and keep count
        execute(0);
        // for(int i = 0; i<1000; i++){
        //     cout << ram[i] << endl;
        // }

        if( current < cases -1) cout << count << endl << endl;
        else cout << count << endl;
        current++;
    }
    



    

    execute_tests();     // For IDE only
}

