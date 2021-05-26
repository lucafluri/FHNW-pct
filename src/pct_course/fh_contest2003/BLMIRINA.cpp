#include <iostream>
#include <unistd.h>
#include <cmath>
#include "../../my_libs/local_testing/string_in_out_testing.h"

using namespace std;

int T, x, y, r;
double a, b, c, d1, d2;
double A[2];
double B[2];


double dist(double x, double y){
    return sqrt(x*x + y*y);
}


int main() {
    prepare_ide("BLMIRINA");     // For IDE only

    cin >> T;
    while(T--){
        cin >> x >> y >> r;

        a = 1 + ((x*x)/(y*y));
        b = -((2*(r*r)*x)/(y*y));
        c = ((r*r*r*r)/(y*y)) - (r*r);

        A[0] = (-b + sqrt((b*b)-(4*a*c))) / (2*a);
        A[1] = (-b - sqrt((b*b)-(4*a*c))) / (2*a);

        B[0] = ((r*r)-(A[0]*x))/y;
        B[1] = ((r*r)-(A[1]*x))/y;


        d1 = dist(A[0], B[0]);
        d2 = dist(A[1], B[1]);

        if(d1 > d2){
            cout << A[0] << " " << B[0] << endl;
        }
        else{
            cout << A[1] << " " << B[1] << endl;
        }
    }
    execute_tests();     // For IDE only
}

