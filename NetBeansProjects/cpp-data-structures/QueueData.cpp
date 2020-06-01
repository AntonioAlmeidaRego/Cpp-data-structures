/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Queue.cpp
 * Author: antonio
 * 
 * Created on 30 de maio de 2020, 23:41
 */
#include <iostream>
#include "QueueData.h" 

using namespace std;

QueueData::QueueData() {
    head = new Node();
    syrup = new Node();
    length = 0;

    head->setnext(syrup);
    head->setprev(syrup);
    syrup->setnext(head);
    syrup->setprev(head);
}

QueueData::QueueData(const QueueData& orig) {
}

QueueData::~QueueData() {
}

bool QueueData::queue_empty() {
    if (head->getnext() == syrup) {
        return true;
    }
    return false;
}

Node * QueueData::enqueue(Node *node){
    length++;
    node->setindex(auto_increment);
    auto_increment_queue();
    if (queue_empty()) {
        head->setnext(node);
        syrup->setprev(node);
        node->setnext(syrup);
        node->setprev(head);
    } else {
        Node * aux = syrup->getprev();
        aux->setnext(node);
        node->setprev(aux);
        node->setnext(syrup);
        syrup->setprev(node);
    }
    
    return node;
}

void QueueData::auto_increment_queue(){
    auto_increment++;
}

Node * QueueData::enqueue(int key, string label, string val) {
    Node *node = new Node(auto_increment, key, label, val);
    auto_increment_queue();
    length++;
    if (queue_empty()) {
        head->setnext(node);
        syrup->setprev(node);
        node->setnext(syrup);
        node->setprev(head);
    } else {
        Node * aux = syrup->getprev();
        aux->setnext(node);
        node->setprev(aux);
        node->setnext(syrup);
        syrup->setprev(node);
    }
    
    return node;
}

Node * QueueData::queue_first() {
    return head->getnext();
}

Node * QueueData::queue_last() {
    return syrup->getprev();
}

Node * QueueData::queue_getkey(int key) {
    Node * aux = head->getnext();

    while (aux != syrup) {
        if (aux->getkey() == key) {
            return aux;
        }
        aux = aux->getnext();
    }

    return nullptr;
}

Node * QueueData::queue_getindex(int index){
    Node * aux = head->getnext();

    while (aux != syrup) {
        if (aux->getindex() == index) {
            return aux;
        }
        aux = aux->getnext();
    }

    return nullptr;
}
 
Node * QueueData::queue_getval(string val){
    Node * aux = head->getnext();

    while (aux != syrup) {
        if (aux->getval() == val) {
            return aux;
        }
        aux = aux->getnext();
    }

    return nullptr;
}

Node * QueueData::update_queue(int index, int key){
    Node * node = queue_getindex(index);
    if(node != nullptr){
        node->setkey(key);
        return node;
    }
    return nullptr;
}

Node * QueueData::update_queue(int index, string val){
    Node * node = queue_getindex(index);
    if(node != nullptr){
        node->setval(val);
        return node;
    }
    return nullptr;
}

Node * QueueData::update_queue(int index, Node *node){
    Node * node_aux = queue_getindex(index);
    if(node_aux != nullptr){
        node_aux->setkey(node->getkey());
        node_aux->setval(node->getval());
        return node_aux;
    }
    return nullptr;
}

Node * QueueData::update_queue(int index, int key, string val){
    Node * node_aux = queue_getindex(index);
    if(node_aux != nullptr){
        node_aux->setkey(key);
        node_aux->setval(val);
        return node_aux;
    }
    return nullptr;
}

void QueueData::update_auto_increment_queue(){
    Node *aux = head->getnext();
    
    auto_increment = 1;
    
    while(aux != syrup){
        aux->setindex(auto_increment);
        auto_increment++;
        aux = aux->getnext();        
    }
}

int * QueueData::queue_extract_keys(){
    int *array = new int[length];
    
    Node * aux = head->getnext();
    int index = 0;
    while (aux != syrup) {
        array[index] = aux->getkey();
        aux = aux->getnext();
        index++;
    } 
    
    return array;
}
 
string* QueueData::queue_extract_values(){ 
    string *array = new string[length];
    Node * aux = head->getnext();
    int index = 0;
    while (aux != syrup) {
        array[index] = aux->getval();
        aux = aux->getnext(); 
        index++;
    } 
    
    return array;
}

Node* QueueData::queue_extract_nodes(){ 
    Node *array = new Node[length];
    Node * aux = head->getnext();
    int index = 0;
    while (aux != syrup) {
        array[index] = *aux;
        aux = aux->getnext(); 
        index++;
    } 
    
    return array;
}

int QueueData::queue_size(){
    return length;
}

Node* QueueData::dequeue(){
    if(!queue_empty()){
        length--;
        Node *aux = head->getnext();
        Node *auxNext = aux->getnext();
        head->setnext(auxNext);
        auxNext->setprev(head);
        Node *retur = aux; 
    
        update_auto_increment_queue();
    
        return retur;
    }
    return nullptr;
}

void QueueData::queue_print() {
    system("cls || clear");
    Node * aux = head->getnext();
    
    if(queue_empty()){
        cout << "| -- \t\tEMPTY QUEUE DATA STRUCTURE \t\t -- |\t" << endl; 
    }else{
        cout << "|INDEX|\t|KEY|\t|LABEL|\t\t|VALUE|\t";
        cout << endl;
    }
    while (aux != syrup) {
        cout << " " << aux->getindex() << "\t"
             << " " << aux->getkey() << "\t"
             << " " << aux->getlabel() << "\t"
             << " " << aux->getval() << " \n";
        aux = aux->getnext();
    } 
}

