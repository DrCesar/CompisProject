//
// Created by WadeOwen on 20-Oct-17.
//

#include "Production.h"

Production::Production(std::string& h) {

    this->head = h;
}

void Production::NewBoty(std::string &s) {

    Body* tempBody;
    Node* tempNode = new Node(s);

    tempBody->start = tempNode;
    this->body.push_back(tempBody);
}

void Production::AddTermBody(std::string& s) {

    Body* tempBody = this->body.back();
    Node* tempNode = new Node(s);

    tempBody->end->next = tempNode;
    tempBody->end = tempNode;

    tempBody->termsBody[s].push_back(tempNode);
}

std::map<std::string, std::string> Production::GetFirst() {

    std::map<std::string,std::string> ans;

    for (Body* n : this->body) {
        ans[n->start->info] = n->start->info;
    }

    return ans;
}




