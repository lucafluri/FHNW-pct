#include <iostream>
#include <unistd.h>

#include <string> 



#include "../../my_libs/local_testing/string_in_out_testing.h" //IDE ONLY

using namespace std;

// Create array
// NxM (matrix) (n rows, m columns)
char img[250][250];
int m, n;

void clearImage(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            img[i][j] = 'O';
        }
    }
}

void color(int x, int y, char color){
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
    int width = x2 - x1;
    int height = y2 - y1;
    for(int i = 0; i<=width; i++){
        for(int j = 0; j<=height; j++){
            img[j][i] = color;
        }
    }
}

void fill(int x, int y, char co, char cn){
    if(img[y][x] == co){
        img[y][x] = cn;
        if(y > 0) fill(x, y-1, co, cn);
        if(x < m) fill(x+1, y, co, cn);
        if(y < n) fill(x, y+1, co, cn);
        if(x > 0) fill(x-1, y, co, cn);
    }

}

void save(string name){
    cout << name << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << img[i][j];
        }
        cout << endl;
    }
}

int main() {
    prepare_ide("p10267");     // For IDE only


    // COMMMANDS
    // I M N            Create a new M ×N image with all pixels initially colored white (O).
    // C                Clear the table by setting all pixels white (O). The size remains unchanged.
    // L X Y C          Colors the pixel (X, Y ) in color (C).
    // V X Y1 Y2 C      Draw a vertical segment of color (C) in column X, between the rows Y 1 and Y 2 inclusive.
    // H X1 X2 Y C      Draw a horizontal segment of color (C) in the row Y , between the columns X1 and X2 inclusive.
    // K X1 Y1 X2 Y2 C  Draw a filled rectangle of color C, where (X1, Y 1) is the upper-left and (X2, Y 2) the lower right corner.
    // F X Y C          Fill the region R with the color C, where R is defined as follows. Pixel (X, Y ) belongs to R. Any other pixel which is the same color as pixel (X, Y ) and shares a common side with any pixel in R also belongs to this region.
    // S Name           Write the file name in MSDOS 8.3 format followed by the contents of the current image.
    // X                Terminate the session.


    char in;
    // Wait for Image creation
    while(cin >> in && in != 'X'){
        if(in == 'I'){
            cin >> m >> n;
            break;
        }
    }

    
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << img[i][j] << " ";
    //     }
    //     cout <<endl;
    // }
    clearImage();
    char x, y, x2, y2, c;
    string name;
    while(cin >> in && in != 'X'){
        switch(in){
            case 'C': //clear
                clearImage();
                break;
            case 'L': //color
                cin >> x >> y >> c;
                color(x - '1', y - '1', c);
                break;
            case 'V': //vline
                cin >> x >> y >>y2 >> c;
                vLine(x - '1', y - '1', y2 - '1', c);
                break;
            case 'H': //hline
                cin >> x >> x2 >> y >> c;
                hLine(x - '1', x2 - '1', y - '1', c);
                break;
            case 'K': //rect
                cin >> x >> x2 >> y >> y2 >> c;
                rect(x - '1', x2 - '1', y - '1', y2 - '1', c);
                break;
            case 'F': //fill
                cin >> x >> y >> c;
                fill(x - '1', y - '1', img[y - '1'][x - '1'], c);
                break;
            case 'S': //save/output
                cin >> name;
                save(name);
                break;
            
            default:
            // Read and ignore rest of line
                // cout << "IGNORING";
                string str;
                getline(cin, str);
        }
    }


    


    execute_tests();     // For IDE only
}

