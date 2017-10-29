//
// Created by WadeOwen on 20-Oct-17.
//

#ifndef PROYECTOCOMPIS_PREDICTIVEPARSER_H
#define PROYECTOCOMPIS_PREDICTIVEPARSER_H

#include "Production.h"
#include "Automaton.h"
#include <vector>
#include "Symbol.h"

class PredictiveParser {

    struct Node {
        Symbol s = Symbol("");
        Node* next = nullptr;

        Node(Symbol x) { s = x; }
        Node(std::string& x) { s = Symbol(x); }
    };

    struct KernelItem {
        Production* production;
        Node* pointer;

        KernelItem(Production* p) { production = p; }
        void MovePointer() { if (pointer->next != nullptr) pointer->next = pointer->next->next; }
    };

private:
    std::map<std::string, Production*> productions;
    Production* initial;
    DState* start;
    Automaton* automat;


public:
    PredictiveParser(std::map<std::string, Production*>);

    std::map<std::string, Production*> First(Production*);
    std::map<std::string, Production*> First(std::vector<std::string>);
    std::map<std::string, Production*> Follow(std::string);

    void CreateAutomaton();
    DState* Goto(DState*, Symbol);
    DState* Closure(DState*);

};


#endif //PROYECTOCOMPIS_PREDICTIVEPARSER_H
