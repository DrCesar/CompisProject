//
// Created by WadeOwen on 12-Sep-17.
//

#ifndef PROYECTOCOMPIS_AUTOMATON_H
#define PROYECTOCOMPIS_AUTOMATON_H

#include <iostream>
#include "SyntacticTree.h"
#include "DState.h"

class Automaton {

private:
    std::map<DState*, DState*> states;
    std::map<DState*, DState*> end;
    std::map<std::string, std::string> alfa;
    DState* start;
    DState* marked;

    void CreateAutomaton(SyntacticTree&);


public:
    Automaton(std::string&, bool);
    Automaton(SyntacticTree&);

    DState* GetStart(){ return this->start; }

    void AddEnd(DState* d){ this->end[d] = d; }

    std::map<DState*, DState*> Move(std::map<DState*, DState*>&, std::string&);
    bool Simulate(std::string&);

    void ToString();

    ~Automaton() {
        delete this->start;
        for (auto const x : this->end)
            delete x.second;
    }


};


#endif //PROYECTOCOMPIS_AUTOMATON_H
