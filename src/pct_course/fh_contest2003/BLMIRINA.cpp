#include <iostream>
#include <unistd.h>
#include <cmath>
#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

int T, x, y, r, tx, ty;

struct vect{
    double x;
    double y;
};

double dist(double x, double y){
    return sqrt(x*x + y*y);
}

int main() {
    prepare_ide("BLMIRINA");     // For IDE only

    cin >> T;
    while(T--){
        cin >> x >> y >> r;

        double d = dist(x, y);


        float m1 = 

        vect v1;
        v1.x = x + (-x / d) * r;
        v1.y = y + (y / d) * r;

        vect v2;
        v2.x = x + (x / d) * r;
        v2.y = y + (-y / d) * r;

        double d1 = dist(v1.x, v1.y);
        double d2 = dist(v2.x, v2.y);

        if(d1 > d2){
            cout << v1.x << " " << v1.y << endl;
        }
        else{
            cout << v2.x << " " << v2.y << endl;
        }



        // float alpha = asin(y/d);

    }
    

    execute_tests();     // For IDE only
}

