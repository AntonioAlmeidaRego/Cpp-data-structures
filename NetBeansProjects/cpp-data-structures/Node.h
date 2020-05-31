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

class Node {
public:
    Node();
    Node(int key, char val);
    Node(const Node& orig);
    virtual ~Node();
    Node * getprev();
    Node * getnext();
    int getkey();
    char getval();
    void setprev(Node *prev);
    void setnext(Node *next);
    void setkey(int key);
    void setval(char val);
private:
    int key;
    char val;
    Node *next;
    Node *prev;
};

#endif /* NODE_H */

