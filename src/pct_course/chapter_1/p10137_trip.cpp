#include <iostream>
#include <unistd.h>


#include "../../my_libs/local_testing/string_in_out_testing.h" //IDE ONLY


using namespace std;

int main() {
    prepare_ide("p10137");     // For IDE only


    int studentCount;

    // For each Trip
    while(cin >> studentCount && studentCount != 0){
        double expenses[studentCount];
        double sum = 0, owers = 0, benef = 0;
        double average;

        for(int i = 0; i<studentCount; i++){
            double expense;
            cin >> expense;
            expenses[i] = expense * 100;
            sum += expenses[i];
        }

        average = sum/studentCount;

        for(int i = 0; i<studentCount; i++){
            int expense = expenses[i] - average;
            if(expense > 0){
                owers += expense;
            }else{
                benef += -expense;
            }
        }

        int minAmount = owers > benef ? owers : benef;
        printf("$%.2f\n", minAmount/100.0);

        // Reset for next iteration
        sum = 0;

    }

    


    execute_tests();     // For IDE only
}

