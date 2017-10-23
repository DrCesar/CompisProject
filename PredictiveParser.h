//
// Created by WadeOwen on 20-Oct-17.
//

#ifndef PROYECTOCOMPIS_PREDICTIVEPARSER_H
#define PROYECTOCOMPIS_PREDICTIVEPARSER_H

#include "Production.h"
#include <vector>

class PredictiveParser {

private:
    std::map<std::string, Production*> productions;


public:
    PredictiveParser(std::map<std::string, Production*>);

    std::map<std::string, Production*> First(Production*);
    std::map<std::string, Production*> First(std::vector<std::string>);
    std::map<std::string, Production*> Follow(std::string);


};


#endif //PROYECTOCOMPIS_PREDICTIVEPARSER_H
