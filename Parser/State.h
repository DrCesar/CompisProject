//
// Created by WadeOwen on 02-Nov-17.
//

#ifndef PROYECTOCOMPIS_DSTATE_H
#define PROYECTOCOMPIS_DSTATE_H

#include "Node.h"
#include "KernelItem.h"
#include <iostream>
#include <map>


class State {

private:
    std::map<Node<Symbol*>*, KernelItem*> itemsList;
    std::map<Node<Symbol*>*, Production*> prodList;
    std::map<Symbol*, std::list<Node<Symbol*>*>> pointerList;
    std::map<Symbol*, State*> transitions;
    bool marked;
    bool start;
    int num;

public:
    State(std::map<Node<Symbol*>*, KernelItem*>);
    State(Production*);

    void SetStart(bool b) { this->start = b; }
    void SetMarked(bool b)  { this->marked = b; }
    void SetNum(int s) { this->num = s; }

    int GetNum() { return this->num; }
    bool GetStart() { return this->start; }
    bool GetMarked() { return this->marked; }
    std::map<Symbol*, std::list<Node<Symbol*>*>> GetNodeList() { return this->pointerList; }
    std::map<Node<Symbol*>*, KernelItem*> GetItemList() { return this->itemsList; }
    std::map<Node<Symbol*>*, Production*> GetProdList() { return this->prodList; };

    void AddTransition(Symbol*, State*);

    void Print();
};


#endif //PROYECTOCOMPIS_DSTATE_H
