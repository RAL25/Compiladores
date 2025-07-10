#pragma once
#include<string>
#include "../Arvore.hpp"
using namespace std;

class Tipo {
public:
  string nome;
  static Tipo* extrai_tipo(No_arv_parse* no);
};
