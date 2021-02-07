//
// Created by AndiSwiss on 10.10.20.
//

#ifndef FHNW_PCT_PROGRAMMING_CONTEST_TRAINING_STRING_IN_OUT_TESTING_H
#define FHNW_PCT_PROGRAMMING_CONTEST_TRAINING_STRING_IN_OUT_TESTING_H

#endif //FHNW_PCT_PROGRAMMING_CONTEST_TRAINING_STRING_IN_OUT_TESTING_H

#include <iostream>
using namespace std;

// For IDE only:
// Enum for colored terminal output.
// See https://en.cppreference.com/w/cpp/language/enum
enum Color {
    red = 31, green = 32, yellow = 33, blue = 34, magenta = 35, cyan = 36
};

void prepare_ide(const string &problem_no, int file_no = -1);

void execute_tests();

void write_colored_text(const string &message, Color color = red);