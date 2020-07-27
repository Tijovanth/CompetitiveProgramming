#include <iostream>
#include <stdio.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    struct Node *previous;
}*first = NULL;

void create(int a[],int n){
    Node *t,*last;
    t = new Node;
    t->data = a[0];
    t->next = NULL;
    t->previous = NULL;
    first = t;
    last = first;

    for(int i = 1; i < n; i++){
        t = new Node;
        t -> data = a[i];
        t -> next = NULL;
        t -> previous = last;
        last -> next = t;
        last = t;
    }
}

void display(Node *p){
    while(p != NULL){
        cout << p->data << " ";
        p = p -> next;
    }
}

void displayRecursively(Node *p){
    if( p == NULL){
        return;
    }
    cout << p -> data << " ";
    displayRecursively(p -> next);
}

int Length(){
    Node *p = first;
    int length = 0;
    while(p != NULL){
        length++;
        p = p -> next;
    }
    return length;
}

void Insert(Node *p, int pos, int num){
    Node *t, *last;
    t = new Node;
    t -> data = num;
    if(pos < 0 || pos > Length())
        return;
    if(pos == 0){
        t -> next = p;
        t -> previous = NULL;
        first -> previous = t;
        first = t;
    }else{
        for(int i = 0; i < pos - 1; i++)
            p = p -> next;
        t -> next = p -> next;
        t -> previous = p;
        if(p->next)
            p -> next -> previous = t;
        p -> next = t;
    }
}

 void Delete(Node *p,int pos){
     if(pos < 0 || pos > Length())
        return;
     if(pos == 1){
         first = p -> next;
         cout << p -> data << " " << endl;
         delete p;
         if(first -> previous)
            first -> previous = NULL;
     }else{
         for(int i = 0; i < pos - 1; i++)
            p = p -> next;
        p -> previous -> next = p -> next;
        if(p -> next){
            p -> next -> previous = p -> previous;
        }
        cout << p -> data << " " << endl;
        delete p;
     }
 }

 void ReversingDoublyLinkedList(Node *p){
     Node *q = NULL;
     while(p != NULL){
         q = p -> previous;
         p -> previous = p -> next;
         p -> next = q;
         first = p;
         p = p -> previous;
     }
 }

int main(){
    int a[] = {10,20,30,40,50};
    create(a,5);
    // display(first);
    // displayRecursively(first);
    //Insert(first,1,11);
    //Delete(first,1);
    //display(first);
    ReversingDoublyLinkedList(first);
    display(first);
}