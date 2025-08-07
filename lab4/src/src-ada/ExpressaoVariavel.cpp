#include "ExpressaoVariavel.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;
ExpressaoVariavel::ExpressaoVariavel() { }

void ExpressaoVariavel::descobrir_variaveis_usadas(std::vector<std::string>& lista_vars) {
    // Encontramos uma variável, adicione seu nome à lista.
    lista_vars.push_back(this->nome->nome);
}

void ExpressaoVariavel::debug_com_tab(int tab) {
  tab3(tab);
  cerr << "VAR[" << nome->nome << "]" << endl;
}
