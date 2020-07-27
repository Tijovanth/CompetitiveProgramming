#include <iostream>
#include <stdio.h>
using namespace std;


struct Node{
    int data;
    struct Node *next;
    struct Node *previous;
}*head = NULL;

void Insert(Node *h, int pos, int num){
    Node *t;
    t = new Node;
    t -> data = num;
    if(pos == 0){
        if(h == NULL){
            t -> next = t;
            t -> previous = t;
            head = t;
        }else{
           t -> previous = head -> previous;
           head -> previous = t;
           t -> next = head;
           t -> previous -> next = t;
           head = t;
        }
    }else{
        for(int i = 0; i < pos - 1; i++)
            h = h -> next;
        t -> next = h -> next;
        t -> previous = h;
        h -> next -> previous = t;
        h -> next = t;
    }
}

void display(Node *h){
    do{
        cout << h -> data << " ";
        h = h -> next;
    }while(h != head);
    cout << endl;
}

void Delete(Node *h, int pos){
    if(pos == 1){
        h -> next -> previous = h -> previous;
        h -> previous -> next = h -> next;
        head = h -> next;
        delete h;
    }else{
        for(int i = 0; i < pos - 1; i++)
            h = h -> next;
        h -> previous -> next = h -> next;
        h -> next -> previous = h -> previous;
        delete h;
    }
}

 int main(){
    Insert(head,0,10);
    Insert(head,1,20);
    Insert(head,2,30);
    //display(head);
    Insert(head,0,5);
    //display(head);
    Delete(head,3);
    display(head);
 }