//
// Created by WadeOwen on 28-Oct-17.
//

#ifndef PROYECTOCOMPIS_KERNELITEM_H
#define PROYECTOCOMPIS_KERNELITEM_H

#include "Production.h"
#include "Symbol.h"
#include "Node.h"

class KernelItem {

private:
    Production* prod;
    Node<Symbol*>* pointer;
    bool isKernel;


public:
    KernelItem();
    KernelItem(Production*);
    KernelItem(Production*, bool);
    KernelItem(Production*, Node<Symbol*>*);

    Node<Symbol*>* GetPointer() { return this->pointer; }
    Production* GetProduction() { return this->prod; }
    int Nigga() {return 1;}

    bool IsKernel() { return this->isKernel; }
    bool IsTerminal() { return this->pointer->GetInfo()->IsTerminal(); }
    void MovePointer();


    std::string ToString() const;
};


#endif //PROYECTOCOMPIS_KERNELITEM_H
