//
// Created by WadeOwen on 20-Oct-17.
//

#include "SLR.h"


SLR::SLR(std::map<Symbol*, std::list<Production*>> p) {

    this->productions = p;

}

SLR::SLR(std::map<Symbol*, std::list<Production*>> p, std::map<Symbol*, std::list<Production*>> b, std::map<std::string, Symbol*> s) {

    this->productions = p;
    this->belongProductions = b;
    this->symbols = s;
}

SLR::SLR(std::map<Symbol*, std::list<Production*>> p, std::map<std::string, Symbol*> s) {

    this->productions = p;
    this->symbols = s;
}

void SLR::CreateAutomaton(){


    State* e;
    State* marked;
    std::list<Node<Symbol*>*> itemList;
    Symbol* s;

    e = new State(Closure(new KernelItem(this->initial)));
    this->automat = AutomatonP(e);

    while ((marked = this->automat.GetMarked())) {
        marked->SetMarked(true);
        for (auto const x : marked->GetNodeList()) {
                e = Goto(marked, x.second);
                if (e != nullptr)
                    marked->AddTransition(x.first, e);
            }
    }
}

std::map<Node<Symbol*>*, KernelItem*> SLR::Closure(KernelItem*  k) {

    std::map<Node<Symbol*>*, KernelItem*> temp;
    temp[k->GetPointer()] = k;

    return Closure(temp);
}

std::map<Node<Symbol*>*, KernelItem*>  SLR::Closure(std::map<Node<Symbol*>*, KernelItem*>  l) {

    std::map<Node<Symbol*>*, KernelItem*>  ans;

    if (l.size() != 0) {

        ans.insert(l.begin(), l.end());

        for (auto const &item : l)
            if (item.first != nullptr)
                if(!item.first->GetInfo()->IsTerminal())
                    for (auto const &prod : this->productions[item.first->GetInfo()])
                        ans[prod->GetStart()] = new KernelItem(prod);


        if (ans.size() != l.size())
            return Closure(ans);
    }

    return ans;

};

State* SLR::Goto(State* d, std::list<Node<Symbol*>*> nodeList) {

    std::map<Node<Symbol*>*, KernelItem*> temp;
    State* ans = nullptr;
    SR item;

    for(auto const& node : nodeList)
        if (node != nullptr && node->GetInfo()->GetInfo() != "END" && node->GetInfo()->GetInfo() != "$")
            temp[node->GetNext()] = new KernelItem(d->GetItemList()[node]->GetProduction(), node->GetNext());

    if (temp.size() != 0)
        ans = this->automat.AddState(new State(Closure(temp)));

    for (auto const& node : nodeList)
        if (node->GetInfo()->GetInfo() == "END") {
            item = SR(d->GetProdList()[node]);
            std::map<std::string, Symbol*> fol = Follow(d->GetProdList()[node]->GetHead());
            for (auto const& sym : fol)
                if (this->parserTable[d].find(sym.second) == this->parserTable[d].end())
                    this->parserTable[d][sym.second] = item;
                else
                    std::cout << "Problema Shift/Reduce en el estado " << std::to_string(d->GetNum()) << ". Con el simbolo " << node->GetInfo()->GetInfo() << std::endl;
        } else {
            if (node->GetInfo() ->GetInfo() == "$") {
                item = SR("Accept");
                this->parserTable[d][node->GetInfo()] = item;
            } else {
                item = SR(ans);
                if (this->parserTable[d].find(node->GetInfo()) == this->parserTable[d].end())
                    this->parserTable[d][node->GetInfo()] = item;
                else
                    std::cout << "Problema Reduce/Reduce en el estado " << std::to_string(d->GetNum()) << ". Con el simbolo " << node->GetInfo()->GetInfo() << std::endl;
            }
        }


    return ans;
}


std::map<std::string, Symbol*> SLR::First(Symbol* p) {

    std::list<Symbol*> v;

    v.push_back(p);

    return First(v);
}

