#pragma once
#include "ID.hpp"
#include "Tipo.hpp"
#include "../Arvore.hpp"
using namespace std;

class Parametro {
public:
  Tipo* tipo;
  ID* nome;
  static vector<Parametro*> extrai_lista_parametros(No_arv_parse* no);
  static vector<Parametro*> extrai_lista_par(No_arv_parse* no);
  void debug_com_tab(int tab);
};
