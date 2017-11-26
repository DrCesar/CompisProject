//
// Created by WadeOwen on 28-Oct-17.
//

#include "KernelItem.h"


KernelItem::KernelItem() {

    this->prod = nullptr;
    this->pointer = nullptr;
    this->isKernel = false;
}

KernelItem::KernelItem(Production *p) {

    this->prod = p;
    this->pointer = p->GetStart();
    this->isKernel = false;
}

KernelItem::KernelItem(Production* p, bool b) {

    this->prod = p;
    this->pointer = p->GetStart();
    this->isKernel = b;
}

KernelItem::KernelItem(Production* p, Node<Symbol*>* n) {
    this->prod = p;
    this->pointer = n;

    if (this->pointer != prod->GetStart())
        this->isKernel = false;
    else
        this->isKernel = true;
}

void KernelItem::MovePointer() {

    if (this->pointer->GetNext() != nullptr) {
        this->pointer = this->pointer->GetNext();

    }
}

std::string KernelItem::ToString() const {

    std::string s;
    Node<Symbol*>* temp = this->prod->GetStart();

    while (temp != nullptr) {
        if (this->pointer == temp)
            s = s + '.';
        s = s + temp->GetInfo()->GetInfo();
    }

    return s;
}
