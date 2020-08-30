//CS530 Lab 3
//Francisco Melendez Hernandez, cssc 1905
//5/6/20
//Parses the "ex.txt" file and outputs result

#include "Parser.h"

//read from the file
void Parser::inputFromFile() {
    ifstream input;
    string line;
    input.open("ex.txt");
    //if ex.txt is not open, exit the program
    if(!(input.is_open())){
        cout << "\"ex.txt\" was not found" << endl;
        exit(1);
    }
    else{
        //read from the file
        while(input.good()){
            getline(input, line);
            text.push_back(line);
        }
        //run the rest of the parser
        Parser::run();
    }
    input.close();
}

void Parser::run() {
    int i;
    string str;
    vector<string> check;
    ifstream input("ex.txt");
    string line;
    for(i = 0; i < text.size()-1; i++){
        //check for contents
        if(!(text.at(i).empty())){
            vector<string> item;
            istringstream strAux(text[i]);
            while(getline(strAux, str, ' ')){
                item.push_back(str);
            }
            vector<string> check = validateVal(item);
            getline(input, line);
            cout << line << "\n";
            cout << check.at(i) << endl;
        }
        else{
            cout << "Empty file. Exiting.";
            exit(1);
        }
    }
    exit(0);
}

vector<string> Parser::validateVal(vector<string> item) {
    stringstream s;
    vector<string> result(2), temp(2);
    ReferenceTable *reference = new ReferenceTable;
    int i;
    for(i = 0; i < item.size(); i++){
        if(item[1] == "="){
            temp = reference->validateAssignment(item);
            if(temp[0] == "1"){
                result[0] = "Valid assignment \n";
                result[1] = " ";
                delete reference;
                return result;
            }
            result[0] = "Invalid assignment \n";
            result[1] = temp[1];
            delete reference;
            return result;
        }
    }
    temp = reference->validateExpression(item);
    if(temp[0] == "1"){
        result[0] = "Valid expression\n";
        result[1] = " ";
        delete reference;
        return result;
    }
    result[0] = "Invalid expression\n";
    result[1] = temp[1];
    delete reference;
    return result;
}