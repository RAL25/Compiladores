#include "ExpressaoBinaria.hpp"

ExpressaoBinaria::ExpressaoBinaria(Expressao* esq, Expressao* dir, OperadorBinario op)
    : esquerda(esq), direita(dir), op(op) {}

ExpressaoBinaria::~ExpressaoBinaria() {
    delete esquerda;
    delete direita;
}