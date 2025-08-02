#include<iostream>
#include "./library/genericHash.h"
#include "./library/nodeClass.h"
using namespace std;

int main(){
    int mapLength;
    cout<<"Enter the length of map : ";
    cin>>mapLength;
    HashMap<int , int> obj(mapLength);
    int choice;
    do{
        cout<<"Enter 1 to add into hashmap\n";
        cout<<"Enter 2 to delete from hashmap\n";
        cout<<"Enter 3 to display the map\n";
        cout<<"Enter 4 to search for key\n";
        cout<<"Enter 0 to exit\n";
        cin>>choice;
        int key, value;
        if(choice == 1){
            cout<<"Enter key : ";
            cin>>key;
            cout<<"Enter value : ";
            cin>>value;
            obj.addInTable(key,value);
        }
        else if(choice == 2){
            cout<<"Enter key : ";
            cin>>key;
            obj.deleteFromTable(key);
        }
        else if(choice == 3){
            obj.display();
        }
        else if(choice == 4){
            cout<<"Enter key to search : ";
            cin>>key;
            obj.search(key);
        }
        else{
            cout<<"Invalid choice\n\n";
        }   
    }while(choice);
    obj.setValue(1,1);
    obj.display();
    return 0;
}