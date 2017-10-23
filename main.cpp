#include <iostream>
#include "ConvertPostfix.h"
#include "SyntacticTree.h"
#include "Automaton.h"
#include "LexerScanner.h"
#include "PredictiveParser.h"



int main() {
    std::cout << "Hello, World!" << std::endl;

    LexerScanner scan = LexerScanner("test.txt");

    PredictiveParser parser = PredictiveParser(scan.GetProductions());

    std::string prod;
    std::string option;
    std::map<std::string, Production*> temp;
    std::vector<std::string> v;

    v.push_back("TP");
    temp = parser.Follow("TP");
    for (auto const& x : temp)
        std::cout << x.second->GetHead();

    std::cout << std::endl;


//    while (option != "3") {
//        temp.clear();
//        std::cout << "Ingrese la cadena que desea evaluar." << std::endl;
//        std::cin >> prod;
//        std::cout << "Ingrese la opcion que quiere. \n 1. First \n 2. Follow \n 3. Quit " << std::endl;
//        std::cin >> option;
//
//        if (option == "1") {
//            std::vector<std::string> v;
//            int i = 0;
//            while (i < prod.length()) {
//                std::string s = "";
//                while (prod[i] = ' ')
//                    i ++;
//
//                while (prod[i] !=  ' ')
//                    s = s + prod[i];
//
//                v.push_back(s);
//            }
//            temp = parser.First(v);
//        }
//
//        if (option == "2")
//           temp = parser.Follow(prod);
//
//        for (auto const& x : temp)
//            std::cout << x.second;
//
//        std::cout << std::endl;
//    }


//    std::string s;
//
//    std::cin >> s;
//
//    ConvertPostfix p (s);
//    SyntacticTree t (p);
//    Automaton a (t);
//
//
//    //std::cout << p.getPostfix()  << std::endl;
//    t.ToString();
//    a.ToString();
//
//    std::cout << "pro " << std::endl;




    return 0;
}

