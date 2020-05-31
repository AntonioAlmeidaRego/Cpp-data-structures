/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Queue.h
 * Author: antonio
 *
 * Created on 30 de maio de 2020, 23:41
 */

#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
class QueueData {
public:
    QueueData();
    QueueData(const QueueData& orig);
    Node * enqueue(int key, string val, string label);
    Node * enqueue(Node *node);
    Node * update_queue(int index, int key);
    Node * update_queue(int index, string val);
    Node * update_queue(int index, Node *node);
    int queue_size();
    bool queue_empty();
    Node * queue_first();
    Node * queue_last();
    Node * queue_getkey(int key); 
    Node * queue_getindex(int index); 
    Node * queue_getval(string val);
    Node * dequeue();
    int* queue_extract_keys(); 
    string* queue_extract_values();
    Node * queue_extract_nodes();
    void queue_print();
    virtual ~QueueData();
private:
    int length;
    Node *head; // nó cabeça
    Node *syrup; // nó calda
    int auto_increment = 1;
    
    void update_auto_increment_queue();
    
    void auto_increment_queue();
};

#endif /* QUEUE_H */

