#pragma once
#include "Comando.hpp"
#include "ID.hpp"
#include "Expressao.hpp"
using namespace std;

struct ClausulaElsif {
  Expressao* condicao;
  vector<Comando*> corpo;
};

class ComandoIF : public Comando {
public:
  Expressao* condicao_if;
  vector<Comando*> corpo_if;
  vector<ClausulaElsif*> clausulasElsif;
  vector<Comando*> corpo_else;
  ComandoIF();
  void calcular_max_params_saida(int& max_atual);
  void debug_com_tab(int tab);
};
