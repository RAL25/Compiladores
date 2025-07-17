#include "Expressao.hpp"
#include "ExpressaoDivisao.hpp"
#include "ExpressaoMod.hpp"
#include "ExpressaoMultiplicacao.hpp"
#include "ExpressaoNumero.hpp"
#include "ExpressaoSoma.hpp"
#include "ExpressaoSubtracao.hpp"
#include "ExpressaoVariavel.hpp"
#include <iostream>
#include "../debug-util.hpp"

using namespace std;

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

// Tratei tanto o E quanto T e F na mesma funcao.
Expressao* Expressao::extrai_expressao(No_arv_parse* no) {
  // E,T,F. 14) a 23)
  switch(no->regra) {
  case 14: { // 14) E -> E + T
    ExpressaoSoma* res14 = new ExpressaoSoma();
    res14->esquerda = extrai_expressao(no->filhos[0]);
    res14->direita = extrai_expressao(no->filhos[2]);
    return res14;
  }
  case 15: { // 15) E -> E - T 
    ExpressaoSubtracao* res15 = new ExpressaoSubtracao();
    res15->esquerda = extrai_expressao(no->filhos[0]);
    res15->direita = extrai_expressao(no->filhos[2]);
    return res15;
  }
  case 16: { // 16) E -> T
    return extrai_expressao(no->filhos[0]);
  }
  case 17: { // 17) T -> T * F
    ExpressaoMultiplicacao* res17 = new ExpressaoMultiplicacao();
    res17->esquerda = extrai_expressao(no->filhos[0]);
    res17->direita = extrai_expressao(no->filhos[2]);
    return res17;
  }
  case 18: {// 18) T -> T / F
    ExpressaoDivisao* res18 = new ExpressaoDivisao();
    res18->esquerda = extrai_expressao(no->filhos[0]);
    res18->direita = extrai_expressao(no->filhos[2]);
    return res18;
  }
  case 19: { // 19) T -> T % F
    ExpressaoMod* res19 = new ExpressaoMod();
    res19->esquerda = extrai_expressao(no->filhos[0]);
    res19->direita = extrai_expressao(no->filhos[2]);
    return res19;
  }
  case 20: { // 19) T -> F
    return extrai_expressao(no->filhos[0]);
  }
  case 21: { // 21) F -> ( E )
    return extrai_expressao(no->filhos[1]);
  }
  case 22: { // 22) F -> ID
    ExpressaoVariavel* res22 = new ExpressaoVariavel();
    res22->nome = ID::extrai_ID(no->filhos[0]);
    return res22;
  }
  case 23: { // 23) F -> NUM
    ExpressaoNumero* res23 = new ExpressaoNumero();
    res23->numero = NUM::extrai_NUM(no->filhos[0]);
    return res23;
  }
  default: {
    return NULL;
  }
  }
}

void Expressao::debug_com_tab(int tab) {
  tab3(tab);
  cerr << "Expressao generica" << endl;
}
