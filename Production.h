//
// Created by WadeOwen on 20-Oct-17.
//

#ifndef PROYECTOCOMPIS_PRODUCTION_H
#define PROYECTOCOMPIS_PRODUCTION_H

#include <map>
#include <list>
#include <vector>
#include <iostream>

class Production {

    struct Node {

        Production* p;
        Node* next;

        Node(Production* x) {
            p = x;
            next = nullptr;
        }

        std::string GetSymbol() {
            return this->p->GetHead();
        }

    };

    struct Body {
        std::map<std::string, std::list<Node*>> termsBody;

        Node* start;
        Node* end;
    };




private:
    std::list<Body*> body;
    std::string head;
    std::map<Production*, Production*> belongProductions;
    bool isTerminal;



public:
    Production(std::string);
    Production(std::string, bool);

    std::list<Body*> GetBody() { return this->body; }
    std::string GetHead() { return this->head; }
    bool GetIsTerminal() { return this->isTerminal; }
    std::map<Production*, Production*> GetBelongBodys() { return this->belongProductions; }

    void SetIsterminal(bool b) { this->isTerminal = b; }

    void AddTermBody(Production*);
    void NewBody(Production*);
    void AddBelongProduction(Production*);

    std::map<std::string, Production*> GetFirst();
    std::map<std::string, Production*> GetFollow();

    void Print();
};


#endif //PROYECTOCOMPIS_PRODUCTION_H
