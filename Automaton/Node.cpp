//
// Created by WadeOwen on 29-Aug-17.
//

#include "Node.h"

Node::Node() {

    this->info = "";
    this->rig = nullptr;
    this->lef = nullptr;
}

Node::Node(std::string s) {
    this->info = s;

    if (s != "@")
        this->nulla = false;
    else
        this->nulla = true;

    this->fPos[this] = this;
    this->lPos[this] = this;
    this->rig = nullptr;
    this->lef = nullptr;
}

Node::Node(std::string& s, Node* rig) {

    this->info = s;
    this->rig = rig;
    this->nulla = true;

    this->fPos = rig->GetFPos();
    this->lPos = rig->GetLPos();

    for (auto const& i : this->GetLPos())
            i.second->SetFolPos(MergeMap(i.second->GetFolPos(), this->GetFPos()));

}


Node::Node(std::string& s, Node* rig, Node* lef) {

    this->info = s;
    this->rig = rig;
    this->lef = lef;

    if (s == "|"){

        this->nulla = this->rig->GetNulla() || this->lef->GetNulla();

        this->fPos = MergeMap(this->rig->GetFPos(), this->lef->GetFPos());
        this->lPos = MergeMap(this->rig->GetLPos(), this->lef->GetLPos());

    } else {

        this->nulla = this->rig->GetNulla() && this->lef->GetNulla();

        if(this->lef->GetNulla())
            this->fPos = MergeMap(this->rig->GetFPos(), this->lef->GetFPos());
        else
            this->fPos = this->lef->GetFPos();

        if (this->rig->GetNulla())
            this->lPos = MergeMap(this->rig->GetLPos(), this->lef->GetLPos());
        else
            this->lPos = this->rig->GetLPos();

        for (auto const& i : this->lef->GetLPos()) {
            if (i.second != nullptr)
                i.second->SetFolPos( MergeMap(i.second->GetFolPos(), this->rig->GetFPos()));
        }

    }
}

std::map<Node*, Node*> Node::MergeMap(std::map<Node*, Node*> l1, std::map<Node*, Node*> l2) {

    l1.insert(l2.begin(), l2.end());

    return l1;
}

void Node::ToString() {

    std::cout << this->info;
    
}

Node::~Node() {
    if (this->rig != nullptr)
        delete this->rig;
    if (this->lef != nullptr)
        delete this->lef;
    /*for (std::map<Node*, Node*>::iterator i = this->fPos.begin(); i != this->fPos.end(); i++)
        delete i->second;
    for (std::map<Node*, Node*>::iterator i = this->lPos.begin(); i != this->lPos.end(); i++)
        delete i->second;
    for (std::map<Node*, Node*>::iterator i = this->folPos.begin(); i != this->folPos.end(); i++)
        delete i->second;*/
}