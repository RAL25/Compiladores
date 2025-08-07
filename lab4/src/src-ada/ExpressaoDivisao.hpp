#ifndef _EXPRESSAO_DIVISAO_HPP_
#define _EXPRESSAO_DIVISAO_HPP_
#include "Expressao.hpp"
using namespace std;

class ExpressaoDivisao : public Expressao {
public:
  Expressao* esquerda;
  Expressao* direita;
  ExpressaoDivisao();
  void descobrir_variaveis_usadas(std::vector<std::string>& lista_vars);
  void debug_com_tab(int tab);
};

#endif
