#pragma once
#include<iostream>
using namespace std;
template <typename HASHKEY, typename HASHVALUE>
class Node{
    public : 
    HASHKEY key;
    HASHVALUE val;
    Node* next;
    //Constructors
    Node(HASHKEY key, HASHVALUE val) {
        this -> val = val;
        this -> key = key;
        this -> next = NULL;
    }
};