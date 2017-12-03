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
};

#endif
