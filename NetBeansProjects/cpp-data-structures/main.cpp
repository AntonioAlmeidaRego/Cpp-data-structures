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
 
void print_dequeue_queue(QueueData *queue){
    Node *deque = queue->dequeue(); 
    cout << "-- DEQUEUE --" << endl;
    cout << endl;
    cout << "|INDEX|\t|KEY|\t|LABEL|\t\t|VALUE|\t";
    cout << endl;
    cout << " " << deque->getindex() << "\t"
         << " " << deque->getkey() << "\t"
         << " " << deque->getlabel() << "\t"
         << " " << deque->getval() << " \n";
    cout << endl;
}

void print_enqueue_queue(Node *node){ 
    cout << "-- ENQUEUE --" << endl;
    cout << endl;
    cout << "|INDEX|\t|KEY|\t|LABEL|\t\t|VALUE|\t";
    cout << endl;
    cout << " " << node->getindex() << "\t"
         << " " << node->getkey() << "\t"
         << " " << node->getlabel() << "\t"
         << " " << node->getval() << " \n";
    cout << endl;
}

void print_search_for_key_queue(QueueData *queue, int key){
    Node *aux = queue->queue_getkey(key);
    if(aux != nullptr){
        cout << "-- SEARCH FOR KEY --" << endl;
        cout << endl;
        cout << "|INDEX|\t|KEY|\t|LABEL|\t\t|VALUE|\t";
        cout << endl;
        cout << " " << aux->getindex() << "\t"
             << " " << aux->getkey() << "\t"
             << " " << aux->getlabel() << "\t"
             << " " << aux->getval() << " \n";
        cout << endl;
    }else{
        cout << "SEARCH FOR KEY --> " << " :( NOT FOUND " << endl;
    }
    cout << endl;
}

void print_search_for_index_queue(QueueData *queue, int index){
    Node *aux = queue->queue_getindex(index);
    if(aux != nullptr){
        cout << "-- SEARCH FOR INDEX -- " << endl;
        cout << endl;
        cout << "|INDEX|\t|KEY|\t|LABEL|\t\t|VALUE|\t";
        cout << endl;
        cout << " " << aux->getindex() << "\t"
             << " " << aux->getkey() << "\t"
             << " " << aux->getlabel() << "\t"
             << " " << aux->getval() << " \n";
        cout << endl;
    }else{
        cout << "SEARCH FOR INDEX --> " << " :( NOT FOUND " << endl;
    }
    cout << endl;
}

void print_search_for_value_queue(QueueData *queue, string value){
    Node *aux = queue->queue_getval(value);
    if(aux != nullptr){
        cout << "-- SEARCH FOR VAL -- " << endl;
        cout << endl;
        cout << "|INDEX|\t|KEY|\t|LABEL|\t\t|VALUE|\t";
        cout << endl;
        cout << " " << aux->getindex() << "\t"
             << " " << aux->getkey() << "\t"
             << " " << aux->getlabel() << "\t"
             << " " << aux->getval() << " \n";
        cout << endl;
        
    }else{
        cout << "SEARCH FOR VAL --> " << " :( NOT FOUND " << endl;
    }
    cout << endl;
}


void print_first_queue(QueueData *queue){
    cout << endl;
    cout << "-- FIRST QUEUE -- " << endl;
    Node *first = queue->queue_first();
    cout << endl;
    cout << "|INDEX|\t|KEY|\t|LABEL|\t\t|VALUE|\t";
    cout << endl;
    cout << " " << first->getindex() << "\t"
         << " " << first->getkey() << "\t"
         << " " << first->getlabel() << "\t"
         << " " << first->getval() << " \n";
    cout << endl;
}

void print_last_queue(QueueData *queue){
    cout << "-- LAST QUEUE -- " << endl;

    Node *last = queue->queue_last();
    cout << endl;
    cout << "|INDEX|\t|KEY|\t|LABEL|\t\t|VALUE|\t";
    cout << endl;
    cout << " " << last->getindex() << "\t"
         << " " << last->getkey() << "\t"
         << " " << last->getlabel() << "\t"
         << " " << last->getval() << " \n";
    cout << endl;
}

void print_queue(QueueData *queue){
    
    
    queue->queue_print();
    
    cout << endl;
   
}


void painel_queue(){
    QueueData *queue = new QueueData();
    int option;
    const string label = "TIME\t";
    do{
       
       cout << "| -- \t\tQUEUE DATA STRUCTURE \t\t -- |\t" << endl << endl;
       cout << "| -- \t\tOPTIONS BELOW \t\t\t -- |" << endl << endl;
       cout << "| -- \t\tTO ENQUEUE CLICK (1)\t\t -- |" << endl << endl;
       cout << "| -- \t\tTO DEQUEUE CLICK (2)\t\t -- |" << endl << endl;
       cout << "| -- \t\tTO PRINT CLICK (3)\t\t -- |" << endl << endl;
       cout << "| -- \t\tREPORT OPTION\t\t -- |" << endl << endl; 
       cin >> option;
       system("cls || clear");
       switch(option){
           case 1: 
              int key;
              string val;
              system("cls || clear");
              cout << "| -- \t\tREPORT KEY \t\t -- |\t" << endl << endl;
              cin >> key;
              system("cls || clear");
              cout << "| -- \t\tREPORT VALUE \t\t -- |\t" << endl << endl;
              getline (cin, val);
              system("cls || clear");
              print_enqueue_queue(queue->enqueue(key, val, label));
             break;
       } 
    }while(option != -1);
    
    queue->enqueue(90, "Time\t", "S.C. INTERNACIONAL");
    queue->enqueue(75, "Time\t", "SAO PAULO");
    queue->enqueue(65, "Time\t", "PALMEIRAS");
    queue->enqueue(64, "Time\t", "FLAMENGO");
    queue->enqueue(new Node(55, "Time\t", "VASCO"));
    
    print_dequeue_queue(queue);
    
    cout << "| -- \t\t BY ANTONIO ALMEIDA \t\t -- |\t" << endl << endl;
}

int main(int argc, char** argv) {
    painel_queue();
    return 0;
}

