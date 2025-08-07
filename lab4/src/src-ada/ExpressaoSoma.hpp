#ifndef _EXPRESSAO_SOMA_HPP_
#define _EXPRESSAO_SOMA_HPP_
#include "Expressao.hpp"
using namespace std;

class ExpressaoSoma : public Expressao {
public:
  Expressao* esquerda;
  Expressao* direita;
  ExpressaoSoma();
  void descobrir_variaveis_usadas(std::vector<std::string>& lista_vars);
  void debug_com_tab(int tab);
};

#endif
