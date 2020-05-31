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
    this->head = new Node();
    this->syrup = new Node();
    length = 0;
    
    this->head->setnext(this->syrup);
    this->head->setprev(this->syrup);
    this->syrup->setnext(this->head);
    this->syrup->setprev(this->head);
} 

QueueData::QueueData(const QueueData& orig) {
}

QueueData::~QueueData() {
}

bool QueueData::queue_empty(){
    if(this->head->getnext() == this->syrup){
        return true;
    }
    return false;
}

void QueueData::enqueue(int key, char val){
    Node *node = new Node(key, val);
    length++;
    if(queue_empty()){
        this->head->setnext(node);
        this->syrup->setprev(node);
        node->setnext(this->syrup);
        node->setprev(this->head);        
    }else{
        Node * aux = this->syrup->getprev();
        aux->setnext(node);
        node->setprev(aux);
        node->setnext(syrup);
        syrup->setprev(node);
    }
}

Node * QueueData::queue_first(){
    return this->head->getnext();
}

Node * QueueData::queue_last(){
    return this->syrup->getprev();
}

Node * QueueData::queue_getkey(int key){
    Node * aux = this->head->getnext();
    
    while(aux != this->syrup){
        if(aux->getkey() == key){
            return aux;
        }
        aux = aux->getnext();
    }
    
    return nullptr;
}

void QueueData::queue_print(){
    Node * aux = this->head->getnext();
    
    while(aux != this->syrup){
        cout << "KEY: " << aux->getkey() << " " << "VAL: " << aux->getval() << " \n"; 
        aux = aux->getnext();
    }
}

