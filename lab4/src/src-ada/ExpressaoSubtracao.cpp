#include "ExpressaoSubtracao.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;
ExpressaoSubtracao::ExpressaoSubtracao() { }

void ExpressaoSubtracao::descobrir_variaveis_usadas(std::vector<std::string>& lista_vars) {
    // Busca recursivamente nos dois lados da expressão
    this->esquerda->descobrir_variaveis_usadas(lista_vars);
    this->direita->descobrir_variaveis_usadas(lista_vars);
}

void ExpressaoSubtracao::debug_com_tab(int tab) {
  tab3(tab);
  cerr << "- [ INI Subtracao"<< endl;
  esquerda->debug_com_tab(tab+1);
  tab3(tab);
  cerr << "-" << endl;
  direita->debug_com_tab(tab+1);
  tab3(tab);
  cerr << "- ] FIM Subtracao"<< endl;
}
