#include "ComandoIF.hpp"
#include <iostream>
#include "../debug-util.hpp"
using namespace std;

ComandoIF::ComandoIF() {
  
}

void ComandoIF::calcular_max_params_saida(int& max_atual) {
    this->condicao_if->calcular_max_params_saida(max_atual);
    for (Comando* cmd : this->corpo_if) {
        cmd->calcular_max_params_saida(max_atual);
    }
    // ... etc para else/elsif ...
}

void ComandoIF::debug_com_tab(int tab) {
  tab3(tab);
  cerr << "INI IF: " << /* << " = " */ endl;
  condicao_if->debug_com_tab(tab+1);
  for (int iv = 0; iv < corpo_if.size(); ++iv) {
    corpo_if[iv]->debug_com_tab(tab+1);
  }
  tab3(tab);
  cerr << "FIM IF" << endl;
  cerr << endl;
  // cerr<<"ComandoIF"<<endl;
}
