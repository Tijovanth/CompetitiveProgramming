# include <iostream>
# include <stdio.h>
using namespace std;

struct Node{
    int data;
    struct Node * next;
}*top = NULL;

int isStackFull(){
    Node *t = new Node;
    int r = t == NULL ? 1 : 0;
    delete t;
    return r;
}

int isStackEmpty(){
    return top == NULL ? 1 : 0;
}

int stackTop(){
    if(top)
        return top->data;
    else
        return -1;
}

void push(int num){
    if(isStackFull())
        cout << "Stack Over Flow " << endl;
    else{
        Node *t = new Node;
        t -> data = num;
        t -> next = top;
        top = t;
    }
}

int pop(){
    if(isStackEmpty()){
        cout << "Stack UnderFlow " << endl;
        return -1;
    }else{
        Node * p = top;
        top = top -> next;
        int x = p -> data;
        delete p;
        return x;
    }
}

int peek(int pos){
    if(isStackEmpty()){
        cout << "Stack UnderFlow " << endl;
        return -1;
    }else{
        Node *p = top;
        for(int i = 0; p != NULL && i < pos - 1; i++){
            p = p -> next;
        }
        if(p)
            return p->data;
        else
            return -1;
    }
}

int main(){
    push(1);
    push(2);
    push(3);
    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
    push(1);
    cout << peek(0) << endl;
    cout << pop() << endl;
    cout << peek(0) << endl;
    cout << stackTop() << endl;
}
