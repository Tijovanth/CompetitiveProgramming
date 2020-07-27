#include <iostream>
#include <stdio.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int x){
    Node * t = new Node;
    if(t == NULL){
        cout << "Queue is full " << endl;
        return;
    }else{
        t -> data = x;
        t -> next = NULL;
        if(front == NULL)
            front = rear = t;
        else{
            rear -> next = t;
            rear = t;
        }
    }
}

int dequeue(){
    if(front == NULL)
        return -1;
    else{
        Node * p = front;
        front = front -> next;
        int x = p -> data;
        delete p;
        return x;
    }
}

void display(){
    Node * p = front;
    while(p){
        cout << p -> data << " ";
        p = p -> next;
    }
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    cout << dequeue();
}