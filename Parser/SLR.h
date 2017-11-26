//
// Created by WadeOwen on 20-Oct-17.
//

#ifndef PROYECTOCOMPIS_PREDICTIVEPARSER_H
#define PROYECTOCOMPIS_PREDICTIVEPARSER_H

#include "Production.h"
#include <vector>
#include <stack>
#include <stdio.h>
#include "Node.h"
#include "Symbol.h"
#include "KernelItem.h"
#include "AutomatonP.h"

class SLR {

    struct SR {
        std::string info;
        State* stat;
        Production* prod;

        SR () {
            this->info = "Accept";
        }

        SR(std::string s) {
            this->info = s;
        }

        SR(State* s) {
            this->stat = s;
            this->prod = nullptr;
            this->info = "Shift";
        }

        SR(Production* p) {
            this->prod = p;
            this->stat = nullptr;
            this->info = "Reduce";
        }

    };

private:
    std::map<std::string, Symbol*> symbols;
    std::map<Symbol*, std::list<Production*>> productions;
    std::map<Symbol*, std::list<Production*>> belongProductions;
    Production* initial;
    AutomatonP automat;

    std::map<State*, std::map<Symbol*, SR>> parserTable;



public:
    SLR(std::map<Symbol*, std::list<Production*>>);
    SLR(std::map<Symbol*, std::list<Production*>>, std::map<Symbol*, std::list<Production*>>, std::map<std::string, Symbol*>);
    SLR(std::map<Symbol*, std::list<Production*>>, std::map<std::string, Symbol*>);

    AutomatonP GetAutomaton() { return this->automat; }

    std::map<std::string, Symbol*> First(Symbol*);
    std::map<std::string, Symbol*> First(std::list<Symbol*>);
    std::map<std::string, Symbol*> Follow(Symbol*);

    void CreateAutomaton();
    void CreateParserTable();
    State* Goto(State*, std::list<Node<Symbol*>*>);
    std::map<Node<Symbol*>*, KernelItem*> Closure(KernelItem*);
    std::map<Node<Symbol*>*, KernelItem*> Closure(std::map<Node<Symbol*>*, KernelItem*>);

    void Parse(std::vector<Symbol*>);
    void SetInitialProduction(Production* p);

    void PrintTable();
    void PrintParser(std::stack<State*>, std::vector<Symbol*>, std::vector<Symbol*>, SR);
};


#endif //PROYECTOCOMPIS_PREDICTIVEPARSER_H
