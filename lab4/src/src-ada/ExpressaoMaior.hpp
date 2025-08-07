#pragma once
#include "Expressao.hpp"
using namespace std;

class ExpressaoMaior : public Expressao {
public:
  Expressao* esquerda;
  Expressao* direita;
  ExpressaoMaior();
  void descobrir_variaveis_usadas(std::vector<std::string>& lista_vars);
  void debug_com_tab(int tab);
};
