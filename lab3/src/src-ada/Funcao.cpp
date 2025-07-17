#include "Funcao.hpp"
#include "../debug-util.hpp"
#include <iostream>

Funcao::Funcao() {
}

Funcao* Funcao::extrai_funcao(No_arv_parse *no){
  if (no->regra != 1)   return NULL;
  // Dependente da gramatica. Regra 1 = Funcao.
  // 21)func -> FUNCTION ID LPARENTHESIS parametros RPARENTHESIS RETURN tipov IS decat BEGIN main END ID SEMICOLON
  Funcao* res = new Funcao();
  res->nome_funcao = ID::extrai_ID(no->filhos[1]);
  res->parametros = Parametro::extrai_lista_parametros(no->filhos[3]);
  res->tipo_retorno = Tipo::extrai_tipo(no->filhos[6]);
  res->declaracoes = Declaracao::extrai_lista_declaracoes(no->filhos[8]);
  res->comandos = Comando::extrai_lista_comandos(no->filhos[10]);
  res->nome_funcao = ID::extrai_ID(no->filhos[12]);
  return res;
}

/*void debug_variaveis(const vector<Variavel*> &vars, int tab) {
  for (int iv = 0; iv < vars.size(); ++iv) {
    tab3(tab);
    vars[iv]->debug_com_tab(tab+1);
  }
}

void debug_comandos(const vector<Comando*> &coms, int tab) {
  for (int ic = 0; ic < coms.size(); ++ic) {
    coms[ic]->debug_com_tab(tab+1);
  }  
}

void Funcao::debug() {
  if (tipo_retorno == NULL) cerr<< "TR NULL"<< endl;
  if (nome_funcao == NULL) cerr<< "NF NULL"<< endl;
  cerr << "Funcao:[retorno=" << tipo_retorno->nome << "][nome=" << nome_funcao->nome << "]" << endl;
  cerr << "      (Param:(";
  fflush(stderr);
  for (int i_par = 0; i_par < parametros.size(); ++i_par) {
    cerr << (parametros[i_par])->tipo->nome << " " <<
      (parametros[i_par])->nome->nome << ", ";
  }
  cerr << ") { " << endl;
  debug_variaveis(variaveis, 1);
  debug_comandos(comandos, 1);
  cerr << "}" <<  endl;
}
*/