std::map<std::string, Symbol*> SLR::First(std::list<Symbol*> v) {

    std::map<std::string, Symbol*> ans, temp;
    Symbol* s;

    do {
        ans.erase("@");
        s = v.front();
        v.pop_front();
        if (s != nullptr) {
            if (s->IsTerminal())
                ans[s->GetInfo()] = s;
            else
                for (auto const &x: this->productions[s])
                    if (x->GetStart()->GetInfo() != s) {
                        temp = First(x->GetStart()->GetInfo());
                        ans.insert(temp.begin(), temp.end());
                    }
        }
    } while (ans.find("@") != ans.end() && v.size() > 0);

    if (!ans["@"])
        ans.erase("@");


    return ans;
}

std::map<std::string, Symbol*> SLR::Follow(Symbol* s) {

    std::map<std::string, Symbol*> ans, temp;

    if (s == this->initial->GetHead())
        ans["$"] = this->symbols["$"];

    for (auto const& prod : this->belongProductions[s]) {
        std::list<Node<Symbol *> *> list = prod->GetBody()[s];
        for (auto const &node: list) {
            if (node->GetNext() == nullptr || node->GetNext()->GetInfo()->GetInfo() == "END") {
                if (node->GetInfo() != prod->GetHead())
                    temp = Follow(prod->GetHead());
            } else
                temp = First(node->GetNext()->GetInfo());
            ans.insert(temp.begin(), temp.end());
        }
    }

    return ans;
}

void SLR::SetInitialProduction(Production* p) {

    this->initial = p;
}

void SLR::CreateParserTable() {


}

void SLR::Parse(std::vector<Symbol*> input) {

    std::stack<State*> stack;
    std::vector<Symbol*> syms;
    stack.push(this->automat.GetStart());
    SR item = SR("Initial");

    std::cout << "Stack \t\t\t Symbols \t\t Input \t\t\t Action" << std::endl;
    while (input.size() > 0 && item.info != "Accept") {
        item = this->parserTable[stack.top()][input.front()];

        this->PrintParser(stack, syms, input, item);
        if (item.info == "Shift") {
            syms.push_back(input.front());
            input.erase(input.begin());

            stack.push(item.stat);
        } else {
            if (item.info == "Reduce") {
                while (syms.size() > 0 && syms.back() != item.prod->GetStart()->GetInfo())
                    syms.pop_back();

                if (syms.size() > 0)
                    syms.pop_back();
                syms.push_back(item.prod->GetHead());

                while (stack.size() > 1 && this->parserTable[stack.top()].find(item.prod->GetHead()) ==
                                           this->parserTable[stack.top()].end())
                    stack.pop();

                SR temp = this->parserTable[stack.top()][item.prod->GetHead()];

                stack.push(temp.stat);
            }
        }
    }
    std::cout << "end" <<std::endl;
}

void SLR::PrintParser(std::stack<State *> st, std::vector<Symbol *> sym, std::vector<Symbol *> in, SR it) {

    std::string stack, symbl, input, item;

    stack = "";
    while (st.size() > 0) {
        State* s = st.top();
        st.pop();
        stack = std::to_string(s->GetNum()) + " " + stack;
    }

    symbl = "";
    for (Symbol* s : sym)
        symbl = symbl + " " + s->GetInfo();

    input = "";
    for (Symbol* s : in)
        input = input + " " + s->GetInfo();

    item = it.info;
    if (it.info == "Reduce")
        item = item + " " + it.prod->ToString();

    std::cout << stack << "\t\t\t" << symbl << "\t\t" << input << "\t\t\t" << item << "\t\t" << std::endl;
    //std::printf("\t%s \t%s \t%s \t%s", stack, symbl, input, item);
}

void SLR::PrintTable() {

    std::string s = "  ";
    std::map<Symbol*, SR> x;

    for (auto const& sym : this->symbols)
        s = s + "\t" + sym.second->GetInfo();
    std::cout << s << std::endl;

    for (auto const& state : this->automat.GetStates()) {
        s = std::to_string(state.second->GetNum());

        for (auto const& sym : this->symbols) {
            if (this->parserTable[state.second].find(sym.second) != this->parserTable[state.second].end()) {
                s = s + "\t" + this->parserTable[state.second][sym.second].info[0];
                if (this->parserTable[state.second][sym.second].info == "Shift")
                    s = s + std::to_string(this->parserTable[state.second][sym.second].stat->GetNum());
            } else
                s = s + " \t-";
        }

        std:: cout << s << std::endl;
    }

}



