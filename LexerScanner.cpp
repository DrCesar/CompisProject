//
// Created by WadeOwen on 13-Sep-17.
//

#include "LexerScanner.h"


LexerScanner::LexerScanner(std::string s) {

    this->file.open(s);

    while (this->currentLine.find("PRODUCTIONS") != std::string::npos)
        GetNextLine();

    ProductionScanner();

}


void LexerScanner::ProductionScanner() {


    while (!file.eof())
        CreateProduction();

    file.close();

    for (auto const& p : this->productions)
        p.second->Print();
}

void LexerScanner::CreateProduction() {

    GetNextLine();


    Production* p;
    Production* bodyElement;
    std::string head = GetNextElement();
    std::string element;
    bool newBody = true;

    if ((p = this->productions[head]) == nullptr) {
        p = new Production(head, false);
        this->productions[head] = p;
    } else
        p->SetIsterminal(false);

    if (GetNextElement() == "=") {
        while ((element = GetNextElement()) != ".") {
            if (element == "|") {
                element = GetNextElement();
                newBody = true;
            }

            if ((bodyElement = this->productions[element]) == nullptr)
                bodyElement = new Production(element, true);

            this->productions[element] = bodyElement;
            if (newBody)
                p->NewBody(bodyElement);
            else
                p->AddTermBody(bodyElement);

            newBody = false;
        }
    } else {
        std::cout << "Error en linea" << std::endl;
    }
}

std::string LexerScanner::GetNextElement() {

    std::string ans = "";

    while (this->countCurrent < this->currentLine.length() && this->currentLine[this->countCurrent] == ' ')
        this->countCurrent++;

    while (this->countCurrent < this->currentLine.length() && this->currentLine[this->countCurrent] != ' ') {
        ans = ans + this->currentLine[this->countCurrent];
        this->countCurrent++;
    }

    ;
    return ans;
}


std::string LexerScanner::GetNextLine() {

    std::getline(this->file, this->currentLine);

    this->countCurrent = 0;

    return this->currentLine;
}
