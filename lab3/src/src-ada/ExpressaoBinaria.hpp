#pragma once

#include "Expressao.hpp"
#include <string>

// Enum para representar os tipos de operadores de forma segura
enum OperadorBinario {
    OP_SOMA, OP_SUBTRACAO, OP_MULTIPLICACAO, OP_DIVISAO, OP_MOD,
    OP_MENOR_QUE, OP_MENOR_OU_IGUAL, OP_IGUAL, OP_MAIOR_OU_IGUAL,
    OP_MAIOR_QUE, OP_DIFERENTE, OP_E, OP_OU, OP_XOU
};

class ExpressaoBinaria : public Expressao {
public:
    Expressao* esquerda;
    Expressao* direita;
    OperadorBinario op;

    /**
     * @brief Construtor para uma expressão binária.
     * @param esq Ponteiro para a expressão da esquerda.
     * @param dir Ponteiro para a expressão da direita.
     * @param op O operador da expressão.
     */
    ExpressaoBinaria(Expressao* esq, Expressao* dir, OperadorBinario op);

    /**
     * @brief Destrutor para limpar a memória dos filhos.
     */
    virtual ~ExpressaoBinaria();

    // Você implementaria aqui os métodos para verificação semântica e geração de código
    // virtual void verificar_semantica(TabelaDeSimbolos& tabela) override;
    // virtual void gerar_codigo() override;
};