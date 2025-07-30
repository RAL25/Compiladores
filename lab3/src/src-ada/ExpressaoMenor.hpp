#pragma once
#include "Expressao.hpp"
using namespace std;

class ExpressaoMenor : public Expressao {
public:
  Expressao* esquerda;
  Expressao* direita;
  ExpressaoMenor();
  void debug_com_tab(int tab);
};
