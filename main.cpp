#include <iostream>
#include "LexerScanner.h"
#include "Parser/SLR.h"

#include "Parser/Node.h"



int main() {
    std::cout << "Hello, World!" << std::endl;

    LexerScanner scan = LexerScanner("test.txt");

    SLR parser = SLR(scan.GetProductions(), scan.GetBelongProd(), scan.GetSymbols());

    parser.SetInitialProduction(scan.GetInitialProduction());

    parser.CreateAutomaton();

    parser.GetAutomaton().Print();
    parser.PrintTable();
    std::string s = "id + id * id";

    parser.Parse(scan.LexeTokens(s));

    return 0;
}

