#include "ExpressaoBinaria.hpp"

ExpressaoBinaria::ExpressaoBinaria(Expressao* esq, Expressao* dir, OperadorBinario op)
    : esquerda(esq), direita(dir), op(op) {}

ExpressaoBinaria::~ExpressaoBinaria() {
    delete esquerda;
    delete direita;
}

void ExpressaoBinaria::descobrir_variaveis_usadas(std::vector<std::string>& lista_vars) {
    // Busca recursivamente nos dois lados da expressão
    this->esquerda->descobrir_variaveis_usadas(lista_vars);
    this->direita->descobrir_variaveis_usadas(lista_vars);
}