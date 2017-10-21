//
// Created by WadeOwen on 29-Aug-17.
//

#ifndef PROYECTOCOMPIS_NODE_H
#define PROYECTOCOMPIS_NODE_H

#include <iostream>
#include <map>
#include <list>


class Node {
    Node *rig;
    Node *lef;
    bool nulla;
    std::string info;
    std::string num;
    std::map<Node*, Node*> fPos;
    std::map<Node*, Node*> lPos;
    std::map<Node*, Node*> folPos;


public:
    Node();
    Node(std::string);
    Node(std::string&, Node*);
    Node(std::string&, Node*, Node*);


    Node* GetRig(){ return rig; }
    Node* GetLef(){ return lef; }
    bool GetNulla(){ return nulla; }
    std::string GetNum(){ return this->num; }
    std::string GetInfo(){ return this->info; }

    std::map<Node*, Node*> GetFPos(){ return fPos; }
    std::map<Node*, Node*> GetLPos(){ return lPos; }
    std::map<Node*, Node*> GetFolPos(){ return folPos; }

    void SetFPos(Node* n){ this->fPos[n] = n;}
    void SetLPos(Node* n){ this->lPos[n] = n;}
    void SetFolPos(std::map<Node*, Node*> l){ this->folPos = l; }
    void SetInfo(std::string s){ this->info = s; }
    void SetRig(Node* n){ this->rig = n; }
    void SetLef(Node* n){ this->lef = n; }
    void SetNum(std::string s){ this->num = s; }

    std::map<Node*, Node*> MergeMap(std::map<Node*, Node*>, std::map<Node*, Node*>);
    void ToString();

    ~Node();


};


#endif //PROYECTOCOMPIS_NODE_H
