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
    void enqueue(int key, char val);
    void enqueue(Node *node);
    int queue_size();
    bool queue_empty();
    Node * queue_first();
    Node * queue_last();
    Node * queue_getkey(int key); 
    Node * dequeue();
    void queue_print();
    virtual ~QueueData();
private:
    int length;
    Node *head; // nó cabeça
    Node *syrup; // nó calda
};

#endif /* QUEUE_H */

