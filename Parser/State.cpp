//
// Created by WadeOwen on 02-Nov-17.
//

#include "State.h"

State::State(std::map<Node<Symbol*>*, KernelItem*> l) {

    this->itemsList = l;
    for( auto const& x: l) {
        this->prodList[x.first] = x.second->GetProduction();
        if (x.first != nullptr)
            this->pointerList[x.first->GetInfo()].push_back(x.first);
    }

    marked = false;
    start = false;
    num = 0;
}

State::State(Production* p) {

    this->itemsList[p->GetStart()] = new KernelItem(p);
    this->pointerList[p->GetStart()->GetInfo()].push_back(p->GetStart());

    marked = false;
    start = false;
    num = 0;
}

void State::AddTransition(Symbol *s, State *d){

    this->transitions[s] = d;
}

void State::Print() {

    std::string s;
    Node<Symbol*>* n;

    std::cout << this->num << std::endl;
    for (auto const& x : this->itemsList) {
        s = x.second->GetProduction()->GetHead()->GetInfo() + " = ";
        n = x.second->GetProduction()->GetStart();
        while (n != nullptr) {
            if (x.first == n)
                s = s + ".";
            s = s + n->GetInfo()->GetInfo() + " ";
            n = n->GetNext();
        }
        if (x.first == n)
            s = s + ".";
        std::cout << s << std::endl;
    }
}

