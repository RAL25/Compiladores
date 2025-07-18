#pragma once
#include "ID.hpp"
#include "Tipo.hpp"
#include "Expressao.hpp"
#include "../Arvore.hpp"
using namespace std;

class Declaracao {
public:
  Tipo* tipo;
  ID* nome;
  Expressao* valor_ini;
  static vector<Declaracao*> extrai_lista_declaracoes(No_arv_parse* no);
  static Expressao* extrai_atra(No_arv_parse* no);
  void debug_com_tab(int tab);
};
