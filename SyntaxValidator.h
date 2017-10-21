//
// Created by WadeOwen on 13-Sep-17.
//

#ifndef PROYECTOCOMPIS_SYNTAXVALIDATOR_H
#define PROYECTOCOMPIS_SYNTAXVALIDATOR_H

#include <iostream>

class SyntaxValidator {

public:
    std::string letterFormat = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string digitFormat = "0123456789";
    std::string anyFormat = "{@N&}";
    std::string stringFormat = "\"{@N&S}\"";
    std::string charFormat = "'[@N&C]'";
    std::string identFormat = letterFormat + "{" + letterFormat + "|" + digitFormat + "}";
    std::string numberFormat = digitFormat + "{" + digitFormat + "}";

    std::string attributesFormat = "<.{" + anyFormat + "}.>";
    std::string semactionFormat = "(.{" + anyFormat + "}.)";





};


#endif //PROYECTOCOMPIS_SYNTAXVALIDATOR_H
