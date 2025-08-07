#ifndef _FRAME_FUNCAO_HPP_
#define _FRAME_FUNCAO_HPP_
#include "../src-ada/Funcao.hpp"
#include "../src-ada/Comando.hpp"
#include "FrameAcesso.hpp"
#include "FrameAcessoTemp.hpp"
#include "FrameAcessoNoFrame.hpp"
#include "../src-ada/Tabela.hpp"
#include <vector>
#include <map>
using namespace std;

class FrameFuncao {
public:
  int tamanho_frame;
  int n_param_entrada;
  int n_maximo_param_saida;
  int n_pseudo_registradores;
  int n_variaveis_no_frame;
  map <string, FrameAcesso*> tabela_simbolo;

  FrameFuncao();
  static FrameFuncao* gera_frame_de_funcao(Funcao* fun);
  static void var_in_frame(Funcao* fun, vector<string> &var_frame);
  static void percurso_funcao(Funcao* fun, map < string, FrameAcesso* > &table);
  void debug();
};

#endif
