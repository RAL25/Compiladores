#include "FrameFuncao.hpp"
#include "../src-ada/ExpressaoChamada.hpp"
#include <iostream>
using namespace std;

FrameFuncao::FrameFuncao() { }

FrameFuncao* FrameFuncao::gera_frame_de_funcao(Funcao* fun) {
  
  FrameFuncao* frame = new FrameFuncao();
  vector<string> var_frame;     // Lista das variáveis que são parâmetros de chamada
  frame->n_variaveis_no_frame = 0;

  // Calculando posição no frame dos parâmetros de entrada, e adicionando na tabela
  int p = fun->parametros.size();
  for( Parametro* pa : fun->parametros ){
      FrameAcessoNoFrame *fa = new FrameAcessoNoFrame();
      fa->posicao_no_frame = p * 8;
      pa->acesso_frame = fa;
      frame->tabela_simbolo.insert( pair <string, FrameAcesso* > ( pa->nome->nome, fa ) );
      var_frame.push_back(pa->nome->nome);
      pa--;
  }

  // Fazendo percurso na função para detectar as variáveis parâmetro de chamada
  var_in_frame(fun, var_frame);

  p = 0;
  for(string v : var_frame){
    if(frame->tabela_simbolo.find(v) == frame->tabela_simbolo.end()){
      frame->n_variaveis_no_frame++;
      FrameAcessoNoFrame *fa = new FrameAcessoNoFrame();
      fa->posicao_no_frame = -(40 + (p * 8));
      frame->tabela_simbolo.insert( pair <string, FrameAcesso* > ( v, fa ) );
      p++;
    }
  }

  // Fazendo percurso e determinando a posição no frame e registradores
  FrameAcessoTemp::cout = 0;
  percurso_funcao(fun, frame->tabela_simbolo);

  // Definindo o acesso frame da lista de variáveis
  for(Declaracao* d : fun->declaracoes){
    if(frame->tabela_simbolo.find(d->nome->nome) != frame->tabela_simbolo.end()){
      d->acesso_frame = frame->tabela_simbolo.at(d->nome->nome);
    }
    else{ 
      // Caso a variável não foi declarada mas não usada, optei em deixá-la em pseudo-registradores, 
      // mas poderia ignorá-las para otimização
      FrameAcessoTemp *fa = new FrameAcessoTemp();
      fa->id = FrameAcessoTemp::cout;
      frame->tabela_simbolo.insert( pair <string, FrameAcesso* > ( d->nome->nome, fa ) );
      d->acesso_frame = fa;
      FrameAcessoTemp::cout++;
    }
  }

  frame->n_param_entrada = fun->parametros.size();
  // frame->n_maximo_param_saida = ExpressaoChamada::max_parametros;
  frame->n_pseudo_registradores = FrameAcessoTemp::cout;
  frame->tamanho_frame = 40 + ( 8 * frame->n_variaveis_no_frame ) + ( 8 * frame->n_maximo_param_saida );

// --- CÁLCULO DO NÚMERO MÁXIMO DE PARÂMETROS DE SAÍDA ---
  int max_params = 0;
  // Inicia a passagem de cálculo a partir dos comandos da função
  for(Comando* c : fun->comandos){
      c->calcular_max_params_saida(max_params);
  }
  frame->n_maximo_param_saida = max_params;

  frame->tamanho_frame = 40 + ( 8 * frame->n_variaveis_no_frame ) + ( 8 * frame->n_maximo_param_saida );

  return frame;
}

void FrameFuncao::var_in_frame(Funcao* fun, vector<string> &var_frame){
  for(Comando* c : fun->comandos){
    c->var_in_frame(var_frame);
  }
}

void FrameFuncao::percurso_funcao(Funcao* fun, map < string, FrameAcesso* > &table){
  for(Comando* c : fun->comandos){
    c->percurso_funcao(table);
  }
}

void FrameFuncao::debug(){
  cout << "*********** Frame Funcao ***********" << endl;
  cout << "Tamanho do Frame: " << tamanho_frame << " bytes" << endl;
  cout << "Num parametros entrada: " << n_param_entrada << endl;
  cout << "Num parametros saida: " << n_maximo_param_saida << endl;
  cout << "Num pseudo registradores: " << n_pseudo_registradores << endl;
  cout << "Num variaveis no frame: " << n_variaveis_no_frame << endl;
  cout << "************************************" << endl;
  cout << "************Tabela de Simbolos************" << endl;
  for (auto const &pair: tabela_simbolo) {
      cout << "[ " << pair.first << " : " << pair.second->debug() << " ]\n";
  }
  cout << "************************************" << endl;
}