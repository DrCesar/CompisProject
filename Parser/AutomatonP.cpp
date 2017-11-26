//
// Created by WadeOwen on 23-Nov-17.
//

#include "AutomatonP.h"

AutomatonP::AutomatonP() {

    this->start = nullptr;
    this->numStates = 0;
}

AutomatonP::AutomatonP(State* s) {

    this->start = s;
    this->start->SetStart(true);
    s->SetNum(this->numStates = 1);
    this->states[s->GetNum()] = s;
}


void AutomatonP::Print() {

    for (auto const& s : this->states)
        s.second->Print();
}

State* AutomatonP::GetMarked() {

    for (auto const x: this->states) {
        if (!x.second->GetMarked())
            return x.second;
    }
    return nullptr;
}

State* AutomatonP::AddState(State* s) {

    if (s != nullptr) {
        for (const auto x : this->states)
            if (x.second->GetProdList() == s->GetProdList())
                return x.second;

        s->SetNum(++this->numStates);
        this->states[s->GetNum()] = s;
    }

    return s;
}