//
// Created by WadeOwen on 23-Nov-17.
//

#ifndef PROYECTOCOMPIS_AUTOMATON_H
#define PROYECTOCOMPIS_AUTOMATON_H

#include "State.h"

class AutomatonP {

private:
    std::map<int, State*> states;
    std::map<State*, State*> end;
    State* start;
    int numStates;


public:
    AutomatonP();
    AutomatonP(State*);

    State* GetStart() { return this->start; }
    std::map<State*, State*> GetEnd() { return this->end; };
    std::map<int, State*> GetStates() const { return this->states; };

    State* AddState(State*);
    State* GetMarked();

    void Print();
    std::string ToString();
};


#endif //PROYECTOCOMPIS_AUTOMATON_H
