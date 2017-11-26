//
// Created by WadeOwen on 13-Sep-17.
//

#include "LexerScanner.h"


LexerScanner::LexerScanner(std::string s) {

    this->initialP = nullptr;
    this->file.open(s);
    SetNextLine();

    while (this->currentLine.find("PRODUCTIONS") == std::string::npos)
        SetNextLine();

    SetNextLine();
    ProductionScanner();

}


void LexerScanner::ProductionScanner() {


    while (!file.eof()) {
        CreateProduction();
        SetNextLine();
    }

    file.close();
}

void LexerScanner::CreateProduction() {


    Production* p;
    Symbol* s;
    Symbol* bodyElement;
    std::string head = GetNextElement();
    std::string element;
    bool newProduction = false;
    bool EOL = false;

    if (head != "") {

        if ((s = this->symbols[head]) == nullptr) {
            s = new Symbol(head, false);
            this->symbols[head] = s;
        } else
            s->SetTerminal(false);

        p = new Production(s);
        this->productions[s].push_back(p);

        if (GetNextElement() == "=") {
            while ((element = GetNextElement()) != "." && !EOL) {
                if (element == "|") {
                    element = GetNextElement();
                    newProduction = true;
                }

                if ((bodyElement = this->symbols[element]) == nullptr) {
                    bodyElement = new Symbol(element, true);
                    this->symbols[element] = bodyElement;
                }

                //this->productions[element] = bodyElement;
                if (newProduction) {
                    p = new Production(s);
                    this->productions[s].push_back(p);
                }

                p->AddTermBody(bodyElement);
                this->belongProductions[bodyElement].push_back(p);

                newProduction = false;
                EOL = IsEndOfLine();
            }

            if (this->initialP == nullptr) {
                Production *pTemp = new Production(new Symbol(p->GetHead()->GetInfo() + "'", false));
                Symbol *end = new Symbol("$", true);

                pTemp->AddTermBody(p->GetHead());
                pTemp->AddTermBody(end);

                this->belongProductions[p->GetHead()].push_back(pTemp);
                this->belongProductions[end].push_back(pTemp);

                this->productions[pTemp->GetHead()].push_back(pTemp);

                this->symbols[pTemp->GetHead()->GetInfo()] = pTemp->GetHead();
                this->symbols[end->GetInfo()] = end;

                this->initialP = pTemp;
            }
        } else {
            std::cout << "Error en linea" << std::endl;
        }
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

    return ans;
}


std::string LexerScanner::SetNextLine() {

    std::getline(this->file, this->currentLine);

    this->countCurrent = 0;

    return this->currentLine;
}

bool LexerScanner::IsEndOfLine() {
    return this->countCurrent == this->currentLine.length();
}

std::vector<Symbol*> LexerScanner::LexeTokens(std::string input) {

    std::string token = "";
    std::string error = "";
    std::vector<Symbol*> output;
    int i = 0;

    input = input + " $";

    while (i < input.length() && error == "") {
        token = "";
        while (i < input.length() && input[i] != ' ') {
            token = token + input[i];
            i++;
        }

        if (this->symbols.find(token) != this->symbols.end()) {
            output.push_back(this->symbols[token]);
        } else {
            error = "Ingreso un token inexistente";
            std::cout << error << std::endl;
        }
        i++;
    }

    return output;
}
