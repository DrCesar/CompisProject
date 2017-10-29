//
// Created by WadeOwen on 20-Oct-17.
//

#include "PredictiveParser.h"


PredictiveParser::PredictiveParser(std::map<std::string, Production *> p) {

    this->productions = p;
}

void PredictiveParser::CreateAutomaton(){

    struct DStateList {

        static DState* GetMarked(std::map<DState*, DState*> l) {

            for (auto const x: l) {
                if (!x.second->GetMarked())
                    return x.second;
            }
            return nullptr;
        }

        static bool AddTransition(DState* e, DState* marked, std::map<DState*, DState*>& l, Symbol s) {

            for (const auto x : l){
                if (x.second->GetProdList() == e->GetProdList()) {
                    marked->AddTransitionS(x.second, s);
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

    e = Closure(new DState(this->initial));
    e->SetStart(true);
    e->SetNum(std::to_string(++cont));
    this->automat->GetStates()[e] = e;
    this->start = e;

    while ((marked = DStateList::GetMarked(this->automat->GetStates()))) {
        marked->SetMarked(true);
        for (auto const x : marked->GetProdList()) {
            s = x.second;
            temp = t.GetFolPos(marked->GetNodeList(), s);
            e = new DState(temp);
            if (!DStateList::AddTransition(e, marked, this->states, s)) {
                e->SetNum(std::to_string(++cont));
                this->automat->GetStates()[e] = e;
                marked->AddTransition(e, s);
            }
        }
    }

    delete e;
    delete marked;


}


std::map<std::string, Production*> PredictiveParser::First(Production* p) {

    std::vector<std::string> v;

    v.push_back(p->GetHead());

    return First(v);
}

std::map<std::string, Production*> PredictiveParser::First(std::vector<std::string> v) {

    std::map<std::string, Production*> ans, temp;
    bool b = true;
    int i = 0;

    do {
        if (this->productions[v[i]] != nullptr) {
            temp = this->productions[v[i]]->GetFirst();

            ans.insert(temp.begin(), temp.end());
            if (i < v.size() - 1)
                ans.erase("#");

            i++;
        } else
            b = false;
    } while (temp["#"] != nullptr && i < v.size() && b);

    return ans;
}

std::map<std::string, Production*> PredictiveParser::Follow(std::string s) {

    std::map<std::string, Production*> ans, temp, follow;
    Production* end;
    Production* x = this->productions[s];

    for (auto const& p : x->GetBelongBodys()) {
        for (auto const &b : p.second->GetBody())
            for (auto const &n : b->termsBody[x->GetHead()]) {
                if (n->next == nullptr) {
                    if (p.second->GetHead() == x->GetHead())
                        temp = x->GetFirst();
                    else
                        temp = Follow(p.second->GetHead());
                    follow.insert(temp.begin(), temp.end());
                } else
                    follow[n->next->GetSymbol()] = n->next->p;
            }
    }

    for (auto const& p : follow) {
        temp = First(p.second);
        ans.insert(temp.begin(), temp.end());
    }

    if (ans["#"] != nullptr){
        end = new Production("$", true);
        ans["$"] = end;
        ans.erase("#");
    }

    return ans;
}



