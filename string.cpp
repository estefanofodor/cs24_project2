// Estefano Fodor, Juan Martinez
// November 16th, 2017
#ifndef STRING_CPP
#define STRING_CPP

#include "string.h"

int main(){
  string p = "";
  List list;
  Expression expression;
  while (p != "stop"){
    p = "";
    q = "";
    cout << "Enter 1 for Expression Evaluation, 2 for Expression Comparison, or stop to stop";
    cin >> p;
    if(p == "stop"){
      break;
    }
    else if(p == "1"){
      Node* n = list.pars_expr();
      cout << expression.eval(n) << endl;
    }
    else if(p == "2"){
      Node* n = list.pars_expr();
      Node* p = list.pars_expr();
      cout << expression.compare(expression.eval(n), expression.eval(q)) << endl;
    }
    else {
      cout << "Not a valid option" << endl;
    }
  }
  return 0;
};

#endif
