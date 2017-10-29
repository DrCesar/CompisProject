//
// Created by WadeOwen on 12-Sep-17.
//

#ifndef PROYECTOCOMPIS_DSTATE_H
#define PROYECTOCOMPIS_DSTATE_H

#include "Node.h"
#include "Production.h"
#include "Symbol.h"

class DState {

    std::string num;
    bool end;
    bool start;
    std::map<Production*, Production*> prodList;
    std::map<Node*, Node*> nodeList;
    std::map<std::string, DState*> transition;
    std::map<Symbol, DState*> transitionS;
    bool marked;

public:
    DState();
    DState(Production* p);
    DState(std::map<Production*, Production*> pl);
    DState(std::map<Node*, Node*>);

    void SetNodeList(std::map<Node*, Node*> l){ this->nodeList = l; }
    void SetTransition(std::map<std::string, DState*> l){ this->transition = l; }
    void SetMarked(bool b){ this->marked = b; }
    void SetNum(std::string n){ this->num = n; }
    void SetEnd(bool b){ this->end = b; }
    void SetStart(bool b){ this->start = b; }

    std::map<Node*, Node*> GetNodeList(){ return this->nodeList; };
    std::map<Production*, Production*> GetProdList() { return this->prodList; }
    std::map<std::string, DState*> GetTransition(){ return this->transition; }
    std::map<Symbol, DState*> GetTransitionS(){ return this->transitionS; }
    bool GetMarked(){ return this->marked; }
    std::string GetNum(){ return this->num; }
    bool GetEnd(){ return this->end; }
    bool GetStart(){ return this->start; }


    bool ContainsN(std::string);
    void AddTransition(DState*, std::string);
    void AddTransitionS(DState*, Symbol);

};


#endif //PROYECTOCOMPIS_DSTATE_H
