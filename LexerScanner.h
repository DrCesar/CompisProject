//
// Created by WadeOwen on 13-Sep-17.
//

#ifndef PROYECTOCOMPIS_SYNTAXVALIDATOR_H
#define PROYECTOCOMPIS_SYNTAXVALIDATOR_H

#include <iostream>
#include <fstream>
#include "Production.h"

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

    std::map<std::string, Production*> productions;


public:
    LexerScanner(std::string);

    std::map<std::string, Production*> GetProductions() { return this->productions; }

    void ProductionScanner();
    void CreateProduction();
    std::string GetNextElement();
    std::string GetNextLine();
    std::string GetCurrentLine();
};


#endif //PROYECTOCOMPIS_SYNTAXVALIDATOR_H
