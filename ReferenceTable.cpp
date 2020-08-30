//CS530 Lab 3
//Francisco Melendez Hernandez, cssc 1905
//5/6/20
//Validates the input from the ex.txt file

#include "ReferenceTable.h"
#define NUM_OPERATORS 7
#define NUM_NUMBERS 10
#define NUM_CHARACTERS 52

/*validate operators*/
struct operators{
    char op;
};
struct operators operatorTable[] = {
        {'+'}, {'-'}, {'*'}, {'/'}, {'%'}, {'='}, {';'}
};
bool ReferenceTable::validateOp(char op) {
    int i;
    for(i=0; i < NUM_OPERATORS; i++){
        if(operatorTable[i].op == op)
           return true;
    }
    return false;
}

/*validate numbers*/
struct numbers{
    char number;
};
struct numbers numberTable[] = {
        {'0'}, {'1'}, {'2'}, {'3'},
        {'4'}, {'5'}, {'6'}, {'7'},
        {'8'}, {'9'}
};
bool ReferenceTable::validateNumber(char number) {
    int i;
    for(i = 0; i < NUM_NUMBERS; i++){
        if(numberTable[i].number == number)
            return true;
    }
    return false;
}

/*validate character*/
struct characters{
    char character;
};
struct characters characterTable[] ={
        { 'A' },    { 'B' },
        { 'C' },   { 'D' },
        { 'E' },    { 'F' },
        { 'G' },   { 'H' },
        { 'I' },    { 'J' },
        { 'K' },   { 'L' },
        { 'M' },    { 'N' },
        { 'O' },   { 'P' },
        { 'Q' },    { 'R' },
        { 'S' },   { 'T' },
        { 'U' },    { 'V' },
        { 'W' },   { 'X' },
        { 'Y' },    { 'Z' },
        { 'a' },   { 'b' },
        { 'c' },    { 'd'},
        { 'e' },   { 'f' },
        { 'g' },    { 'h'},
        { 'i' },   { 'j' },
        { 'k' },    { 'l' },
        { 'm' },   { 'n' },
        { 'o' },    { 'p' },
        { 'q' },   { 'r' },
        { 's' },    { 't' },
        { 'u' },   { 'v' },
        { 'w' },    { 'x' },
        { 'y' },   { 'z' }
};
bool ReferenceTable::validateChar(char character) {
    int i;
    for(i = 0; i < NUM_CHARACTERS; i++){
        if(characterTable[i].character == character){
            return true;
        }
    }
    return false;
}

/*Validate ID*/
bool ReferenceTable::validateID(string item) {
    int i;
        for(i=0; i < item.length(); i++){
            if(validateNumber(item[i])){
                continue;
            }
            if(validateChar(item[i])){
                continue;
            }
            if(validateOp(item[i])){
                continue;
            }
            else if (!(validateNumber(item[i])) && !(validateChar(item[i])) && !(validateOp(item[i]))){
                return false;
            }
        }
        return true;
}

vector<string> ReferenceTable::validateExpression(vector<string> item){
    stringstream s;
    ReferenceTable *reference = new ReferenceTable();
    vector<string> out;
    int i;
    int p, pFlagLeft = 0, pFlagRight = 0;

    //check for uneven parentheses
    for(p = 0; p<item.size(); p++){
        if(item[p] == "("){
            pFlagLeft++;
        }
        else if(item[p] == ")"){
            pFlagRight++;
        }
        if(pFlagLeft != pFlagRight) {
            s << "Line \" " << item[p] << " \" has an unequal amount of parentheses" << endl;
            out.push_back("0");
            out.push_back(s.str());
            delete reference;
            return out;
        }
    }
    if((reference->validateID(item[0]) == true) && (item[0] != " ")){
        if((reference->validateOp(item[1][0])==true) && (item[1].length() == 1)){
            if(reference->validateID(item[item.size()-1])){
                for(i = 2; i <item.size()-1;i++){
                    if(!(reference->validateID(item[i]))){
                        s << "Line \" " <<item[i] << " \" has an invalid ID" << endl;
                        out.push_back("0");
                        out.push_back(s.str());
                        delete reference;
                        return out;
                    }
                    ++i;
                }
                out.push_back("1");
                out.push_back(" ");
                delete reference;
                return out;
            }
            s<< "Line \"" << item[item.size()-1] << "\" has an invalid ID";
            out.push_back("0");
            out.push_back(s.str());
            delete reference;
            return out;
        }
        s << "Line \" " << item[1] << " \" has an invalid operator" << endl;
        out.push_back("0");
        out.push_back(s.str());
        delete reference;
        return out;
    }
    s << "Line \" " <<item[0] << " \" has an invalid ID" << endl;
    out.push_back("0");
    out.push_back(s.str());
    delete reference;
    return out;
}

vector<string> ReferenceTable::validateAssignment(vector<string> item){
    stringstream s;
    ReferenceTable *reference = new ReferenceTable();
    vector<string> out;
    int i;

    if(reference->validateID(item[0]) == true){
        if(item[1] == "="){
            if(item[item.size() - 1][0] == ';'){
                return validateExpression(item);
            }
            s<< "The final token is not a \";\" "<< endl;
            out.push_back("0");
            out.push_back(s.str());
            return out;
        }
        s<< "The second token is not a \"=\" "<< endl;
        out.push_back("0");
        out.push_back(s.str());
        return out;
    }
    s<< "The first token is not valid as an ID: " << endl;
    out.push_back("0");
    out.push_back(s.str());
    return out;
}


