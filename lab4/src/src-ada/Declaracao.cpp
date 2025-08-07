#include "Declaracao.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;

/*
26)decat -> ID COLON tipov atra SEMICOLON decat
27)decat -> v
28)atra -> ASSIGNMENT arit
29)atra -> v
*/

vector<Declaracao *> Declaracao::extrai_lista_declaracoes(No_arv_parse* no) {
  if (no->regra == 27) return vector<Declaracao*>();
  // Tem que ser regra 26.
  vector<Declaracao*> res;
  Declaracao* aux = new Declaracao();
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
  if (no->regra == 29) return res;
  // Tem que ser regra 28.
  res = Expressao::extrai_expressao(no->filhos[1]);
  return res;
}

void Declaracao::debug_com_tab(int tab) {
  tab3(tab);
  cerr << "[" << nome->nome << ":" <<  tipo->nome << "] Variavel Declarada" << endl;
}
