#pragma once
#include "FrameAcesso.hpp"
#include <iostream>
using namespace std;

class FrameAcessoTemp : public FrameAcesso {
public:
  int id; // id unico do pseudo-registrador/temporario.
  static int cout;
  FrameAcessoTemp();
  string debug();
};
