#include <iostream>
#include <unistd.h>


#include "../../my_libs/local_testing/string_in_out_testing.h" //IDE ONLY


using namespace std;
const int SIZE = 8;

char board[SIZE][SIZE];

// Pos for white and black kings
int kx;
int ky;
int Kx;
int Ky;

bool boardEmpty(){
    for(int i = 0; i<SIZE; i++){
        for(int j = 0; j<SIZE; j++){
            if(board[i][j] != '.') return false;
        }
    }
    return true;
}

// Check all straights for rook and queen
bool straight(bool white){
    int x = white ? Kx : kx;
    int y = white ? Ky : ky;
    char R = white ? 'r' : 'R';
    char Q = white ? 'q' : 'Q';
    char c;
    // Go in all 4 directions and 
    // up
    for(int i = y-1; i >= 0; i--){ 
        c = board[i][x];
        if(c == R || c == Q) return true;
        else if(c != '.') break;
    }
    // down
    for(int i = y+1; i < SIZE; i++){ 
        c = board[i][x];
        if(c == R || c == Q) return true;
        else if(c != '.') break;
    }
    // left
    for(int i = x-1; i >= 0; i--){ 
        c = board[y][i];
        if(c == R || c == Q) return true;
        else if(c != '.') break;
    }
    // right
    for(int i = x+1; i < SIZE; i++){ 
        c = board[y][i];
        if(c == R || c == Q) return true;
        else if(c != '.') break;
    }
    return false;
}

// Check all straights for rook and queen
bool diagonal(bool white){
    int x = white ? Kx : kx;
    int y = white ? Ky : ky;
    char B = white ? 'b' : 'B';
    char Q = white ? 'q' : 'Q';
    char P = white ? 'p' : 'P';
    char c;
    int ix, iy;
    // Go in all 4 directions and 
    // check whether first piece is threatening rook
    // UpLeft
    for(ix = x-1, iy = y-1; ix >= 0 && iy >= 0; ix--, iy--){
        c = board[iy][ix];
        if(c == B || c == Q) return true;
        else if(c != '.') break;
    }
    // UpRight
    for(ix = x+1, iy = y-1; ix < SIZE && iy >= 0; ix++, iy--){
        c = board[iy][ix];
        if(c == B || c == Q) return true;
        else if(c != '.') break;
    }
    // DownRight
    for(ix = x+1, iy = y+1; ix < SIZE && iy < SIZE; ix++, iy++){
        c = board[iy][ix];
        if(c == B || c == Q) return true;
        else if(c != '.') break;
    }
    // DownLeft
    for(ix = x-1, iy = y+1; ix >= 0 && iy < SIZE; ix--, iy++){
        c = board[iy][ix];
        if(c == B || c == Q) return true;
        else if(c != '.') break;
    }

    // Check pawn
    if(white){
        if(y > 0 && x < SIZE - 1 && board[y-1][x+1] == P) return true;
        else if(y > 0 && x > 0 && board[y-1][x-1] == P) return true;
    }else{
        if(y < SIZE && x < SIZE - 1 && board[y+1][x+1] == P) return true;
        else if(y < SIZE && x > 0 && board[y+1][x-1] == P) return true;
    }
    return false;
}

bool knight(bool white){
    int x = white ? Kx : kx;
    int y = white ? Ky : ky;
    char N = white ? 'n' : 'N';
    char c;

    int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

    for(int i = 0; i<8; i++){
        if(y+dy[i] >= 0 && y+dy[i] < SIZE && x+dx[i] < SIZE && x+dx[i] >=0){
            c = board[y+dy[i]][x+dx[i]]; 
            if(c == N) return true;
        } 
    }
    return false;
}


int main() {
    prepare_ide("p10196");     // For IDE only

    // Save board
    // Find positions of each king
    // Check all possible check squares for each king and 
    // look whether relevant piece from opponent is present on said square.
    // If yes, king in check
    char tmp[SIZE];
    char c;
    int game = 1;
    while(true){
        // Read in Board
        for(int i = 0; i<SIZE;i++){
            for(int j = 0; j<SIZE; j++){
                cin >> c;
                board[i][j] = c;
                
                // Save b/w king positions
                if(c == 'k'){
                    kx = j;
                    ky = i;
                }else if(c == 'K'){
                    Kx = j;
                    Ky = i;
                }
            }
        }
        if(boardEmpty()) break; //terminate loop
        cin.getline(tmp, 8); //throw away spacer line

        // Check for checks....
        if(straight(true) || diagonal(true) || knight(true)) printf("Game #%d: white king is in check.", game);
        else if(straight(false) || diagonal(false) || knight(false)) printf("Game #%d: black king is in check.", game);
        else printf("Game #%d: no king is in check.", game);
        cout << endl;
        game++;
    }
    execute_tests();     // For IDE only
}

