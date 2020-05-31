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
using namespace std;

Node::Node() {
    key = 0; 
    label = "";
    val = "";
    next = nullptr;
    prev = nullptr; 
}

Node::Node(int key, string label, string val){
    this->key = key;
    this->val = val; 
    this->label = label;
    next = nullptr;
    prev = nullptr; 
}

Node::Node(int index, int key, string label, string val){
    this->key = key;
    this->val = val; 
    this->label = label;
    next = nullptr;
    prev = nullptr; 
    this->index = index;
}

Node::Node(const Node& orig) {
}

Node::~Node() {
}

Node * Node::getprev(){
    return prev;
}

Node * Node::getnext(){
    return next;
}

int Node::getkey(){
    return key;
}

string Node::getval(){
    return val;
}

string Node::getlabel(){
    return label;
}

int Node::getindex(){
    return index;
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

void Node::setval(string val){
    this->val = val;
}

void Node::setlabel(string label){
    this->label = label;
}

void Node::setindex(int index){
    this->index = index;
}


