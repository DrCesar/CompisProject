//
// Created by WadeOwen on 20-Oct-17.
//

#ifndef PROYECTOCOMPIS_PRODUCTION_H
#define PROYECTOCOMPIS_PRODUCTION_H

#include <map>
#include <list>

class Production {

    struct Node {

        std::string info;
        Node* next;

        Node(std::string& s) {
            info = s;
        }
    };

    struct Body {
        std::map<std::string, std::list<Node*>> termsBody;

        Node* start;
        Node* end;
    };

private:
    std::list<Body*> body;
    std::string head;



public:
    Production(std::string&);

    void AddTermBody(std::string&);
    void NewBoty(std::string&);
    std::map<std::string, std::string> GetFirst();

};


#endif //PROYECTOCOMPIS_PRODUCTION_H
