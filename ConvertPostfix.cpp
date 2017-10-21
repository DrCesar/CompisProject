//
// Created by WadeOwen on 28-Aug-17.
//

#include "ConvertPostfix.h"


ConvertPostfix::ConvertPostfix(std::string s, bool op = false) {

    if (op) {
        s = RegexConverter(s);
    }

    int i = 0;

    this->ts = false;
    this->regex = s;

    while (i < s.length()) {

        switch (s[i]){
            case '(':
                if (ts)
                    signo('.');
                sOper.push(s[i]);
                break;
            case ')':
                while (!sOper.empty() && sOper.top() != '(') {
                    sPostfix.push(sOper.top());
                    sOper.pop();
                }
                if (!sOper.empty())
                    sOper.pop();
                break;
            case '+':
            case '*':
            case '.':
            case '|':
                signo(s[i]);
                break;
            case '?':
                signo('|');
                sOper.push('@');
                break;
            default:
                if (ts)
                    signo('.');
                sPostfix.push(s[i]);
                ts = true;
                break;

        }
        i++;
    }
    while (!sOper.empty()) {
        sPostfix.push(sOper.top());
        sOper.pop();
    }

    postfix = "";
    while (!sPostfix.empty()) {
        postfix = sPostfix.top() + postfix;
        sPostfix.pop();
    }
}


int ConvertPostfix::jer(char c) {

    switch (c) {
        case '(':
            return 4;
        case '+':
        case '*':
            return 3;
        case '.':
            return 2;
        case '|':
            return 1;
        default:
            return 0;
    }
}


void ConvertPostfix::signo(char s) {

    while(!sOper.empty() && jer(sOper.top()) <= jer(s)) {
        sPostfix.push(sOper.top());
        sOper.pop();
    }

    if (s == '*' || s == '+'){
        sPostfix.push(s);
        ts = true;
    } else {
        sOper.push(s);
        ts = false;
        std::cout << "asdf" << std::endl;
    }
}

std::string ConvertPostfix::RegexConverter(std::string s) {


    int i = 0;
    this->regex = "";

    while (i < s.length()) {

        switch (s[i]) {
            case '{':

        }
    }

    return nullptr;
}
