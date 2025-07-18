#ifndef _COMANDO_HPP_
#define _COMANDO_HPP_
#include<vector>
#include "../Arvore.hpp"
using namespace std;

class Comando {
public:
  static vector<Comando*> extrai_lista_comandos(No_arv_parse* no);
  static Comando* extrai_atr(No_arv_parse* no);
  static Comando* extrai_comando(No_arv_parse* no);
  static vector<Comando*> extrai_else(No_arv_parse* no);
  static Comando* extrai_loop(No_arv_parse* no);
  static Comando* extrai_retorno(No_arv_parse* no);
  virtual void debug_com_tab(int tab);
};

#endif
