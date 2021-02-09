#include <iostream>
#include <unistd.h>

#include <string> 



#include "../../my_libs/local_testing/string_in_out_testing.h" //IDE ONLY

using namespace std;

// Create array
// NxM (matrix) (n rows, m columns)
char img[252][252];
int m, n;

void swap(int &x, int &y){
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}

void clearImage(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            img[i][j] = 'O';
        }
    }
}

void colorField(int x, int y, char color){
    img[y][x] = color;
}

void vLine(int x, int y1, int y2, char color){
    int top = y1;
    int len = abs(y2-y1) + 1;
    if(y1 > y2) top = y2;

    for(int i = 0; i<len; i++){
        img[top+i][x] = color;
    }
}

void hLine(int x1, int x2, int y, char color){
    int left = x1;
    int len = abs(x2-x1) + 1;
    if(x1 > x2) left = x2;

    for(int i = 0; i<len; i++){
        img[y][left+i] = color;
    }
}

void rect(int x1, int y1, int x2, int y2, char color){
    int left = x1;
    int top = y1;
    if(x1 > x2){
        left = x2;
        swap(x1, x2);
    }
    if(y1 > y2){
        top = y2;
        swap(y1, y2);
    }

    int width = x2 - x1;
    int height = y2 - y1;

    for(int x = left; x<=left+width; x++){
        for(int y = top; y<=top+height; y++){
            colorField(x, y, color);
        }
    }
}

void fill(int x, int y, char co, char cn){
    
    if(img[y][x] == co){
        colorField(x, y, cn);
        if(x > 1) {
            fill(x-1, y, co, cn);
        } 
        if(y > 1) {
            fill(x, y-1, co, cn);
        }
        if(x < m) {
            fill(x+1, y, co, cn);
        }
        if(y < n) {
            fill(x, y+1, co, cn); 
        }
    }

}

void save(string name){
    cout << name << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << img[i][j];
        }
        cout << endl;
    }
}

int main() {
    prepare_ide("p10267");     // For IDE only

    char in;

    clearImage();
    string x, y, x2, y2;
    char c;
    string name;
    while(cin >> in && in != 'X'){
        switch(in){
            case 'I':
                cin >> m >> n;
                clearImage();
                break;
            case 'C': //clear
                clearImage();
                break;
            case 'L': //color
                cin >> x >> y >> c;
                colorField(stoi(x), stoi(y), c);
                break;
            case 'V': //vline
                cin >> x >> y >>y2 >> c;
                vLine(stoi(x), stoi(y), stoi(y2), c);
                break;
            case 'H': //hline
                cin >> x >> x2 >> y >> c;
                hLine(stoi(x), stoi(x2), stoi(y), c);
                break;
            case 'K': //rect
                cin >> x >> x2 >> y >> y2 >> c;
                rect(stoi(x), stoi(x2), stoi(y), stoi(y2), c);
                break;
            case 'F': //fill
                cin >> x >> y >> c;
                if(img[stoi(y)][stoi(x)]!=c) fill(stoi(x), stoi(y), img[stoi(y)][stoi(x)], c);
                break;
            case 'S': //save/output
                cin >> name;
                save(name);
                break;
            
            default:
            // Read and ignore rest of line
                string str;
                getline(cin, str);
        }
    }


    


    execute_tests();     // For IDE only
}

