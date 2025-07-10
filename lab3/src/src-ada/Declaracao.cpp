#include "Declaracao.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;

/*
23)decat -> ID COLON tipov atra SEMICOLON decat
24)decat -> v
25)atra -> ASSIGNMENT arit
26)atra -> v
*/

vector<Declaracao *> Declaracao::extrai_lista_declaracoes(No_arv_parse* no) {
  if (no->regra == 24) return vector<Declaracao*>();
  // Tem que ser regra 23.
  vector<Declaracao*> res;
  Declaracao* aux;
  aux->nome = ID::extrai_ID(no->filhos[0]);
  aux->tipo = Tipo::extrai_tipo(no->filhos[2]);
  aux->valor_ini = extrai_atra(no->filhos[3]);
  res.push_back(aux);
  vector<Declaracao*> restante = extrai_lista_declaracoes(no->filhos[5]);
  res.insert(res.end(), restante.begin(), restante.end());
  return res;
}

Expressao* Declaracao::extrai_atra(No_arv_parse* no) {
  Expressao* res = nullptr;
  if (no->regra == 26) return res;
  // Tem que ser regra 25.
  res = Expressao::extrai_expressao(no->filhos[1]);
  return res;
}

void Declaracao::debug_com_tab(int tab) {
  tab3(tab);
  cerr << "[" << nome->nome << ":" <<  tipo->nome << "] Declaracao Declarada" << endl;
}
