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

Node * QueueData::enqueue(int key, string val, string label) {
    Node *node = new Node(auto_increment, key, val, label);
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

void QueueData::update_auto_increment_queue(){
    Node *aux = head->getnext();
    
    auto_increment = 1;
    
    while(aux != syrup){
        aux->setindex(auto_increment);
        auto_increment++;
        aux = aux->getnext();        
    }
}

Node* QueueData::dequeue(){
    Node *aux = head->getnext();
    Node *auxNext = aux->getnext();
    head->setnext(auxNext);
    auxNext->setprev(head);
    Node *retur = aux; 
    
    update_auto_increment_queue();
    
    return retur;
}

void QueueData::queue_print() {
    Node * aux = head->getnext();
    cout << "|INDEX|\t|KEY|\t|LABEL|\t\t|VALUE|\t";
    cout << endl;
    while (aux != syrup) {
        cout << " " << aux->getindex() << "\t"
             << " " << aux->getkey() << "\t"
             << " " << aux->getlabel() << "\t"
             << " " << aux->getval() << " \n";
        aux = aux->getnext();
    } 
}

