// Estefano Fodor, Juan Martinez
// November 11th, 2017
#ifndef NODE_CPP
#define NODE_CPP

#include "node.h"
#include <string>

Node::Node(char var){
  this->node_t = VARIABLE;
  this->data.var = var;
  this->operand1 = NULL;
  this->operand2 = NULL;
  this->parent = NULL;
}

Node::Node(operator_type op, Node* operand1, Node* operand2){
  this->node_t = EXPRESSION;
  this->data.op = op;
  this->operand1 = operand1;
  this->operand2 = operand2;
  this->parent = NULL;
}

Node::Node(int val){
  this->node_t = INTEGER;
  this->data.val = val;
  this->operand1 = NULL;
  this->operand2 = NULL;
  this->parent = NULL;
}

Node::~Node(){
  if(this != NULL){
    delete this->operand1;
    delete this->operand2;
    delete this->parent;
    delete this;
  }
}

string Node::print_infix() const{
  string s1 = "";
  if(getNodeType() == INTEGER){
    s1 = int_to_string()+ ')';
  }
  else if(getNodeType() == VARIABLE){
    s1 = '(' + this->data.var;
  }
  else if(getNodeType() == EXPRESSION){
    s1 = print_operator();
  }
}

string Node::print_prefix() const{
  string s1 = "";
  if(getNodeType() == INTEGER){
    s1 = int_to_string();
  }
  else if(getNodeType() == VARIABLE){
    s1 = this->data.var;
  }
  else if(getNodeType() == EXPRESSION){
    s1 = print_operator();
  }
}

string Node::print_postfix() const{
  string s1 = "";
  if(getNodeType() == INTEGER) {
    s1 = int_to_string();
  }
  else if(getNodeType() == VARIABLE){
    s1 = this->data.var;
  }
  else if(getNodeType() == EXPRESSION){
    s1 = print_operator();
  }
}

string Node::int_to_string() const{
  string s = "";
  if (this->data.val >= 0 || this->data.val <= 9){ 
    string s = to_string(this->data.val);
    return s;
  }
}

node_type Node::getNodeType() const{
  return this->node_t;
}

char Node::print_operator() const{
  char c;
  if(this->data.op == PLUS){
    c = '+';
  }
  else if(this->data.op == MINUS){
    c = '-';
  }
  else if(this->data.op == MULT){
    c = '*';
  }
  else if(this->data.op == DIVIDE){
    c = '/';
  }
  return c;
}


Node* Node::get_operand1() const{
  return this->operand1;
}

Node* Node::get_operand2() const{
  return this->operand2;
}

Node* Node::get_parent() const{
  return this->parent;
}

void Node::change_operator(operator_type op){
  this->data.op = op;
}

void Node::change_operand1(Node *a){
  this->operand1 = a;
}

void Node::change_operand2(Node *a){
  this->operand2 = a;
}
void Node::setParent(Node *a){
   this->parent = a;
};


#endif
