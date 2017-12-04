// Estefano Fodor, Juan Martinez
// November 14th, 2017
#ifndef EXPRESSION_CPP
#define EXPRESSION_CPP

#include "expression.h"
#include <cstdlib>

Expression::Expression(){
  this->s1 = "";
  this->n = NULL;
}

void Expression::infix(Node* source){
  this->s1 = "";
  this->n = source;
  if(this->n == NULL){
    return;
  }
  if(this->n->get_operand1() != NULL){
    this->s1 += '(';
    infix(n->get_operand1());
  }
  this->s1 += this->n->print_infix();
  if(this->n->get_operand2() != NULL){
    infix(this->n->get_operand2());
  }
  return;
}

void Expression::prefix(Node* source) {
  this->s1 = "";
  this->n = source;
  if(this->n == NULL){
    return;
  }
  this->s1 += this->n->print_prefix();
  if(this->n->get_operand1() != NULL){
    prefix(this->n->get_operand1());
  }
  else if(this->n->get_operand2() != NULL){
    prefix(this->n->get_operand2());
  }
  return;
}

void Expression::postfix(Node* source) {
  this->s1 = "";
  this->n = source;
  if(this->n == NULL){
    return;
  }
  if(this->n->get_operand1() != NULL){
    postfix(this->n->get_operand1());
  }
  else if(this->n->get_operand2() != NULL){
    postfix(this->n->get_operand2());
  }
  this->s1 += this->n->print_postfix();
  return;
}

string Expression::return_s1() const{
  return this->s1;
}

int Expression::eval(Node *source){
  if(source->get_operand1() == NULL && source->get_operand2() == NULL){
    return get_val(source);
  }
  node_type x;
  int x;
  int y;
  Node* n = source;
  int val = 0;
  x = source.getNodeType();
  if(x == EXPRESSION){
    if(source->get_operand1().getNodeType() == EXPRESSION){
      eval(source->get_operand1());
    }
    else if(source->get_operand2().getNodeType() == EXPRESSION){
      eval(source->get_operand2());
    }
    else{
      n = source->get_operand1();
      x = get_val(n);
      delete n;
      n = source->get_operand2();
      y = get_val(n);
      delete n;
      val = x source.print_operator() y;
      Node p = new Node(val);
      p->setParent(source->getParent());
      delete source;
      source = p;
    }
  }      
}

bool Expression::compare(int x, int y){
  if (x == y){
    return true;
  }
  else{
    return false;
  }
};

#endif
