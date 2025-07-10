#include "Parametro.hpp"
#include "ID.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;

/*
19)param -> ID COLON tipov par
20)param -> v
21)par -> SEMICOLON ID COLON tipov par
22)par -> v*/

vector<Parametro *> Parametro::extrai_lista_parametros(No_arv_parse* no) {
  // LP
  if (no->regra == 20) return vector<Parametro*>();
  // Tem que ser regra 19.
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
  if (no->regra == 22) return vector<Parametro*>();
  // Tem que ser regra 21.
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
