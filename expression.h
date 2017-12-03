// Estefano Fodor, Juan Martinez
// November 16th, 2017
#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include "list.h"
using namespace std;

class Expression{
 public:
  Expression();
  void infix(Node* source);
  void prefix(Node* source);
  void postfix(Node* source);
  string return_s1() const;
  
 private: 
  string s1;
  int used;
  Node *n;
};
#endif
