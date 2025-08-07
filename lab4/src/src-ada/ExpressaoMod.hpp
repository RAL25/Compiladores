#ifndef _EXPRESSAO_MOD_HPP_
#define _EXPRESSAO_MOD_HPP_
#include "Expressao.hpp"
using namespace std;

class ExpressaoMod : public Expressao {
public:
  Expressao* esquerda;
  Expressao* direita;
  ExpressaoMod();
  void descobrir_variaveis_usadas(std::vector<std::string>& lista_vars);
  void debug_com_tab(int tab);
};

#endif
