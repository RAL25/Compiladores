#pragma once
#include<vector>
#include "ID.hpp"
#include "Variavel.hpp"
#include "Comando.hpp"
#include "../Arvore.hpp"
using namespace std;

class Funcao {
public:
  ID* tipo_retorno;
  ID* nome_funcao;
  vector<Variavel*> parametros;
  vector<Variavel*> variaveis;
  vector<Comando*> comandos;

  Funcao();
  static Funcao* extrai_funcao(No_arv_parse *arv);
  void debug();
};

class Procedure {
public:
  static Procedure* Procedure::extrai_procedure(No_arv_parse *arv);
};
