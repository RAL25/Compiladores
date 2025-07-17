#include "Parametro.hpp"
#include "ID.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;

/*
22)parametros -> ID COLON tipov parametro
23)parametros -> v
24)parametro -> SEMICOLON ID COLON tipov parametro
25)parametro -> v
*/

vector<Parametro *> Parametro::extrai_lista_parametros(No_arv_parse* no) {
  // LP
  if (no->regra == 23) return vector<Parametro*>();
  // Tem que ser regra 22.
  vector<Parametro*> res;
  Parametro* aux;
  aux->nome = ID::extrai_ID(no->filhos[0]);
  aux->tipo = Tipo::extrai_tipo(no->filhos[2]);
  res.push_back(aux);
  vector<Parametro*> restante = extrai_lista_par(no->filhos[3]);
  res.insert(res.end(), restante.begin(), restante.end());
  return res;
}

vector<Parametro*> Parametro::extrai_lista_par(No_arv_parse* no) {
  if (no->regra == 25) return vector<Parametro*>();
  // Tem que ser regra 24.
  vector<Parametro*> res;
  Parametro* aux;
  aux->nome = ID::extrai_ID(no->filhos[1]);
  aux->tipo = Tipo::extrai_tipo(no->filhos[3]);
  res.push_back(aux);
  vector<Parametro*> restante = extrai_lista_par(no->filhos[4]);
  res.insert(res.end(), restante.begin(), restante.end());
  return res;
}

void Parametro::debug_com_tab(int tab) {
  tab3(tab);
  cerr << "[" << nome->nome << ":" <<  tipo->nome << "] Parametro Declarada" << endl;
}
