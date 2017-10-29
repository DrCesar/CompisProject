//
// Created by WadeOwen on 12-Sep-17.
//

#include "Automaton.h"

Automaton::Automaton(std::string& s, bool op = true) {

    
}

Automaton::Automaton(SyntacticTree& t) {

   CreateAutomaton(t);
}

void Automaton::CreateAutomaton(SyntacticTree &t) {

    struct DStateList {

        static DState* GetMarked(std::map<DState*, DState*> l) {

            for (auto const x: l) {
                if (!x.second->GetMarked())
                    return x.second;
            }
            return nullptr;
        }

        static bool AddTransition(DState* e, DState* marked, std::map<DState*, DState*>& l, std::string& s) {

            for (const auto x : l){
                if (x.second->GetNodeList() == e->GetNodeList()) {
                    marked->AddTransition(x.second, s);
                    return true;
                }
            }
            return false;
        }
    };


    std::map<Node*, Node*> temp;
    DState* e;
    DState* marked;
    std::string s;
    int cont = 0;

    e = new DState(t.GetRoot()->GetFPos());
    e->SetStart(true);
    e->SetNum(std::to_string(++cont));
    this->states[e] = e;
    this->alfa = t.GetAlfa();
    this->start = e;

    while ((marked = DStateList::GetMarked(this->states))) {
        marked->SetMarked(true);
        for (auto const x : this->alfa) {
            s = x.second;
            temp = t.GetFolPos(marked->GetNodeList(), s);
            e = new DState(temp);
            if (!DStateList::AddTransition(e, marked, this->states, s)) {
                e->SetNum(std::to_string(++cont));
                this->states[e] = e;
                Node* x = e->GetNodeList()[t.GetEnd()];
                if (e->GetNodeList()[t.GetEnd()] != nullptr) {
                    e->SetEnd(true);
                    this->end[e] = e;
                }
                marked->AddTransition(e, s);
            }
        }
    }

    delete e;
    delete marked;
}



std::map<DState*, DState*> Automaton::Move(std::map<DState *, DState *>& l, std::string& s) {

    std::map<DState*, DState*> res;
    DState* e;

    for (auto const x : l) {
        if (x.second->GetTransition().find(s) != x.second->GetTransition().end())
            res[x.second] = x.second;
    }

    return res;
}


bool Automaton::Simulate(std::string &s) {

    std::map<DState *, DState *> res;
    res[this->start] = this->start;

    for (char &c : s) {
        std::string temp(1,c);
        res = Move(res, temp);
    }

    for (auto const x : this->end) {
        if (res.find(x.second) != res.end())
            return true;
    }

    return false;
}


void Automaton::ToString() {

    for (auto const& y : this->states) {
        DState* e = y.second;
        if (e->GetStart())
            std::cout << " START ";
        if (e->GetEnd())
            std::cout << " END ";
        std::cout << "[ " << e->GetNum() << " {";
        for (auto const& x : e->GetTransition()) {
            std::cout << x.second->GetNum() << "(" << x.first << ")" << " ";
        }
        std::cout << "}]" << std::endl;
    }
}


