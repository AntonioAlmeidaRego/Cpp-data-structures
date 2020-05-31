/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: antonio
 *
 * Created on 30 de maio de 2020, 23:28
 */

#ifndef NODE_H
#define NODE_H 

#include <iostream>
#include <string.h>
using namespace std;

class Node {
public:
    Node();
    Node(int key, string val, string label); 
    Node(int index, int key, string val, string label);
    Node(const Node& orig);
    virtual ~Node();
    Node * getprev();
    Node * getnext();
    int getkey();
    string getval();
    string getlabel(); 
    int getindex();
    void setprev(Node *prev);
    void setnext(Node *next);
    void setkey(int key);
    void setval(string val);
    void setindex(int index);
    void setlabel(string label);     
private:
    int key;
    string val;
    Node *next;
    Node *prev;
    string label; 
    int index;
};

#endif /* NODE_H */

