#include "Define.hpp"
#include "ID.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;

vector<Define *> Define::extrai_lista_define(No_arv_parse* no) {
  // LP
    
    
        //4) define -> v
  if (no->regra == 4) return vector<Define*>();
  // C. 12) C -> ID = E ; 13) C -> { LV LC }
  else if (no->regra == 2) { //12) C -> ID = E ;    //2) define -> func define                             
    vector<Comando*> res;
    res.push_back(Funcao::extrai_funcao(no->filhos[0]));
    vector<Comando*> restante = extrai_lista_comandos(no->filhos[1]);
    res.insert(res.end(), restante.begin(), restante.end());
    return res;
  } else if (no->regra == 3) { // 13) C -> { LV LC }    //3) define -> decatA define
    ComandoLista* res13 = new ComandoLista();
    res13->lista_variaveis = Variavel::extrai_lista_variaveis(no->filhos[1]);
    res13->lista_comandos = extrai_lista_comandos(no->filhos[2]);
    return res13;
  }else {
    return NULL;
  }	
  // Tem que ser regra 3, com unico filho.
  return extrai_lista_nao_vazia_define(no->filhos[0]);
}

vector<Variavel*> Variavel::extrai_lista_nao_vazia_define(No_arv_parse* no) {
  // LPx. 4) LPx -> P, 5) LPx -> P , LPx
  vector<Variavel*> res;
  res.push_back(extrai_variavel_P(no->filhos[0]));
  if (no->regra == 4) return res;
  // Tem que ser regra 5. LPx-> P , LPx
  vector<Variavel*> restante = extrai_lista_nao_vazia_define(no->filhos[2]);
  res.insert(res.end(), restante.begin(), restante.end());
  return res;
}

vector<Variavel *> Variavel::extrai_lista_variaveis(No_arv_parse* no) {
  if (no->regra == 6) return vector<Variavel*>();
  // Tem que ser regra 7.
  vector<Variavel*> res;
  // 7) LV -> V LV    ,   10)V -> P ;   extrai(P) ,   
  res.push_back(extrai_variavel_P(no->filhos[0]->filhos[0]));
  // 7) LV -> V LV. Focando em LV da direita.
  vector<Variavel*> restante = extrai_lista_variaveis(no->filhos[1]);
  res.insert(res.end(), restante.begin(), restante.end());
  return res;
}

Variavel* Variavel::extrai_variavel_P(No_arv_parse* no) {
  Variavel* res = new Variavel();
  // 11) P -> ID ID
  res->tipo = ID::extrai_ID(no->filhos[0]);
  res->nome = ID::extrai_ID(no->filhos[1]);
  return res;
}

void Variavel::debug_com_tab(int tab) {
  tab3(tab);
  cerr << "[" << nome->nome << ":" <<  tipo->nome << "] Variavel Declarada" << endl;
}
