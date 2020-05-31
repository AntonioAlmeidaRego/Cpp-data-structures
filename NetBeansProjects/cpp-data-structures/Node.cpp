/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.cpp
 * Author: antonio
 * 
 * Created on 30 de maio de 2020, 23:28
 */

#include "Node.h"

Node::Node() {
    this->key = 0;
    this->val = '0';
    this->next = nullptr;
    this->prev = nullptr;
}

Node::Node(int key, char val){
    this->key = key;
    this->val = val;
    this->next = nullptr;
    this->prev = nullptr;
}

Node::Node(const Node& orig) {
}

Node::~Node() {
}

Node * Node::getprev(){
    return this->prev;
}

Node * Node::getnext(){
    return this->next;
}

int Node::getkey(){
    return this->key;
}

char Node::getval(){
    return this->val;
}

void Node::setprev(Node* prev){
    this->prev = prev;
}

void Node::setnext(Node * next){
    this->next = next;
}

void Node::setkey(int key){
    this->key = key;
}

void Node::setval(char val){
    this->val = val;
}