#include <iostream>
#include <unistd.h>

#include <cmath>
#include <algorithm>
#include <vector>

#include "../../my_libs/local_testing/string_in_out_testing.h" //IDE ONLY


using namespace std;

float roundTo2(float var)
{ 
    // float value = (int)(var * 100 + .5); 
    // return (float)value / 100; 
    // we use array of chars to store number 
    // as a string. 
    char str[40];  

    // Print in string the value of var  
    // with two decimal point 
    sprintf(str, "%.2f", var); 

    // scan string value in var  
    sscanf(str, "%f", &var);  
    
    return var;  
} 

bool compare_float(float x, float y, float epsilon = 0.01f){
    if(fabs(x - y) < epsilon) return true; //they are same
    return false; //they are not same
}

int main() {
    prepare_ide("p10137");     // For IDE only


    int studentCount;

    // For each Trip
    while(cin >> studentCount && studentCount != 0){
        float expenses[studentCount];
        float sum = 0;
        float average;

        float owers = 0;
        float benef = 0;

        for(int i = 0; i<studentCount; i++){
            cin >> expenses[i];
            sum += expenses[i];
        }

        average = roundTo2(sum/studentCount);
        if(compare_float(average, 0.01)) average = 0.02;


        for(int i = 0; i<studentCount; i++){
            float offset = (average - expenses[i]);
            if(offset > 0)  owers += offset;
            else benef += offset;

        }

        float minAmount = owers <= -benef ? owers : -benef;

        printf("$%.2f\n", minAmount);

        // Reset for next iteration
        sum = 0;

    }

    


    execute_tests();     // For IDE only
}

