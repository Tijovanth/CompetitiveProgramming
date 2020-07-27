#include <iostream>
#include <stdio.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node **hashTable; 

int Hash(int index){
    return index % 10;
}
void Insert(int index, int value){
    struct Node *t = new Node;
    t -> data = value;
    t -> next = NULL;
    if(hashTable[index] == NULL){
        hashTable[index] = t;
    }else{
        struct Node *p = hashTable[index];
        while(p -> next && p->next->data < value){
            p = p -> next;
        }
        if(p == hashTable[index] && p-> data > value){
            t -> next = p;
            hashTable[index] = t;
        }else{
            t -> next = p -> next;
            p -> next = t;
        }
    }
}

void CreateHash(int a[],int n){
    hashTable = new Node *[n];
    for(int i = 0; i < n; i++)
        hashTable[i] = NULL;
    for(int i = 0; i < n; i++){
        Insert(Hash(a[i]),a[i]);
    }
}

struct Node * Search(int key){
    int index = Hash(key);
    struct Node *p = hashTable[index];
    while(p){
        if(p -> data == key)
            return p;
        if(p -> data > key)
            return NULL;
        p = p -> next;
    }
    return NULL;
}

// int Delete(int key){
//     Node * p = Search(key);

// }
int main(){
    int a[] = {16,12,25,39,6,122,5,68,75};
    CreateHash(a,9);
    cout << Search(75)->data << " ";
}