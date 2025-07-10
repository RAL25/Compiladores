#include "Comando.hpp"
#include "ComandoAtribuicao.hpp"
#include "ComandoIF.hpp"
#include "ID.hpp"
#include "Variavel.hpp"
#include <iostream>
#include "../debug-util.hpp"

vector<Comando*> Comando::extrai_lista_comandos(No_arv_parse* no) {
  /*
  6)main -> atr main
  7)main -> arit main
  8)main -> call SEMICOLON main
  9)main -> cmd main
  10)main -> v
  */ 
 vector<Comando*> res;
  if (no->regra == 6){
    res.push_back(extrai_atr(no->filhos[0]));
    vector<Comando*> restante = extrai_lista_comandos(no->filhos[1]);
    res.insert(res.end(), restante.begin(), restante.end());
  }
  else if (no->regra == 7)   
    return Comando::extrai_lista_comandos(no->filhos[1]);
  else if (no->regra == 8)
    return Comando::extrai_lista_comandos(no->filhos[2]);
  else if (no->regra == 9) {
    res.push_back(extrai_comando(no->filhos[0]));
    vector<Comando*> restante = extrai_lista_comandos(no->filhos[1]);
    res.insert(res.end(), restante.begin(), restante.end());
  }
  else{
    // Tem que ser regra 10.
    return vector<Comando*>();
  }
  return res;
}

Comando* Comando::extrai_atr(No_arv_parse* no){
  // 31) atr -> ID ASSIGNMENT arit SEMICOLON
  ComandoAtribuicao* res;
  res->esquerda = ID::extrai_ID(no->filhos[0]);
  res->direita = Expressao::extrai_expressao(no->filhos[2]);
  return res;
}

Comando* Comando::extrai_comando(No_arv_parse* no) {
  /*
    27) cmd -> IF arit THEN main parte_condicional END IF SEMICOLON
    28) parte_condicional -> ELSIF arit THEN main parte_condicional
    29) parte_condicional -> ELSE main
    30) parte_condicional -> v
  */
  ComandoIF* res = new ComandoIF();
  res->condicao_if = Expressao::extrai_expressao(no->filhos[1]);
  res->corpo_if = Comando::extrai_lista_comandos(no->filhos[3]);
  res->corpo_else = extrai_else(no->filhos[4]);
  return res;     
}

vector<Comando*> extrai_else(No_arv_parse* no){
  vector<Comando*> res;
  if(no->regra == 28){
    res = extrai_else(no->filhos[4]);
  }else if(no->regra == 29){
    vector<Comando*> restante = Comando::extrai_lista_comandos(no->filhos[1]);
    res.insert(res.end(), restante.begin(), restante.end());
  }else{
    return vector<Comando*>();
  }
}

void Comando::debug_com_tab(int tab) {
  /*tab3(tab);
  cerr << "Comando generico"<< endl;*/
}
