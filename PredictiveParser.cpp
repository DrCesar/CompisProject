//
// Created by WadeOwen on 20-Oct-17.
//

#include "PredictiveParser.h"


PredictiveParser::PredictiveParser(std::map<std::string, Production *> p) {

    this->productions = p;
}

std::map<std::string,std::string> PredictiveParser::First(std::vector<std::string> v) {

    std::map<std::string, std::string> ans, temp;
    int i = 0;
    temp["@"] = "@";
    std::map<std::string, std::string>::iterator it = temp.find("@");

    while (i < v.size() && it != temp.end()) {
        temp = this->productions[v[i]]->GetFirst();

        ans.insert(temp.begin(), temp.end());
        if (i < v.size() - 1)
            ans.erase("@");

        it = temp.find("@");
        i++;
    };

    return ans;
}

std::map<std::string, std::string> PredictiveParser::Follow(std::string s) {

    std::map<std::string, std::string> ans;

    for (auto const& x : this->productions) {
//        for (auto const& y : x.second->GetBody()) {
//            if (y->termsBody[s]. != nullptr)
//
//
//        }
    }
}

