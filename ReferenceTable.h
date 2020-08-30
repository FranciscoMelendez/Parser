//CS530 Lab 3
//Francisco Melendez Hernandez, cssc 1905
//5/6/20

#ifndef CS530LAB3_REFERENCETABLE_H
#define CS530LAB3_REFERENCETABLE_H

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>

using  namespace std;

class ReferenceTable{
public:
    vector<string> validateAssignment(vector<string> item);
    vector<string> validateExpression(vector<string> item);
    bool validateID (string item);
    bool validateChar (char character);
    bool validateNumber (char number);
    bool validateOp (char op);
};

#endif //CS530LAB3_REFERENCETABLE_H
