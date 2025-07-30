#include "ComandoIF.hpp"
#include <iostream>
#include "../debug-util.hpp"
using namespace std;

ComandoIF::ComandoIF() {
  
}

void ComandoIF::debug_com_tab(int tab) {
  tab3(tab);
  cerr << "INI IF: " << /* << " = " */ endl;
  condicao_if->debug_com_tab(tab+1);
  for (int iv = 0; iv < corpo_if.size(); ++iv) {
    corpo_if[iv]->debug_com_tab(tab+1);
  }
  tab3(tab);
  cerr << "FIM IF" << endl;
  cerr << endl;
  // cerr<<"ComandoIF"<<endl;
}
