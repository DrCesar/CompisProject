//
// Created by WadeOwen on 28-Oct-17.
//

#ifndef PROYECTOCOMPIS_KERNELITEM_H
#define PROYECTOCOMPIS_KERNELITEM_H

#include "Production.h"
#include "Symbol.h"

class KernelItem {

    struct Node {

        Symbol* sym;
        Node* next;

        Node(Symbol* s) {
            sym = s;
            next = nullptr;
        }
    };

private:
    Production* prod;
    Node* pointer;


public:
    KernelItem(Production*);

    void MovePointer();



};


#endif //PROYECTOCOMPIS_KERNELITEM_H
