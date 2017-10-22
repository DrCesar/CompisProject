//
// Created by WadeOwen on 13-Sep-17.
//

#include "LexerScanner.h"


LexerScanner::LexerScanner(std::string s) {

    this->file.open(s);

    while (this->currentLine.find("PRODUCTIONS") != std::string.npos)
        GetNextLine();

    ProductionScanner();

    file.close();
}


std::map<Production*, Production*> LexerScanner::ProductionScanner() {

    int counter = 0;




}

Production* LexerScanner::GetProduction() {

    GetNextLine();

    Production* p;
    Production* bodyElement;
    std::string head = GetNextElement();
    std::string element;

    if ((p = this->productions[head]) == nullptr)
        p = new Production(head);

    if (GetNextElement() == "=") {
        while ((element = GetNextElement()) != "") {
            if ((bodyElement = this->productions[element]) == nullptr)
                bodyElement = new Production(element);

            this->productions[element] = bodyElement;


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

    return ans;
}


std::string LexerScanner::GetNextLine() {

    std::getline(this->file, this->currentLine);

    return this->currentLine;
}
