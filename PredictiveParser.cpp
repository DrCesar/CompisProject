//
// Created by WadeOwen on 20-Oct-17.
//

#include "PredictiveParser.h"


PredictiveParser::PredictiveParser(std::map<std::string, Production *> p) {

    this->productions = p;
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



