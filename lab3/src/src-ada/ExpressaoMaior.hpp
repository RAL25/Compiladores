#pragma once
#include "Expressao.hpp"
using namespace std;

class ExpressaoMaior : public Expressao {
public:
  Expressao* esquerda;
  Expressao* direita;
  ExpressaoMaior();
  void debug_com_tab(int tab);
};
