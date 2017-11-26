//
// Created by WadeOwen on 20-Oct-17.
//

#ifndef PROYECTOCOMPIS_PRODUCTION_H
#define PROYECTOCOMPIS_PRODUCTION_H

#include <map>
#include <list>
#include <vector>
#include <iostream>
#include "Symbol.h"
#include "Node.h"

class Production {


private:
    std::map<Symbol*, std::list<Node<Symbol*>*>> body;
    Node<Symbol*>* start;
    Node<Symbol*>* end;
    Symbol* head;
    std::map<Production*, Production*> belongProductions;
    bool isTerminal;


public:
    Production(std::string, bool);
    Production(Symbol*);
    Production(Symbol*, Symbol*);

    std::map<Symbol*, std::list<Node<Symbol*>*>> GetBody() { return this->body; }
    Symbol* GetHead() { return this->head; }
    Node<Symbol*>* GetStart() { return this->start; }
    bool GetIsTerminal() { return this->isTerminal; }
    std::map<Production*, Production*> GetBelongBodys() { return this->belongProductions; }

    void SetIsterminal(bool b) { this->isTerminal = b; }

    void AddTermBody(Symbol*);
    void AddBelongProduction(Production*);

    void Print();
    std::string ToString();
};


#endif //PROYECTOCOMPIS_PRODUCTION_H
