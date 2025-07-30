#include "Expressao.hpp"
#include "ExpressaoDivisao.hpp"
#include "ExpressaoMod.hpp"
#include "ExpressaoMultiplicacao.hpp"
#include "ExpressaoNumero.hpp"
#include "ExpressaoSoma.hpp"
#include "ExpressaoSubtracao.hpp"
#include "ExpressaoVariavel.hpp"
#include "ExpressaoMenor.hpp"
#include "ExpressaoMaior.hpp"
#include <iostream>
#include "../debug-util.hpp"
// #include "Expressao.hpp"
// #include "ExpressaoNumero.hpp"
// Remova includes antigos como ExpressaoSoma, etc.
// E adicione o novo:
#include "ExpressaoBinaria.hpp"
// Inclua também os outros tipos de expressão que você tem (ID, Chamada, etc.)

Expressao* Expressao::extrai_expressao(No_arv_parse* no) {
  /*
  35) arit -> aritA
  36) arit -> aritA oprA aritA
  37) oprA -> LESSTHAN
  38) oprA -> LESSTHANOREQUAL
  39) oprA -> EQUALS
  40) oprA -> GREATERTHANOREQUAL
  41) oprA -> GREATERTHAN
  42) oprA -> INEQUALITY
  43) aritA -> aritA oprB aritB
  44) aritA -> aritB
  45) oprB -> PLUS
  46) oprB -> HYPHEN
  47) oprB -> OR
  48) oprB -> XOR
  49) aritB -> aritB oprC aritC
  50) aritB -> aritC
  51) oprC -> ASTERISK
  52) oprC -> SOLIDUS
  53) oprC -> MOD
  54) oprC -> AND
  55) aritC -> LPARENTHESIS arit RPARENTHESIS
  56) aritC -> HYPHEN aritC
  57) aritC -> PLUS aritC
  58) aritC -> NOT aritC
  59) aritC -> ID 
  60) aritC -> NUMBER 
  61) aritC -> call
  */
    if (no == nullptr) return nullptr;
    // O número da regra vem do seu arquivo de gramática
    int regra = no->regra;
    // Regras para operadores binários (precedência baixa: <, >, =, etc.)
    // 36) arit -> aritA oprA aritA
    if (regra == 36) {
        Expressao* esq = extrai_expressao(no->filhos[0]);
        Expressao* dir = extrai_expressao(no->filhos[2]);
        No_arv_parse* no_operador = no->filhos[1];
        int regra_opr = no_operador->regra; // Pega a regra do operador específico

        OperadorBinario op;
        switch (regra_opr) {
            case 37: { // op = OP_MENOR_QUE; break;
                ExpressaoMenor* res17 = new ExpressaoMenor();
                res17->esquerda = esq;
                res17->direita = dir;
                return res17;   
            }
            case 38: op = OP_MENOR_OU_IGUAL; break;
            case 39: op = OP_IGUAL; break;
            case 40: op = OP_MAIOR_OU_IGUAL; break;
            case 41: {// op = OP_MAIOR_QUE; break;
                ExpressaoMaior* res17 = new ExpressaoMaior();
                res17->esquerda = esq;
                res17->direita = dir;
                return res17;   
            }
            case 42: op = OP_DIFERENTE; break;
            default: // Tratar erro
                return nullptr;
        }
        return new ExpressaoBinaria(esq, dir, op);
    }
    // 43) aritA -> aritA oprB aritB
    else if (regra == 43) {
        Expressao* esq = extrai_expressao(no->filhos[0]);
        Expressao* dir = extrai_expressao(no->filhos[2]);
        int regra_opr = no->filhos[1]->regra;

        OperadorBinario op;
        switch (regra_opr) {
            case 45:{ /*op = OP_SOMA;*/ 
              ExpressaoSoma* res14 = new ExpressaoSoma();
              res14->esquerda = esq;
              res14->direita = dir;
              return res14;
            break;}
            case 46:{ // op = OP_SUBTRACAO; break;
              ExpressaoSubtracao* res15 = new ExpressaoSubtracao();
              res15->esquerda = esq;
              res15->direita = dir;
              return res15;
            }
            // Falta fazer para essas regras
            case 47: op = OP_OU; break;
            case 48: op = OP_XOU; break;
            default: return nullptr;
        }
        return new ExpressaoBinaria(esq, dir, op);
    }
    // 49) aritB -> aritB oprC aritC
    else if (regra == 49) {
        Expressao* esq = extrai_expressao(no->filhos[0]);
        Expressao* dir = extrai_expressao(no->filhos[2]);
        int regra_opr = no->filhos[1]->regra;
        
        OperadorBinario op;
        switch (regra_opr) {
            case 51:{// op = OP_MULTIPLICACAO; break;
                ExpressaoMultiplicacao* res17 = new ExpressaoMultiplicacao();
                res17->esquerda = esq;
                res17->direita = dir;
                return res17;  
            }
            case 52: {//op = OP_DIVISAO; break;
                ExpressaoDivisao* res18 = new ExpressaoDivisao();
                res18->esquerda = esq;
                res18->direita = dir;
                return res18;  
            }
            case 53: op = OP_MOD; break;
            case 54: op = OP_E; break;
            default: return nullptr;
        }
        return new ExpressaoBinaria(esq, dir, op);
    }
    // Regras que simplesmente passam para o próximo nível de precedência
    // 35) arit -> aritA
    // 44) aritA -> aritB
    // 50) aritB -> aritC
    else if (regra == 35 || regra == 44 || regra == 50) {
        return extrai_expressao(no->filhos[0]);
    }
    // Regras para terminais e outras expressões
    // 60) aritC -> NUMBER
    else if (regra == 60) {
        // Supondo que a classe ExpressaoNumero extraia o valor do dado_extra
        ExpressaoNumero* res60 = new ExpressaoNumero();
        res60->numero = NUM::extrai_NUM(no->filhos[0]);
        return res60;
    }
    /*
    Para a regra 55) aritC -> LPARENTHESIS arit RPARENTHESIS
    */
   else if(regra == 55){
        return extrai_expressao(no->filhos[1]);
   }
   // Regra 59) aritC -> ID 
   else if(regra == 59){
        ExpressaoVariavel* res60 = new ExpressaoVariavel();
        res60->nome = ID::extrai_ID(no->filhos[0]);
        return res60;
   }
    // Adicione aqui os casos para as regras 55 a 59 e 61 (parênteses, unários, ID, chamada)
    
    // ... outros 'else if' para as demais regras ...
    
    else {
        // Caso a regra não seja reconhecida
        return nullptr;
    }
}

void Expressao::debug_com_tab(int tab) {
  tab3(tab);
  cerr << "Expressao generica" << endl;
}