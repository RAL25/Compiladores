#ifndef _EXPRESSAO_VARIAVEL_HPP_
#define _EXPRESSAO_VARIAVEL_HPP_
#include "Expressao.hpp"
#include "ID.hpp"
using namespace std;

class ExpressaoVariavel : public Expressao {
public:
  ID* nome;
  ExpressaoVariavel();
  void descobrir_variaveis_usadas(std::vector<std::string>& lista_vars);
  void debug_com_tab(int tab);
};

#endif
