#pragma once
#include "ID.hpp"
#include "../Arvore.hpp"
using namespace std;

class Define {
public:
  ID* tipo;
  ID* nome;
  static vector<Define*> extrai_lista_define(No_arv_parse* no);
  static vector<Define*> extrai_lista_nao_vazia_define(No_arv_parse* no);
  static vector<Define*> extrai_lista_variaveis(No_arv_parse* no);
  static Define* extrai_variavel_P(No_arv_parse* no);
  void debug_com_tab(int tab);
};


