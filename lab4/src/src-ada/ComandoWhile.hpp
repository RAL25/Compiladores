#pragma once
#include "Comando.hpp"
#include "ID.hpp"
#include "Expressao.hpp"
using namespace std;

class ComandoWhile : public Comando {
public:
  Expressao* condicao_while;
  vector<Comando*> corpo_while;
  ComandoWhile();
  void debug_com_tab(int tab);
};
