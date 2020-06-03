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
#include "StackData.h"

using namespace std;

/*
 * 
 */
 
void print_dequeue_queue(QueueData *queue){
    Node *deque = queue->dequeue(); 
    if(deque != nullptr){
        cout << "| -- \t\tDEQUEUE DATA STRUCTURE \t\t -- |\t" << endl << endl;
        cout << endl;
        cout << "|INDEX|\t|KEY|\t|LABEL|\t\t|VALUE|\t";
        cout << endl;
        cout << " " << deque->getindex() << "\t"
             << " " << deque->getkey() << "\t"
             << " " << deque->getlabel() << "\t"
             << " " << deque->getval() << " \n";
        cout << endl;
    }
}

void print_enqueue_queue(Node *node){ 
    if(node != nullptr){
        cout << "| -- \t\tENQUEUE DATA STRUCTURE \t\t -- |\t" << endl << endl;
        cout << endl;
        cout << "|INDEX|\t|KEY|\t|LABEL|\t\t|VALUE|\t";
        cout << endl;
        cout << " " << node->getindex() << "\t"
             << " " << node->getkey() << "\t"
             << " " << node->getlabel() << "\t"
             << " " << node->getval() << " \n";
        cout << endl;
    }
}

void print_update_queue(Node *node){ 
    if(node != nullptr){
        cout << "| -- \t\tUPTADE DATA STRUCTURE \t\t -- |\t" << endl << endl;
        cout << endl;
        cout << "|INDEX|\t|KEY|\t|LABEL|\t\t|VALUE|\t";
        cout << endl;
        cout << " " << node->getindex() << "\t"
             << " " << node->getkey() << "\t"
             << " " << node->getlabel() << "\t"
             << " " << node->getval() << " \n";
        cout << endl;
    }
}

void print_search_for_key_queue(QueueData *queue, int key){
    cout << "| -- \t\tSEARCH FOR KEY DATA STRUCTURE \t\t -- |\t" << endl << endl;
    Node *aux = queue->queue_getkey(key);
    if(aux != nullptr){ 
        cout << endl;
        cout << "|INDEX|\t|KEY|\t|LABEL|\t\t|VALUE|\t";
        cout << endl;
        cout << " " << aux->getindex() << "\t"
             << " " << aux->getkey() << "\t"
             << " " << aux->getlabel() << "\t"
             << " " << aux->getval() << " \n";
        cout << endl;
    }else{
         cout << "| -- \t\tSEARCH FOR KEY --> " << " :( NOT FOUND \t\t --|\t" << endl << endl;
    }
    cout << endl;
}

void print_search_for_index_queue(QueueData *queue, int index){
    cout << "| -- \t\tSEARCH FOR INDEX DATA STRUCTURE \t\t -- |\t" << endl << endl;
    Node *aux = queue->queue_getindex(index);
    if(aux != nullptr){ 
        cout << endl;
        cout << "|INDEX|\t|KEY|\t|LABEL|\t\t|VALUE|\t";
        cout << endl;
        cout << " " << aux->getindex() << "\t"
             << " " << aux->getkey() << "\t"
             << " " << aux->getlabel() << "\t"
             << " " << aux->getval() << " \n";
        cout << endl;
    }else{
        cout << "| -- \t\tSEARCH FOR INDEX --> " << " :( NOT FOUND \t\t --|\t" << endl << endl;
    }
    cout << endl;
}

void print_search_for_value_queue(QueueData *queue, string value){
    cout << "| -- \t\tSEARCH FOR VALUE DATA STRUCTURE \t\t -- |\t" << endl << endl;
    Node *aux = queue->queue_getval(value);
    if(aux != nullptr){
        cout << endl;
        cout << "|INDEX|\t|KEY|\t|LABEL|\t\t|VALUE|\t";
        cout << endl;
        cout << " " << aux->getindex() << "\t"
             << " " << aux->getkey() << "\t"
             << " " << aux->getlabel() << "\t"
             << " " << aux->getval() << " \n";
        cout << endl;
        
    }else{
        cout << "| -- \t\tSEARCH FOR VAL --> " << " :( NOT FOUND \t\t --|\t" << endl << endl;
    }
    cout << endl;
}


void print_first_queue(QueueData *queue){
    cout << endl;
    cout << "| -- \t\tFIRST QUEUE DATA STRUCTURE \t\t -- |\t" << endl << endl;
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
    cout << "| -- \t\tLAST QUEUE DATA STRUCTURE \t\t -- |\t" << endl << endl;

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
    system("cls || clear");
    queue->queue_print();
    cout << endl;
    print_first_queue(queue);
    cout << endl;
    print_last_queue(queue);
}


