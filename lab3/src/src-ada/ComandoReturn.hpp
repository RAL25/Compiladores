#pragma once
#include "Comando.hpp"
#include "ID.hpp"
#include "Expressao.hpp"
using namespace std;

class ComandoReturn : public Comando {
public:
  vector<Comando*> retorno_comandos;
  ComandoReturn();
  void debug_com_tab(int tab);
};
