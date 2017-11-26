//
// Created by WadeOwen on 01-Nov-17.
//

#ifndef PROYECTOCOMPIS_NODE_H
#define PROYECTOCOMPIS_NODE_H

#include <iostream>

#include "Symbol.h"

template <class T>
class Node {

private:
    T info;
    Node* next;

public:
    Node(T s) { this->info = s; this->next = nullptr; }
    T GetInfo() { return this->info; }
    Node* GetNext() { return this->next; }

    void SetInfo(T s) { this->info = s; }
    void SetNext(Node* n) { this->next = n; }

    //std::string ToString();
};


#endif //PROYECTOCOMPIS_NODE_H
