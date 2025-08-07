#pragma once
#include "Comando.hpp"
#include "ID.hpp"
#include "Expressao.hpp"
using namespace std;

class ComandoExpressao : public Comando {
public:
  Expressao* expressao_arit;
  ComandoExpressao();
  void debug_com_tab(int tab);
};
