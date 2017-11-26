//
// Created by WadeOwen on 29-Aug-17.
//

#include <stack>
#include "SyntacticTree.h"


SyntacticTree::SyntacticTree(ConvertPostfix p){

    this->end = new Node();
    this->root = new Node();
    std::string s = p.GetPostfix();
    std::cout << s << std::endl;
    s = s + "#.";
    std::stack<Node*> sNode;
    Node* temp1;
    Node* temp2;
    Node* temp3;
    std::string j;
    int cont = 0;

    for (int i = 0; i < s.length(); i++) {

        std::string sTemp(1, s[i]);

        switch (s[i]) {
            case '|':
            case '.':
                temp1 = sNode.top();
                sNode.pop();
                temp2 = sNode.top();
                sNode.pop();
                temp3 = new Node(sTemp, temp1, temp2);
                sNode.push(temp3);
                break;
            case '*':
                temp1 = sNode.top();
                sNode.pop();
                sNode.push( new Node(sTemp, temp1));
                break;
            case '+':
                CopyTree(temp1, sNode.top());
                temp2 = sNode.top();
                sNode.pop();
                sTemp = "*";
                sNode.push( new Node(sTemp, temp2));
                temp2 = sNode.top();
                sNode.pop();
                j = ".";
                sNode.push( new Node(j, temp1, temp2));
                break;
            default:
                temp1 = new Node(sTemp);
                //temp1->SetLPos(temp1);
                //temp1->SetFPos(temp1);
                if (sTemp == "#")
                    this->end = temp1;
                else {
                    this->alfa[sTemp] = sTemp;
                }
                cont++;
                temp1->SetNum(std::to_string(cont));
                sNode.push(temp1);
                break;

        }
    }

    temp1 = sNode.top();
    root = temp1;
    sNode.pop();
}


void SyntacticTree::CopyTree(Node* temp, Node* n){

    temp->SetInfo(n->GetInfo());

    if (n->GetRig() != nullptr) {
        Node* tempRig = new Node();
        temp->SetRig(tempRig);
        CopyTree(tempRig, n->GetRig());
    }

    if (n->GetLef() != nullptr) {
        Node* tempLef = new Node();
        temp->SetLef(tempLef);
        CopyTree(tempLef, n->GetLef());
    }

}

std::map<Node*, Node*> SyntacticTree::GetFolPos(std::map<Node*, Node*> l, std::string& s) {

    std::map<Node*, Node*> res;

    for (auto const& i : l)
        if (i.second->GetInfo() == s) {
            i.second->ToString();
            if (!res.empty())
                res.insert(i.second->GetFolPos().begin(), i.second->GetFolPos().end());
            else
                res = i.second->GetFolPos();
        }
    return res;
}

void SyntacticTree::ToString() {

    if (root != nullptr) {
        std::cout << this->root->GetInfo() << std::endl;
        ToString(root);
    }
}

void SyntacticTree::ToString(Node* n) {

    if (n->GetRig() != nullptr) {
        std::cout << n->GetInfo() << "->" << n->GetRig()->GetInfo() << std::endl;
        ToString(n->GetRig());
    }

    if (n->GetLef() != nullptr) {
        std::cout << n->GetInfo() << "->" << n->GetLef()->GetInfo() << std::endl;
        ToString(n->GetLef());
    }
}