//
// Created by WadeOwen on 12-Sep-17.
//

#ifndef PROYECTOCOMPIS_DSTATE_H
#define PROYECTOCOMPIS_DSTATE_H

#include "Node.h"

class DState {

    std::string num;
    bool end;
    bool start;
    std::map<Node*, Node*> nodeList;
    std::map<std::string, DState*> transition;
    bool marked;

public:
    DState();
    DState(std::map<Node*, Node*>);

    void SetNodeList(std::map<Node*, Node*> l){ this->nodeList = l; }
    void SetTransition(std::map<std::string, DState*> l){ this->transition = l; }
    void SetMarked(bool b){ this->marked = b; }
    void SetNum(std::string n){ this->num = n; }
    void SetEnd(bool b){ this->end = b; }
    void SetStart(bool b){ this->start = b; }

    std::map<Node*, Node*> GetNodeList(){ return this->nodeList; };
    std::map<std::string, DState*> GetTransition(){ return this->transition; }
    bool GetMarked(){ return this->marked; }
    std::string GetNum(){ return this->num; }
    bool GetEnd(){ return this->end; }
    bool GetStart(){ return this->start; }


    bool ContainsN(std::string);
    void AddTransition(DState*, std::string);


};


#endif //PROYECTOCOMPIS_DSTATE_H
