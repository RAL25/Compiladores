#pragma once
#include "Expressao.hpp"
using namespace std;

class ExpressaoMenor : public Expressao {
public:
  Expressao* esquerda;
  Expressao* direita;
  ExpressaoMenor();
  void descobrir_variaveis_usadas(std::vector<std::string>& lista_vars);
  void debug_com_tab(int tab);
};
