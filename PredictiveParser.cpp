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
    int i = 0;

    do {
        temp = this->productions[v[i]]->GetFirst();

        ans.insert(temp.begin(), temp.end());
        if (i < v.size() - 1)
            ans.erase("#");

        i++;
    } while (temp["#"] != nullptr && i < v.size());

    return ans;
}

std::map<std::string, Production*> PredictiveParser::Follow(std::string s) {

    std::map<std::string, Production*> ans, temp;
    Production* p = this->productions[s];

    std::map<std::string, Production*> follow = p->GetFollow();

    for (auto const& p : follow) {
        temp = First(p.second);
        ans.insert(temp.begin(), temp.end());
    }

    return ans;
}



