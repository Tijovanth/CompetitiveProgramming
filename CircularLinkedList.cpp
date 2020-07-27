#include <iostream>
#include <stdio.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*head = NULL;

void create(int a[], int n){
    Node *t,*last;
    t = new Node;
    t->data = a[0];
    t->next = t;
    head = t;
    last = head;
    for(int i = 1; i < n; i++){
        t = new Node;
        t->data = a[i];
        t->next = last-> next;
        last->next = t;
        last = t;
    }
}

void display(Node *h){
    do{
        cout << h->data <<" ";
        h = h -> next;
    }while(h != head);
}

void displayRecursively(Node *h){
    static int flag = 0;
    if(h != head || flag == 0){
        flag = 1;
        cout << h->data << " ";
        displayRecursively(h->next);
    }
}

int Length(){
    Node *h = head;
    int length = 0;
    do{
        length++;
        h = h -> next;
    }while(h != head);
    return length;
}

void Insert(Node *h, int pos, int num){
    Node *t;
    t = new Node;
    t-> data = num;
    if(pos < 0 || pos > Length()){
        cout << "position invalid " << endl;
    }else{
    if(head == NULL){
        t -> next = t;
        head = t;
    }
    else if(pos == 0){
        do{
            h = h -> next;
        }while(h -> next != head);
        t -> next = head;
        h -> next = t;
        head = t;
    }else{
        for(int i = 0; i < pos - 1; i++)
            h = h -> next;
        t -> next = h -> next;
        h -> next = t;
    }
}
}

void Delete(Node *h, int pos){
    Node *q = NULL;
    if(pos == 1){

    }else{
         for(int i = 0; i < pos - 2; i++)
            h = h -> next;
        q = h -> next;
        h -> next = q -> next;
        delete q;
    }
   
}

int main(){
    int a[] = {10};
    create(a,1);
    //display(head);
    //displayRecursively(head);
    Insert(head,1,20);
    displayRecursively(head);
}