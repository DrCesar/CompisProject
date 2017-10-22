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
        Production* p;
        Node* next;

        Node(std::string& s) {
            info = s;
        }

        Node(Production* x) {
            p = x;
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
    std::map<Production*, Production*> myProductions;
    bool terminal;



public:
    Production(std::string&);
    Production(std::string&, bool);

    std::list<Body*> GetBody() { return this->body; }
    std::string GetHead() { return this->head; }

    void AddTermBody(std::string&);
    void NewBody(std::string&);
    std::map<std::string, std::string> GetFirst();

    ~Production() {
        for (auto const& x : this->body)
            delete x;
    }
};


#endif //PROYECTOCOMPIS_PRODUCTION_H
