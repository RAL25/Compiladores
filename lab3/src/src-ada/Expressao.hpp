#pragma once
#include "../Arvore.hpp"

class Expressao {
public:
    static Expressao* extrai_expressao(No_arv_parse* no);
    virtual void debug_com_tab(int tab);
};
