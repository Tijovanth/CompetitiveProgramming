# include <iostream>
# include <stdio.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*top1 = NULL, *top2 = NULL;

int isStackEmpty(){
    return top1 != NULL ? 0 : 1;
}

int isStackEmpty2(){
    return top2 != NULL ? 0 : 1;
}

int isStackFull(){
    Node *t = new Node;
    int r = t == NULL ? 1 : 0;
    delete t;
    return r;
}

void push(int x){
    if(isStackFull()){
        cout << "Stack is Full " << endl;
        return;
    }else{
        Node * t = new Node;
        t -> data = x;
        t -> next = top1;
        top1 = t;
    }
}

void push2(int x){
    if(isStackFull()){
        cout << "Stack is Full " << endl;
        return;
    }else{
        Node * t = new Node;
        t -> data = x;
        t -> next = top2;
        top2 = t;
    }
}

int pop(){
    if(isStackEmpty()){
        cout << "Stack is Empty " << endl;
        return -1;
    }else{
        Node * p = top1;
        top1 = top1 -> next;
        int x = p -> data;
        delete p;
        return x;
    }
}

int pop2(){
    if(isStackEmpty2()){
        cout << "Stack is Empty " << endl;
        return -1;
    }else{
        Node * p = top2;
        top2 = top2 -> next;
        int x = p -> data;
        delete p;
        return x;
    }
}

void enqueue(int num){
    push(num);
}

int dequeue(){
    if(isStackEmpty2()){
        if(isStackEmpty()){
            cout << "Queue is empty " << endl;
            return -1;
        }else{
            while(top1){
                push2(pop());
            }
        }
    }
    return pop2();
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl;
}