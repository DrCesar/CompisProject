//
// Created by WadeOwen on 20-Oct-17.
//

#include "Production.h"

Production::Production(std::string s, bool b) {

    this->head = new Symbol(s, b);
    this->isTerminal = b;
    this->start = nullptr;
}

Production::Production(Symbol* s) {

    this->head = s;
    this->isTerminal = false;
    this->start = nullptr;
}

Production::Production(Symbol* s, Symbol* s2) {

    this->head = s;
    this->isTerminal = s->IsTerminal();
    AddTermBody(s2);
}

void Production::AddTermBody(Symbol* s) {

    Node<Symbol*>* tempNode = new Node<Symbol*>(s);
    if (this->start == nullptr) {
        this->start = tempNode;
        Node<Symbol*>* en = new Node<Symbol*>(new Symbol("END"));
        this->start->SetNext(en);
    } else {
        tempNode->SetNext(end->GetNext());
        this->end->SetNext(tempNode);
    }

    this->end = tempNode;
    this->body[s].push_back(tempNode);
}

void Production::AddBelongProduction(Production* p) {

    this->belongProductions[p] = p;
}

void Production::Print() {

    std::cout << this->head->GetInfo() << " = ";

    Node<Symbol*>* n = this->start;
    while (n != nullptr) {
        std::cout << n->GetInfo()->GetInfo() << " ";
        n = n->GetNext();
    }

    std::cout << std::endl;
}


std::string Production::ToString() {

    std::string ans = this->head->GetInfo() + " = ";

    Node<Symbol*>* n = this->start;
    while (n->GetInfo()->GetInfo() != "END") {
        ans = ans + n->GetInfo()->GetInfo() + " ";
        n = n->GetNext();
    }

    return ans;
}


