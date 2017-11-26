//
// Created by WadeOwen on 12-Sep-17.
//

#include "DState.h"

DState::DState() {

    this->end = false;
    this->start = false;
    this->num = "";
}

DState::DState(std::map<Node*, Node*> l) {

    this->nodeList = l;

    this->end = false;
    this->start = false;
    this->marked = false;
    this->num = "";
}

void DState::AddTransition(DState* d, std::string s) {

    this->transition[s] = d;
}

bool DState::ContainsN(std::string n) {

    if (this->transition.find(n) != this->transition.end())
        return true;
    else
        return false;
}
