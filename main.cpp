#include <iostream>
#include "ConvertPostfix.h"
#include "SyntacticTree.h"
#include "Automaton.h"


int main() {
    std::cout << "Hello, World!" << std::endl;

    std::string s;

    std::cin >> s;

    ConvertPostfix p (s);
    SyntacticTree t (p);
    Automaton a (t);


    //std::cout << p.getPostfix()  << std::endl;
    t.ToString();
    a.ToString();

    std::cout << "pro " << std::endl;




    return 0;
}