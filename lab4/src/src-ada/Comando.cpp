#include "Comando.hpp"
#include "ComandoAtribuicao.hpp"
#include "ComandoIF.hpp"
#include "ComandoWhile.hpp"
#include "ComandoReturn.hpp"
#include "ComandoExpressao.hpp"
#include "Expressao.hpp"
#include "ID.hpp"
#include "Variavel.hpp"
#include <iostream>
#include "../debug-util.hpp"

Comando::~Comando() {}

vector<Comando*> Comando::extrai_lista_comandos(No_arv_parse* no) {
  /*
  6) main -> atr main
  7) main -> exp main
  8) main -> call SEMICOLON main
  9) main -> cmd main
  10) main -> loop main
  11) main -> ret main
  12) main -> v
  */ 
 vector<Comando*> res;
  if (no->regra == 6){
    res.push_back(extrai_atr(no->filhos[0]));
    vector<Comando*> restante = extrai_lista_comandos(no->filhos[1]);
    res.insert(res.end(), restante.begin(), restante.end());
  }
  else if (no->regra == 7){
    res.push_back(chama_extrai_expressao(no->filhos[0]));
    vector<Comando*> restante = extrai_lista_comandos(no->filhos[1]);
    res.insert(res.end(), restante.begin(), restante.end());
    // return Comando::extrai_lista_comandos(no->filhos[2]);
  }
  else if (no->regra == 8)
    return Comando::extrai_lista_comandos(no->filhos[2]);
  else if (no->regra == 9) {
    res.push_back(extrai_comando(no->filhos[0]));
    vector<Comando*> restante = extrai_lista_comandos(no->filhos[1]);
    res.insert(res.end(), restante.begin(), restante.end());
  }
  else if(no->regra == 10){
    res.push_back(extrai_loop(no->filhos[0]));
    vector<Comando*> restante = extrai_lista_comandos(no->filhos[1]);
    res.insert(res.end(), restante.begin(), restante.end());
  }
  else if(no->regra == 11){
    res.push_back(extrai_retorno(no->filhos[0]));
    vector<Comando*> restante = extrai_lista_comandos(no->filhos[1]);
    res.insert(res.end(), restante.begin(), restante.end());
  }
  else{
    // Tem que ser regra 12.
    return vector<Comando*>();
  }
  return res;
}

Comando* Comando::extrai_atr(No_arv_parse* no){
  // 34)atr -> ID ASSIGNMENT arit SEMICOLON
  ComandoAtribuicao* res = new ComandoAtribuicao();
  res->esquerda = ID::extrai_ID(no->filhos[0]);
  res->direita = Expressao::extrai_expressao(no->filhos[2]);
  return res;
}

Comando* Comando::chama_extrai_expressao(No_arv_parse* no){
  // 66)exp -> arit SEMICOLON 
  ComandoExpressao* res = new ComandoExpressao();
  res->expressao_arit = Expressao::extrai_expressao(no->filhos[0]);
  return res;
}

Comando* Comando::extrai_comando(No_arv_parse* no) {
/*
  30) cmd -> IF arit THEN main parte_condicional END IF SEMICOLON
  */
  ComandoIF* res = new ComandoIF();
  res->condicao_if = Expressao::extrai_expressao(no->filhos[1]);
  res->corpo_if = Comando::extrai_lista_comandos(no->filhos[3]);
  res->corpo_else = extrai_else(no->filhos[4]);
  return res;     
}
  
vector<Comando*> Comando::extrai_else(No_arv_parse* no){
  /*
  31) parte_condicional -> ELSIF arit THEN main parte_condicional
  32) parte_condicional -> ELSE main
  33) parte_condicional -> v
  */
  vector<Comando*> res;
  if(no->regra == 31){
    res = extrai_else(no->filhos[4]);
  }else if(no->regra == 32){
    vector<Comando*> restante = Comando::extrai_lista_comandos(no->filhos[1]);
    res.insert(res.end(), restante.begin(), restante.end());
  }else{
    // Tem que ser a regra 33.
    return vector<Comando*>();
  }
  return res;
}

Comando* Comando::extrai_loop(No_arv_parse* no){
  // 65)loop -> WHILE arit LOOP main END LOOP SEMICOLON
  ComandoWhile* res = new ComandoWhile();
  res->condicao_while = Expressao::extrai_expressao(no->filhos[1]);
  res->corpo_while = Comando::extrai_lista_comandos(no->filhos[3]);
  return res;
}

Comando* Comando::extrai_retorno(No_arv_parse* no){
  // 13)ret -> RETURN main
  ComandoReturn* res = new ComandoReturn();
  res->retorno_comandos = Comando::extrai_lista_comandos(no->filhos[1]);
  return res;
}

int Comando::executa_comando( stack<Tabela*> &simbolos ){
    cout << "Executa comando genérico" << endl;
    return 0;
}

void Comando::var_in_frame( vector<string> &var_frame){

}

void Comando::percurso_funcao(  map < string, FrameAcesso* > &table ){

}

void Comando::calcular_max_params_saida(int& max_atual){}

void Comando::debug_com_tab(int tab) {
  tab3(tab);
  cerr << "Comando generico"<< endl;
}
