Francisco Melendez Hernandez, Thong Le, Nathaniel Stewart, Tim Tea
CS530, Spring 2020
Assignment #3, Parser
README.txt

File Manifest
main.cpp
Parser.cpp/.h
ReferenceTable.cpp/.h

Compile instructions
type "make" on the terminal line. The source code will be compiled automatically using g++ -std=c++11. It will create an 'exp' file

Operating Instructions
type 'exp ex.txt' to run the program with the source file (provide your "ex.txt")

List/Description of novel/significant design decisions
-Using stringstreams to hold the result strings, and then pushing those stringstream contents into a vector that contains the results
-Using vectors to hold "0" or "1" as an indication of the result of the checks

List/Description of all known deficiencies or bugs
-ReferenceTable.cpp::validateAssignment has unruly coding style. It is pretty messy.
- some of the stringstreams from validateExpressions never get printed. They're stored but never outputted
-In ReferenceTable.cpp, the check for parentheses is not robust at all. The checks themselves assume that the additional possible extra space
 (depending on if it's an opening or closing parenthesis). Also, the check doesn't flag input such as ")( ))(("
-If the first character of a token is not valid, it won't be caught. This is because the logic of the method used to validate the first character coulnd't be used to also validate every other token without being incorrect. 
-If more than 2 lines in ex.txt are inputted, the program throws an out of range exception after the second line is analyzed and it's output is shown.
    My hypothesis is either an error occurs when reading in the files themselves (perhaps on Parser::line 20) or Parser.cpp::line 47

Lessons Learned
-Implementing parsers in C++ instead of Lex/Yacc
-Modularization
-Vectors
-Manually freeing memory from the heap
-Logic pertaining to pointers to character positions in a string
-Logic pertaining to checking each case of token

Grammar (BNF)
<assign> 	::= id = <exp> ;
<exp>   	::= <id> <op> <id> { <op> <id> }
<id>    	::= <char>|<id><char>|<id><digit>
<char>      	::= a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z|A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z
<digit> 	::= 0|1|2|3|4|5|6|7|8|9
<op> 		::= +|-|*|/|%|=|;