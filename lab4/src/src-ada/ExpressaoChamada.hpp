// Em src-ada/ExpressaoChamada.hpp (Novo ou modificado)
#pragma once

#include "Expressao.hpp"
#include "ID.hpp"
#include <vector>

class ExpressaoChamada : public Expressao {
public:
    ID* nome_funcao;
    std::vector<Expressao*> argumentos;
    
    ExpressaoChamada();
    void var_in_frame(std::vector<std::string>& var_frame);
    void calcular_max_params_saida(int& max_atual);
    void debug_com_tab(int tab);
};