#include "ComandoWhile.hpp"
#include <iostream>
#include "../debug-util.hpp"
using namespace std;

ComandoWhile::ComandoWhile() {
  
}

void ComandoWhile::debug_com_tab(int tab) {
  tab3(tab);
  cerr << "INI WHILE: " << /*esquerda->nome << " = " <<*/ endl;
  condicao_while->debug_com_tab(tab+1);
  for (int iv = 0; iv < corpo_while.size(); ++iv) {
    corpo_while[iv]->debug_com_tab(tab+1);
  }
  tab3(tab);
  cerr << "FIM WHILE" << endl;
  cerr << endl;
  // cerr<<"ComandoWhile"<<endl;
}
