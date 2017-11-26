//
// Created by WadeOwen on 29-Aug-17.
//

#ifndef PROYECTOCOMPIS_SYNTACTICTREE_H
#define PROYECTOCOMPIS_SYNTACTICTREE_H

#include "Node.h"
#include "ConvertPostfix.h"

class SyntacticTree {

private:
    Node* root;
    Node* end;
    std::map<std::string, std::string> alfa;

public:

    SyntacticTree(ConvertPostfix);

    void SetRoot(Node* n){ this->root = n; }
    void SetEnd(Node* n){ this->end = n; }
    Node* GetRoot(){ return this->root; }
    Node* GetEnd(){ return this->end; }
    std::map<std::string, std::string> GetAlfa(){ return this->alfa; }

    std::map<Node*, Node*> GetFolPos(std::map<Node*, Node*>, std::string&);
    void ToString();
    void ToString(Node*);

    void CopyTree(Node*, Node*);
    ~SyntacticTree(){
        delete root;
    }

};


#endif //PROYECTOCOMPIS_SYNTACTICTREE_H
