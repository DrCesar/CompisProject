//
// Created by WadeOwen on 20-Oct-17.
//

#include "PredictiveParser.h"


PredictiveParser::PredictiveParser(std::map<std::string, Production *> p) {

    this->productions = p;
}

std::map<std::string,std::string> PredictiveParser::First(std::list<std::string> l) {

    int counter = 0;
    std::map<std::string, std::string> ans, temp;
    std::list<std::string>::const_iterator lIter = l.begin();

    do {
        temp = this->productions[*lIter]->GetFirst();



    } while (temp["@"] != nullptr);
}

