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
    auto_increment_stack();
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

void StackData::auto_increment_stack(){
    auto_increment++;
}

Node * StackData::push(Node* node){
    length++;
    node->setindex(auto_increment);
    auto_increment_stack();
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

void StackData::update_auto_increment_stack(){
    Node *aux = head->getnext();
    
    auto_increment = 1;
    
    while(aux != syrup){
        aux->setindex(auto_increment);
        auto_increment++;
        aux = aux->getnext();        
    }
}

Node * StackData::pop(){
    if(!stack_empty()){
        length--;
        Node * aux = syrup->getprev();
        Node * antAux = aux->getprev();
        antAux->setnext(syrup);
        syrup->setprev(antAux);
        Node *retur = aux; 
        
        update_auto_increment_stack();
        
        return retur;
    }
    
    return nullptr;
}

void StackData::stack_print(){
    system("cls || clear");
    
    Node * aux = syrup->getprev();
    
    if(stack_empty()){
        cout << "| -- \t\tEMPTY STACK DATA STRUCTURE \t\t -- |\t" << endl; 
    }else{
        cout << "|INDEX|\t|KEY|\t|LABEL|\t\t|VALUE|\t";
        cout << endl;
    }
    while (aux != head) {
        cout << " " << aux->getindex() << "\t"
             << " " << aux->getkey() << "\t"
             << " " << aux->getlabel() << "\t"
             << " " << aux->getval() << " \n";
        aux = aux->getprev();
    } 
}

Node * StackData::stack_getindex(int index){
    Node * aux = syrup->getprev();
    
    while(aux != head){
        if(aux->getindex() == index){
            return aux;
        }
        aux = aux->getprev();
    }
    
    return nullptr;
}

Node * StackData::update_stack(int index, int key){
    Node * auxIndex = stack_getindex(index);
    
    if(auxIndex != nullptr){
        auxIndex->setkey(key);
        return auxIndex;
    }
    
    return nullptr;
}

Node * StackData::update_stack(int index, string val){
    Node * auxIndex = stack_getindex(index);
    
    if(auxIndex != nullptr){
        auxIndex->setval(val);
        return auxIndex;
    }
    
    return nullptr;
}

Node * StackData::update_stack_label(int index, string label){
    Node * auxIndex = stack_getindex(index);
    
    if(auxIndex != nullptr){
        auxIndex->setlabel(label);
        return auxIndex;
    }
    
    return nullptr;
}

Node * StackData::update_stack(int index, Node *node){
    Node * auxIndex = stack_getindex(index);
    
    if(auxIndex != nullptr){
        auxIndex->setval(node->getval());
        auxIndex->setkey(node->getkey());
        auxIndex->setlabel(node->getlabel());
        return auxIndex;
    }
    
    return nullptr;
}


Node * StackData::update_stack(int index, int key, string val, string label){
    Node * auxIndex = stack_getindex(index);
    
    if(auxIndex != nullptr){
        auxIndex->setval(val);
        auxIndex->setkey(key);
        auxIndex->setlabel(label);
        return auxIndex;
    }
    
    return nullptr;
}


Node * StackData::update_stack(int index, int key, string val){
    Node * auxIndex = stack_getindex(index);
    
    if(auxIndex != nullptr){
        auxIndex->setval(val);
        auxIndex->setkey(key);
        return auxIndex;
    }
    
    return nullptr;
}

string* StackData::stack_extract_values(){
    string *array = new string[length];
    
    int index = 0;
    Node * aux = syrup->getprev();
    
    while(aux != head){
        array[index] = aux->getval();
        index++;
        aux = aux->getprev();
    }
    
    return array;
}

Node* StackData::stack_extract_nodes(){
    Node *array = new Node[length];
    
    int index = 0;
    Node * aux = syrup->getprev();
    
    while(aux != head){
        array[index] = *aux;
        index++;
        aux = aux->getprev();
    }
    
    return array;
}

int* StackData::stack_extract_indexs(){
    int *array = new int[length];
    
    int index = 0;
    Node * aux = syrup->getprev();
    
    while(aux != head){
        array[index] = aux->getindex();
        index++;
        aux = aux->getprev();
    }
    
    return array;
}

int* StackData::stack_extract_keys(){
    int *array = new int[length];
    
    int index = 0;
    Node * aux = syrup->getprev();
    
    while(aux != head){
        array[index] = aux->getkey();
        index++;
        aux = aux->getprev();
    }
    
    return array;
}

Node * StackData::stack_getkey(int key){
    Node * aux = syrup->getprev();
    
    while(aux != head){
        if(aux->getkey() == key){
            return aux;
        }
        aux = aux->getprev();
    }
    
    return nullptr;
}

Node * StackData::stack_getval(string val){
    Node * aux = syrup->getprev();
    
    while(aux != head){
        if(aux->getval() == val){
            return aux;
        }
        aux = aux->getprev();
    }
    
    return nullptr;
}