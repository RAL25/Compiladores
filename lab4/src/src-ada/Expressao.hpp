#pragma once
#include "../Arvore.hpp"
#include "vector"

class Expressao {
public:
    static Expressao* extrai_expressao(No_arv_parse* no);
    static vector<Expressao*> extrair_lista_argumentos(No_arv_parse* no);
    virtual void descobrir_variaveis_usadas(std::vector<std::string>& lista_vars);
    virtual void calcular_max_params_saida(int& max_atual);
    virtual void debug_com_tab(int tab);
};
