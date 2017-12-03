// Estefano Fodor, Juan Martinez
// November 16th, 2017
#ifndef STRING_CPP
#define STRING_CPP

#include "string.h"

int main(){
  string in = "";
  string post = "";
  string pre = "";
  List list;
  Expression expression;
  Node* n = list.pars_expr();
  expression.infix(n);
  in = expression.return_s1();
  cout << in;
  expression.postfix(n);
  post = expression.return_s1();
  cout << post << endl;
  expression.prefix(n);
  pre = expression.return_s1();
  cout << pre <<endl;
  return 0;
};

#endif
