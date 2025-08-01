#include<iostream>
#include "./nodeClass.h"
#include "./gIndex.h"
using namespace std;

template<typename HASHKEY, typename HASHVALUE>
class HashMap{
    private : 
    Node<HASHKEY,HASHVALUE>** arr;
    public : 
    HashMap(){
        arr = new Node<HASHKEY,HASHVALUE> *[10];
        for(int i=0;i<10;i++){
            arr[i] = NULL;
        }
    }
    void addInTable(HASHKEY key, HASHVALUE val);
    void deleteFromTable(HASHKEY key);
    void display();
    Node<HASHKEY, HASHVALUE>* search(HASHKEY key);
};

template<typename HASHKEY, typename HASHVALUE>
Node<HASHKEY, HASHVALUE>* HashMap<HASHKEY,HASHVALUE> :: search(HASHKEY key){
    int index = getIndex(key);
    Node<HASHKEY, HASHVALUE>* temp = arr[index];

    while(temp && temp -> key != key){
        temp = temp -> next;
    }
    if(temp == NULL){
        cout<<"No key found\n\n";
        return NULL;
    }
    else{
        return temp;
    }
}

template<typename HASHKEY, typename HASHVALUE>
void HashMap<HASHKEY,HASHVALUE> :: addInTable(HASHKEY key, HASHVALUE val){
    int index = getIndex(key);
    Node<HASHKEY, HASHVALUE>* newNode = new Node<HASHKEY, HASHVALUE>(key, val);
    if(arr[index] == NULL){
        arr[index] = newNode;
        cout<<"Added Successfully\n\n";
    }
    else{
        Node<HASHKEY, HASHVALUE>* temp = arr[index];
        while(temp -> next && temp -> key != key){
            temp = temp -> next;
        }
        if(temp -> next == NULL && temp -> key != key){
            temp -> next = newNode;
            cout<<"Added Successfully\n\n";
        }
        else{
            cout<<"Key alreaady exists \n\n";
        }
    }
}

template<typename HASHKEY, typename HASHVALUE>
void HashMap<HASHKEY,HASHVALUE> :: deleteFromTable(HASHKEY key){
    int index = getIndex(key);
    Node<HASHKEY, HASHVALUE>* temp = arr[index];
    Node<HASHKEY, HASHVALUE>* tail = NULL;

    if(temp == NULL){
        cout<<"No key exist\n\n";
    }
    else if(temp -> key == key){
        arr[index] = temp -> next;
    }
    else{
        while(temp && temp -> key != key){
            tail = temp;
            temp = temp -> next;
        }
        if(temp == NULL){
            cout<<"No key exist\n\n";
        }
        else{
            tail -> next = temp -> next;
        }
    }
    cout<<key<<" Key deleted \n\n";
}

template<typename HASHKEY, typename HASHVALUE>
void HashMap<HASHKEY,HASHVALUE> :: display(){
    cout<<"{\n";
    for(int i=0;i<10;i++){
        Node<HASHKEY, HASHVALUE>* temp = arr[i];
        while(temp){
            cout<<"    {"<<temp -> key<<", "<<temp -> val<<"},\n";
            temp = temp -> next;
        }
    }
    cout<<"}\n";
}