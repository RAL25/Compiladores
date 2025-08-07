#include "ExpressaoMenor.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;
ExpressaoMenor::ExpressaoMenor() { }

void ExpressaoMenor::descobrir_variaveis_usadas(std::vector<std::string>& lista_vars) {
    // Busca recursivamente nos dois lados da expressão
    this->esquerda->descobrir_variaveis_usadas(lista_vars);
    this->direita->descobrir_variaveis_usadas(lista_vars);
}

void ExpressaoMenor::debug_com_tab(int tab) {
  tab3(tab);
  cerr << "< [ INI Menor"<< endl;
  esquerda->debug_com_tab(tab+1);
  tab3(tab);
  cerr << "<" << endl;
  direita->debug_com_tab(tab+1);
  tab3(tab);
  cerr << "< ] FIM Menor"<< endl;
}
