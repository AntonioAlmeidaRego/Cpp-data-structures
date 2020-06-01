/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StackData.cpp
 * Author: antonio
 * 
 * Created on 1 de junho de 2020, 16:42
 */

#include "StackData.h"

StackData::StackData() {
    head = new Node();
    syrup = new Node();
    
    head->setnext(syrup);
    head->setprev(syrup);
    syrup->setnext(head);
    syrup->setprev(head);
    
    length = 0;
}

StackData::StackData(const StackData& orig) {
}

StackData::~StackData() {
}

bool StackData::stack_empty(){
    if(head->getnext() == syrup){
        return true;
    }
    return false;
}

int StackData::stack_size(){
    return length;
}

Node * StackData::stack_topo(){
    return syrup->getprev();
}

Node * StackData::stack_last(){
    return head->getnext();
}

Node * StackData::push(int key, string label, string val){
    length++;
    Node * node = new Node(auto_increment, key, label, val);
    if(stack_empty()){
        head->setnext(node);
        node->setprev(head);
        syrup->setprev(node);
        node->setnext(syrup);
    }else{
        Node * aux = syrup->getprev();
        aux->setnext(node);
        node->setprev(aux);
        node->setnext(syrup);
        syrup->setprev(node);
    }
}

Node * StackData::push(Node* node){
    length++;
    node->setindex(auto_increment);
    if(stack_empty()){
        head->setnext(node);
        node->setprev(head);
        syrup->setprev(node);
        node->setnext(syrup);
    }else{
        Node * aux = syrup->getprev();
        aux->setnext(node);
        node->setprev(aux);
        node->setnext(syrup);
        syrup->setprev(node);
    }
}

Node * StackData::pop(){
    length--;
    Node * aux = syrup->getprev();
    Node * antAux = aux->getprev();
    antAux->setnext(syrup);
    syrup->setprev(antAux);
}