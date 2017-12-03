// Estefano Fodor, Juan Martinez
// October 29th, 2017
#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

enum node_type{EXPRESSION, VARIABLE, INTEGER};
enum operator_type{PLUS, MINUS, MULT, DIVIDE};

union data_type {
  operator_type op;
  char var;
  int val;
};

class Node {
 public:
    // Constructor
    Node(char var = 'x');
    Node(operator_type op = PLUS, Node* operand1 = NULL, Node* operand2 = NULL);
    Node(int val = 0);
    // Destructor
    ~Node();
    // Observers
    string print_infix() const;
    string print_prefix() const;
    string print_postfix() const;
    string int_to_string() const;
    char print_operator() const;
    node_type getNodeType() const;
    Node* get_operand1() const;
    Node* get_operand2() const;
    Node* get_parent() const;
    // Modifiers
    void setParent(Node *a);
    void change_operator(operator_type op);
    void change_operand1(Node *a);
    void change_operand2(Node *a);
 private:
    node_type node_t;
    data_type data;
    Node* operand1;
    Node* operand2;
    Node* parent;
};

#endif
