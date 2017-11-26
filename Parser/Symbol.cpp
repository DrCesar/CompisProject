//
// Created by WadeOwen on 28-Oct-17.
//

#include "Symbol.h"

Symbol::Symbol(std::string s) {
    this->info = s;
    this->terminal = true;
}

Symbol::Symbol(std::string s, bool b) {

    this->info = s;
    this->terminal = b;
}

std::string Symbol::ToString() {

    return this->info;
}
