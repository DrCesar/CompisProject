//
// Created by WadeOwen on 20-Oct-17.
//

#include "Production.h"

Production::Production(std::string h) {

    this->head = h;
    this->isTerminal = false;
}

Production::Production(std::string h, bool b) {

    this->head = h;
    this->isTerminal = b;
}

void Production::NewBody(Production* p) {

    Body* tempBody = new Body();
    Node* tempNode = new Node(p);

    tempBody->start = tempNode;
    tempBody->end = tempNode;
    this->body.push_back(tempBody);

    p->AddBelongProduction(this);
}

void Production::AddTermBody(Production* p) {

    if (this->body.back() != nullptr) {
        Body *tempBody = this->body.back();
        Node *tempNode = new Node(p);

        tempBody->end->next = tempNode;
        tempBody->end = tempNode;

        tempBody->termsBody[p->GetHead()].push_back(tempNode);
        p->AddBelongProduction(this);
    } else
        NewBody(p);
}

void Production::AddBelongProduction(Production* p) {

    this->belongProductions[p] = p;
}

std::map<std::string, Production*> Production::GetFirst() {

    std::map<std::string, Production*> ans, temp;

    if (this->isTerminal)
        ans[this->head] = this;
    else
        for (Body* n : this->body) {
            if (n->start->p->GetIsTerminal())
                ans[n->start->GetSymbol()] = n->start->p;
            else {
                temp = n->start->p->GetFirst();
                ans.insert(temp.begin(), temp.end());
            }
        }

    return ans;
}

std::map<std::string, Production*> Production::GetFollow() {

    std::map<std::string, Production*> ans, temp;

    for (auto const& p : this->belongProductions) {
        for (auto const &b : p.second->body)
            for (auto const &n : b->termsBody[this->head]) {
                if (n->next == nullptr) {
                    if (p.second->GetHead() == this->GetHead())
                        temp = this->GetFirst();
                    else
                        temp = p.second->GetFollow();
                    ans.insert(temp.begin(), temp.end());
                } else
                    ans[n->next->GetSymbol()] = n->next->p;
            }
    }
    return ans;
}


void Production::Print() {

    for (auto const& b : this->body) {
        std::cout << this->head << " = ";

        Node* n = b->start;
        while (n != nullptr) {
            std::cout << n->GetSymbol() << " ";
            n = n->next;
        }

        std::cout << std::endl;
    }
}


