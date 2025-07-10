#pragma once
#include<vector>
#include "ID.hpp"
#include "Tipo.hpp"
#include "Declaracao.hpp"
#include "Comando.hpp"
#include "Parametro.hpp"
#include "../Arvore.hpp"
using namespace std;

class Funcao {
public:
  Tipo* tipo_retorno;
  ID* nome_funcao;

  vector<Parametro*> parametros;
  vector<Declaracao*> declaracoes;
  vector<Comando*> comandos;

  Funcao();
  static Funcao* extrai_funcao(No_arv_parse *arv);
  void debug();
};
