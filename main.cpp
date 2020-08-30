//CS530 Lab 3
//Francisco Melendez Hernandez, cssc 1905
//5/6/20
//Runs the parser
#include <iostream>
#include "Parser.h"
#include "ReferenceTable.h"

int main() {
    Parser *run = new Parser;
    run->inputFromFile();
    delete run;
    return 0;
}
