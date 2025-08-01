#include<iostream>
#include "./library/genericHash.h"
#include "./library/nodeClass.h"
using namespace std;

int main(){
    // int key, value;
    // cout<<" Enter a key : \n";
    // cin>>key;

    // cout<<"Enter a value : \n";
    // cin>>value;
    int mapLength;
    cout<<"Enter the length of map : ";
    cin>>mapLength;
    

    int choice;
    HashMap<int , int> obj;
    obj.addInTable(1,2);
    obj.addInTable(3,4);

    obj.display();

    Node<int, int>* result = obj.search(1);
    if(result != NULL)
    cout<<"The value for key bcd is : "<<result -> val<<"\n\n";

    obj.deleteFromTable(1);
    obj.display();
    return 0;
}