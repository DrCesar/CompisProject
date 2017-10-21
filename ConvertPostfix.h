//
// Created by WadeOwen on 28-Aug-17.
//

#ifndef PROYECTOCOMPIS_CONVERTPOSTFIX_H
#define PROYECTOCOMPIS_CONVERTPOSTFIX_H

#include <iostream>
#include <stack>



class ConvertPostfix {

private:
    std::string postfix;
    std::string regex;
    std::stack<char> sOper;
    std::stack<char> sPostfix;
    bool ts;

public:
    ConvertPostfix(std::string, bool op);

    std::string GetPostfix(){ return postfix; }
    std::string GetRegex(){ return this->regex; }
    std::string RegexConverter(std::string);

    int jer(char);

    void signo(char);

};




#endif //PROYECTOCOMPIS_CONVERTPOSTFIX_H
