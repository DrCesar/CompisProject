//
// Created by WadeOwen on 28-Oct-17.
//

#ifndef PROYECTOCOMPIS_SYMBOL_H
#define PROYECTOCOMPIS_SYMBOL_H

#include <iostream>
#include <map>

class Symbol {

private:
    std::string info;
    bool terminal;

public:
    Symbol(std::string);
    Symbol(std::string, bool);

    std::string GetInfo() { return this->info; }
    bool IsTerminal() {return this->terminal; }
    void SetTerminal(bool b) { this->terminal = b; }

    std::string ToString();
};


#endif //PROYECTOCOMPIS_SYMBOL_H
