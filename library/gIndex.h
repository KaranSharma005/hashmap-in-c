#include<iostream>
using namespace std;

int getIndex(int key, int size){
    return key%size;
}

int getIndex(float key, int size){
    return ((int)key)%size;
}

int getIndex(string key, int size){
    int num = 0;
    int s = key.size();
    for(int i=0;i<s;i++){
        num+=(int)key[i];
    }
    return num%size;
}

int getIndex(char* key, int size){
    int num = 0;
    for(int i=0;key[i] !='\0';i++){
        num+=(int)key[i];
    }
    return num%size;
}