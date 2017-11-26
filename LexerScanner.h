//
// Created by WadeOwen on 13-Sep-17.
//

#ifndef PROYECTOCOMPIS_SYNTAXVALIDATOR_H
#define PROYECTOCOMPIS_SYNTAXVALIDATOR_H

#include <iostream>
#include <fstream>
#include <stack>
#include "Parser/Production.h"
#include "Parser/Symbol.h"

class LexerScanner {

private:
    std::string letterFormat = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string digitFormat = "0123456789";
    std::string anyFormat = "{@N&}";
    std::string stringFormat = "\"{@N&S}\"";
    std::string charFormat = "'[@N&C]'";
    std::string identFormat = letterFormat + "{" + letterFormat + "|" + digitFormat + "}";
    std::string numberFormat = digitFormat + "{" + digitFormat + "}";

    std::string attributesFormat = "<.{" + anyFormat + "}.>";
    std::string semactionFormat = "(.{" + anyFormat + "}.)";

    std::ifstream file;
    std::string currentLine;
    int countCurrent;

    std::map<std::string, Symbol*> symbols;
    std::map<Symbol*, std::list<Production*>> productions;
    std::map<Symbol*, std::list<Production*>> belongProductions;
    Production* initialP;


public:
    LexerScanner(std::string);

    std::map<Symbol*, std::list<Production*>> GetProductions() { return this->productions; }
    std::map<std::string, Symbol*> GetSymbols() { return this->symbols; };
    std::map<Symbol*, std::list<Production*>> GetBelongProd() { return this->belongProductions; };

    Production* GetInitialProduction() { return this->initialP; }
    std::vector<Symbol*> LexeTokens(std::string);

    void ProductionScanner();
    void CreateProduction();
    std::string GetNextElement();
    std::string SetNextLine();
    std::string GetCurrentLine();
    bool IsEndOfLine();
};


#endif //PROYECTOCOMPIS_SYNTAXVALIDATOR_H
