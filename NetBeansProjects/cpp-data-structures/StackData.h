/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StackData.h
 * Author: antonio
 *
 * Created on 1 de junho de 2020, 16:42
 */

#ifndef STACKDATA_H
#define STACKDATA_H
#include "Node.h"
class StackData {
public:
    StackData();
    StackData(const StackData& orig);
    Node * push(int key, string label, string val);
    Node * push(Node *node);
    Node * update_stack(int index, int key);
    Node * update_stack(int index, string val);
    Node * update_stack(int index, Node *node);
    Node * update_stack(int index, int key, string val);
    int stack_size();
    bool stack_empty();
    Node * stack_topo();
    Node * stack_last();
    Node * stack_getkey(int key); 
    Node * stack_getindex(int index); 
    Node * stack_getval(string val);
    Node * pop();
    int* stack_extract_keys(); 
    string* stack_extract_values(); 
    Node* stack_extract_nodes(); 
    void stack_print();
    virtual ~StackData();
private:
    int length;
    Node *head; // nó cabeça
    Node *syrup; // nó calda
    int auto_increment = 1;
    
    void update_auto_increment_queue();
    
    void auto_increment_queue();
};

#endif /* STACKDATA_H */

