/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: antonio
 *
 * Created on 30 de maio de 2020, 23:28
 */

#include <iostream>

#include "QueueData.h"

using namespace std;

/*
 * 
 */
void print_queue(){
    QueueData *queue = new QueueData();
    queue->enqueue(1, 'A');
    queue->enqueue(2, 'B');
    queue->enqueue(3, 'C');
    queue->enqueue(4, 'D');
    
    queue->queue_print();

    cout << endl;
    cout << "FIRT QUEUE --> KEY: " << queue->queue_first()->getkey() << " VAL: " <<
            queue->queue_first()->getval() << " ";
    
    cout << "\nLAST QUEUE --> KEY: " << queue->queue_last()->getkey() << " VAL: " <<
            queue->queue_last()->getval() << " ";
}

int main(int argc, char** argv) {
    print_queue();
    return 0;
}

