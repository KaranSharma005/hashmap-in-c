#include<iostream>
using namespace std;

int getIndex(int key){
    return key%10;
}

int getIndex(float key){
    return ((int)key)%10;
}

int getIndex(string key){
    int num = 0;
    int size = key.size();
    for(int i=0;i<size;i++){
        num+=(int)key[i];
    }
    return num%10;
}

int getIndex(char* key){
    int num = 0;
    for(int i=0;key[i] !='\0';i++){
        num+=(int)key[i];
    }
    return num%10;
}