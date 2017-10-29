//
// Created by WadeOwen on 28-Oct-17.
//

#ifndef PROYECTOCOMPIS_SYMBOL_H
#define PROYECTOCOMPIS_SYMBOL_H

#include "iostream"

class Symbol {

private:
    std::string sym;
    bool terminal;

public:
    Symbol(std::string);

    std::string GetSymbol() { return this->sym; }
    bool IsTerminal() {return this->terminal; }

    void setTerminal(bool b) { this->terminal = b; }
};


#endif //PROYECTOCOMPIS_SYMBOL_H
