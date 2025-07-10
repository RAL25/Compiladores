#include "Tipo.hpp"

Tipo* Tipo::extrai_tipo(No_arv_parse* no) {
  Tipo* res = new Tipo();
  /*tipov -> INTEGER
  tipov -> FLOAT
  tipov -> BOOLEAN*/
  res->nome = no->filhos[0]->dado_extra;
  return res;
}