void painel_queue(){
    QueueData *queue = new QueueData();
    int option;
    
    const string label = "TIME\t";
    do{ 
       cout << "| -- \t\tQUEUE DATA STRUCTURE \t\t -- |\t" << endl << endl;
       cout << "| -- \t\tOPTIONS BELOW \t\t\t -- |" << endl << endl;
       cout << "| -- \t\tTO ENQUEUE CLICK (1)\t\t -- |" << endl << endl;
       cout << "| -- \t\tTO UPDATE CLICK (2)\t\t -- |" << endl << endl;
       cout << "| -- \t\tTO DEQUEUE CLICK (3)\t\t -- |" << endl << endl;
       cout << "| -- \t\tTO PRINT CLICK (4)\t\t -- |" << endl << endl;
       cout << "| -- \t\tTO EXIT CLICK (-1)\t\t -- |" << endl << endl;
       cout << "| -- \t\tREPORT OPTION     \t\t -- |" << endl << endl; 
       cin >> option;
       system("cls || clear");
       switch(option){
           case 1: 
           {  
              int key;
              string val;
              system("cls || clear");
              cout << "| -- \t\tREPORT KEY \t\t -- |\t" << endl << endl;
              cin >> key;
              system("cls || clear");
              cout << "| -- \t\tREPORT VALUE (NOT USE SPACE) \t\t -- |\t" << endl << endl;
              cin >> val;
              system("cls || clear");
              print_enqueue_queue(queue->enqueue(key, label, val));
             break;}
           case 2:{
               int sub_option; 
               
               system("cls || clear");
               cout << "| -- \t\tOPTIONS BELOW \t\t\t -- |" << endl << endl;
               cout << "| -- \t\tTO UPDATE KEY CLICK (1)\t\t -- |" << endl << endl;
               cout << "| -- \t\tTO UPDATE VALUE CLICK (2)\t\t -- |" << endl << endl;
               cout << "| -- \t\tTO UPDATE KEY AND VALUE CLICK (3)\t\t -- |" << endl << endl;
               cout << "| -- \t\tTO BACK CLICK (4)\t\t -- |" << endl << endl;
               cout << "| -- \t\tREPORT OPTION     \t\t -- |" << endl << endl; 
               cin >> sub_option;
               switch(sub_option){
                   case 1:{
                      system("cls || clear");
                      int key;
                      int index;
                      cout << "| -- \t\tREPORT INDEX \t\t -- |\t" << endl << endl;
                      cin >> index;
                      system("cls || clear");
                      cout << "| -- \t\tREPORT KEY \t\t -- |\t" << endl << endl;
                      cin >> key;                       
                      system("cls || clear");
                      print_update_queue(queue->update_queue(index, key));
                      
                      break;} 
                   case 2: {
                       system("cls || clear");
                       string val;
                       int index;
                       cout << "| -- \t\tREPORT INDEX \t\t -- |\t" << endl << endl;
                       cin >> index;
                       system("cls || clear");
                       cout << "| -- \t\tREPORT VALUE (NOT USE SPACE) \t\t -- |\t" << endl << endl;
                       cin >> val;                       
                       system("cls || clear");
                       print_update_queue(queue->update_queue(index, val));
                       break;
                   }
                   case 3:{
                       int key;
                       string val;
                       system("cls || clear");
                       int index;
                       cout << "| -- \t\tREPORT INDEX \t\t -- |\t" << endl << endl;
                       cin >> index;
                       system("cls || clear");
                       cout << "| -- \t\tREPORT KEY \t\t -- |\t" << endl << endl;
                       cin >> key;
                       system("cls || clear");
                       cout << "| -- \t\tREPORT VALUE (NOT USE SPACE) \t\t -- |\t" << endl << endl;
                       cin >> val;
                       system("cls || clear");
                       print_update_queue(queue->update_queue(index, new Node(key, label, val)));
                       break;
                   }
                   case 4: {
                       option--;
                       system("cls || clear");
                       break;
                   }
               }
               break;
           }
           case 3: 
           {
               system("cls || clear");
               print_dequeue_queue(queue);
               break;
           }
           case 4:
               system("cls || clear");
               print_queue(queue);
               break;
       } 
    }while(option != -1); 
    
    
    cout << "| -- \t\t BY ANTONIO ALMEIDA @ 2020\t\t -- |\t" << endl << endl;
}

int main(int argc, char** argv) {
    painel_queue(); 
     
    return 0;
}

