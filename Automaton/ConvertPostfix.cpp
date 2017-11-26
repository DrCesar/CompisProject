//
// Created by WadeOwen on 28-Aug-17.
//

#include "ConvertPostfix.h"


ConvertPostfix::ConvertPostfix(std::string s, bool op = false) {


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
                    char x = sOper.top();
                    sPostfix.push(x);
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
        char x = sOper.top();
        sPostfix.push(x);
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
            return 0;
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
        char x = sOper.top();
        sPostfix.push(x);
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

ConvertPostfix::ConvertPostfix(std::string s){

    bool inStrChr = false;
    int i = 0;

    this->imOp = false;
    this->regex = "";

    while (i < s.length()) {

        if (inStrChr) {

        }

        switch (s[i]) {
            case '{':
            case '(':
                if (!inStrChr) {
                    if (this->imOp)
                        Sign('.');
                    Sign('(');
                }
                break;
            case ']':
            case ')':
            case '}':
                if (!inStrChr) {
                    while (!this->op.empty() && op.top().info != '(') {
                        Symbol x = op.top();
                        temp.push(x);
                        op.pop();
                    }

                    if (!op.empty())
                        op.pop();

                    if (s[i] == '}' || s[i] == ']')
                        op.push(Symbol('*', true));
                }
                break;
            case '.':
            case '|':
            case '*':
            case '+':
                if (!inStrChr)
                    Sign(s[i]);
                break;
            case ' ':
                break;
            default:
                if (imOp)
                    Sign('.');



        }
    }

}

int ConvertPostfix::Hierarchy(char c) {

    switch (c) {
        case '(':
            return 0;
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

void  ConvertPostfix::Sign(char c) {

    while (!op.empty() && jer(c) <= jer(op.top().info)) {
        Symbol x = op.top();
        temp.push(x);
        op.pop();
    }

    if (c == '*' || c == '+')
        ts = true;
    else
        ts = false;

    op.push(Symbol(c, true));
}

bool ConvertPostfix::StillInStrChr(std::string s, int i){

    if (i < s.length())
        return false;

    switch (s[i]) {
        case '{':
        case '}':
        case '[':
        case ']':
        case '(':
        case ')':
        case '+':
        case '-':
        case '.':
        case '|':
            return false;
        case ' ':
            return StillInStrChr(s, i + 1);
        default:
            return true;
    }

}

