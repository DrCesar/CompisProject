//
// Created by WadeOwen on 28-Aug-17.
//

#ifndef PROYECTOCOMPIS_CONVERTPOSTFIX_H
#define PROYECTOCOMPIS_CONVERTPOSTFIX_H

#include <iostream>
#include <stack>



class ConvertPostfix {

    struct Symbol {
        char info;
        bool oper;

        Symbol(char s, bool b) {
            info = s;
            oper = b;
        }
    };

private:
    std::string postfix;
    std::string regex;
    std::stack<char> sOper;
    std::stack<char> sPostfix;
    std::stack<Symbol> op;
    std::stack<Symbol> temp;
    std::stack<Symbol> post;
    bool imOp;
    bool ts;

public:
    ConvertPostfix(std::string, bool op);
    ConvertPostfix(std::string);

    std::string GetPostfix(){ return postfix; }
    std::string GetRegex(){ return this->regex; }
    std::string RegexConverter(std::string);

    int jer(char);
    void signo(char);

    int Hierarchy(char);
    void Sign(char);
    bool StillInStrChr(std::string, int);

};




#endif //PROYECTOCOMPIS_CONVERTPOSTFIX_H
