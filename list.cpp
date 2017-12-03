// Estefano Fodor, Juan Martinez
// November 12th, 2017
#ifndef LIST_CPP
#define LIST_CPP

#include "list.h"
#include <cstdlib>

Node* List::pars_expr(){
  string expr = "";
  cout << "Enter expression: ";
  cin >> expr;
  operator_type opr = PLUS;
  Node* current = new Node(opr);
  int val;
  int i = 0;
  int length = expr.length();
  char c = expr[0];
  Node *n = new Node(0);
  Node *p = new Node(0);
  Node *q = new Node(0);
  while (i < length){
    c = expr[i];
    val = c - '0';
    if ( c == '('){
      if(i != 0){
	n = new Node(opr);
	n->setParent(current);
	if(current->get_operand1() == NULL){
	  current->change_operand1(n);
	}
	else if(current->get_operand2() == NULL){
	  current->change_operand2(n);
	}
	current = n;
      }
    }
    else if(c == '+' || c == '-' || c == '*' || c == '/'){
      if(c == '+'){
    	opr = PLUS;
      }
      else if(c = '-'){
    	opr = MINUS;
      }
      else if(c = '*'){
    	opr = MULT;
      }
      else if(c = '/'){
    	opr = DIVIDE;
      }
      current->change_operator(opr);
    }
    else if(c == 'x'){
      p = new Node(c);
      current->change_operand1(p);
    }
    else if(val >= 0 || val <= 9){
      q = new Node(val);
      current->change_operand2(q);
      current = current->get_parent();
    }
    else if(c == ')'){
      current = current->get_parent();
    }
    i++;
  }
  return current;
};

#endif    
