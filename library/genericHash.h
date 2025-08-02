#include<iostream>
#include "./nodeClass.h"
#include "./gIndex.h"
using namespace std;

template<typename K, typename V>
class HashMap{
    private : 
    Node<K,V>** arr;
    int length;
    int filled;
    public : 
    HashMap(int length){
        this -> length = length;
        arr = new Node<K,V> *[length];
        for(int i=0;i<length;i++){
            arr[i] = NULL;
        }
    }
    void addInTable(K key, V val);
    void deleteFromTable(K key);
    void display();
    void resize();
    Node<K, V>* search(K key);
};
template<typename K, typename V>
void HashMap<K,V> :: resize(){
    int temp = length;
    length = length*2;
    filled = 0;
    Node<K,V>** dummy = arr;
    arr = new Node<K,V> *[length];
    for(int i=0;i<length;i++){
        arr[i] = NULL;
    }

    for(int i=0;i<temp;i++){
        Node<K, V>* temp = dummy[i];
        while(temp){
            addInTable(temp -> key, temp -> val);
            temp = temp -> next;
        }
    }
    int count = 0;
    for(int i=0;i<length;i++){
        if(arr[i] != NULL)
        count++;
    }
    filled = count;
}

template<typename K, typename V>
Node<K, V>* HashMap<K,V> :: search(K key){
    int index = getIndex(key,length);
    Node<K, V>* temp = arr[index];

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

template<typename K, typename V>
void HashMap<K,V> :: addInTable(K key, V val){
    int index = getIndex(key, length);
    Node<K, V>* newNode = new Node<K, V>(key, val);
    if(arr[index] == NULL){
        arr[index] = newNode;
        cout<<"Added Successfully\n\n";
        filled++;
    }
    else{
        Node<K, V>* temp = arr[index];
        while(temp -> next && temp -> key != key){
            temp = temp -> next;
        }
        if(temp -> next == NULL && temp -> key != key){
            temp -> next = newNode;
            cout<<"Added Successfully\n\n";
            filled++;
        }
        else{
            cout<<"Key alreaady exists \n\n";
        }
    }
    int threshold = (filled*100)/length;
    if(threshold >= 75){
        cout<<"Threshhold \n";
        resize();
    }
}

template<typename K, typename V>
void HashMap<K,V> :: deleteFromTable(K key){
    int index = getIndex(key, length);
    Node<K, V>* temp = arr[index];
    Node<K, V>* tail = NULL;

    if(temp == NULL){
        cout<<"No key exist\n\n";
    }
    else if(temp -> key == key){
        arr[index] = temp -> next;
        filled--;
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
        filled--;
        
        cout<<key<<" Key deleted \n\n";
    }
}

template<typename K, typename V>
void HashMap<K,V> :: display(){
    cout<<"{\n";
    for(int i=0;i<length;i++){
        Node<K, V>* temp = arr[i];
        while(temp){
            cout<<"    {"<<temp -> key<<", "<<temp -> val<<"},\n";
            temp = temp -> next;
        }
    }
    cout<<"}\n";
    cout<<length<<"\n";
}