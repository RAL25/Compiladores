#include "ExpressaoChamada.hpp"
#include <algorithm> 
#include <iostream>
#include "../debug-util.hpp"

using namespace std;

ExpressaoChamada::ExpressaoChamada() { }

void ExpressaoChamada::var_in_frame(std::vector<std::string>& var_frame) {
    // Para cada expressão que é um argumento...
    for (Expressao* arg : this->argumentos) {
        // ...encontre todas as variáveis usadas dentro dela.
        arg->descobrir_variaveis_usadas(var_frame);
    }
    // Não precisamos buscar no nome da função em si.
}


void ExpressaoChamada::calcular_max_params_saida(int& max_atual) {
    // Atualiza o máximo global com o número de argumentos desta chamada
    max_atual = std::max(max_atual, (int)this->argumentos.size());

    // Continua a busca dentro dos próprios argumentos (chamadas aninhadas)
    for (Expressao* arg : this->argumentos) {
        arg->calcular_max_params_saida(max_atual);
    }
}

void ExpressaoChamada::debug_com_tab(int tab) {
  /*tab3(tab);
  cerr << "/ [ INI Divisao"<< endl;
  esquerda->debug_com_tab(tab+1);
  tab3(tab);
  cerr << "/" << endl;
  direita->debug_com_tab(tab+1);
  tab3(tab);
  cerr << "/ ] FIM Divisao"<< endl;*/
  cerr<<"Chamando a funcao: "<<nome_funcao<<endl;
}
