#ifndef _TABELA_HPP_
#define _TABELA_HPP_
#include <vector>
#include <map>
#include "Variavel.hpp"

using namespace std;

class Tabela {
public:
  map<string, int> symbol_table;

  Tabela();
  void insere_parametros(vector<Variavel*> parametros, const vector<int> &params);
  void insere_variaveis(vector<Variavel*> variaveis);
  void print_table();
};

#endif
