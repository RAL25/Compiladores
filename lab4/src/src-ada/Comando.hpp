#ifndef _COMANDO_HPP_
#define _COMANDO_HPP_
#include<vector>
#include<stack>
#include "../Arvore.hpp"
#include "Expressao.hpp"
#include "Tabela.hpp"
using namespace std;

class Comando {
public:
  Expressao* expressao_arit;
  virtual ~Comando();
  static vector<Comando*> extrai_lista_comandos(No_arv_parse* no);
  static Comando* extrai_atr(No_arv_parse* no);
  static Comando* extrai_comando(No_arv_parse* no);
  static vector<Comando*> extrai_else(No_arv_parse* no);
  static Comando* extrai_loop(No_arv_parse* no);
  static Comando* extrai_retorno(No_arv_parse* no);
  static Comando* chama_extrai_expressao(No_arv_parse* no);
  virtual int executa_comando( stack<Tabela*> &simbolos );
  virtual void var_in_frame( vector<string> &var_frame);
  virtual void percurso_funcao(  map < string, FrameAcesso* > &table );
  virtual void calcular_max_params_saida(int& max_atual);
  virtual void debug_com_tab(int tab);
};

#endif
