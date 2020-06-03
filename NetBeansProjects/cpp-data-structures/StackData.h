/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StackData.h
 * Author: antonio
 *
 * Created on 1 de junho de 2020, 16:42
 */

#ifndef STACKDATA_H
#define STACKDATA_H
#include "Node.h"

/*Classe StackData (Pilha)*/
class StackData {
    // Métodos Públicos
public:
    StackData();// constructor
    StackData(const StackData& orig);
    Node * push(int key, string label, string val);// método de inserção da pilha
    Node * push(Node *node); // método de inserção da pilha
    Node * update_stack(int index, int key); // método de atualizar a key da pilha a partir do indice
    Node * update_stack(int index, string val); // método de atualizar o val da pilha a partir do indice
    Node * update_stack_label(int index, string label); // método de atualizar a label da pilha a partir do indice
    Node * update_stack(int index, Node *node);// método de atualizar o node (somente key, val e label para não causar estrahos na pilha, caso alterasse alguma referencia dos ponteiros) da pilha a partir do indice
    Node * update_stack(int index, int key, string val); // método de atualizar a key e o val da pilha a partir do indice
    Node * update_stack(int index, int key, string val, string label);// método de atualizar a key, val e label da pilha a partir do indice
    int stack_size(); // método retorna o tamanho da pilha
    bool stack_empty(); // método retorna verdadeiro se a pilha está vazia ou falso
    Node * stack_topo(); // método retorna o primeiro nó que está na pilha
    Node * stack_last(); // método retorna o último nó que está na pilha
    Node * stack_getkey(int key);  // método retorna o nó que contenha o key
    Node * stack_getindex(int index);  // método retorna o nó que contenha o index
    Node * stack_getval(string val); // método retorna o nó que contenha o val
    Node * pop(); // método usado para remover da pilha
    int* stack_extract_keys();  // método usado para retornar um vetor de keys da pilha
    int* stack_extract_indexs();  // método usado para retornar um vetor de indexs da pilha
    string* stack_extract_values(); // método usado para retornar um vetor de values da pilha
    Node* stack_extract_nodes(); // método usado para retornar um vetor de nós da pilha
    void stack_print(); // método para imprimir a pilha
    virtual ~StackData();
private: // atributos e métodos privados
    int length; // atributo que será usado para mostrar o tamanho da pilha
    Node *head; // atributo no qual será usado para ter referencias dos nós da pilha (nó cabeça) 
    Node *syrup; // atributo no qual será usado para ter referencias dos nós da pilha (nó calda)
    int auto_increment = 1; // atributo usado para ter um controle dos indexs da pilha
    
    void update_auto_increment_stack();// método privado para atualizar os indexs, caso ocorra alguma remoção na pilha
    
    void auto_increment_stack(); // método privado para incrementar o atributo
};

#endif /* STACKDATA_H */

