//CS530 Lab 3
//Francisco Melendez Hernandez, cssc 1905
//5/6/20

#ifndef CS530LAB3_PARSER_H
#define CS530LAB3_PARSER_H

#include "ReferenceTable.h"
#include <fstream>
#include <iostream>

class Parser{
public:
    void inputFromFile();
    void run();
    vector<string> validateVal(vector<string> item);
    vector<string> text;
};
#endif //CS530LAB3_PARSER_H
