#include <iostream>
#include <stdio.h>
using namespace std;

struct Stack{
    int top;
    int size;
    int *s;
};

struct Node{
    int data;
    struct Node *next;
}*first = NULL;

int isStackEmpty(struct Stack st){
    if(st.top == -1)
        return 1;
    else
        return 0;
}

int isStackFull(struct Stack st){
    if(st.top == st.size - 1)
        return 1;
    else
        return 0;
}

void push(struct Stack *st, int num){
    if(isStackFull(*st))
        return;
    else{
        st->top++;
        st->s[st->top] = num;
    }
    
}

void create(int a[], int n){
    Node * t = NULL, *last = NULL;
    t = new Node;
    t -> data = a[0];
    t -> next = NULL;
    first = last = t;
    for(int i = 1; i < n; i++){
        t = new Node;
        t -> data = a[i];
        last -> next = t;
        t -> next = NULL;
        last = t;
    }
}

void display(struct Node *p){
    while(p){
        cout << p -> data << " ";
        p = p -> next;
    }
}

int FindingMiddleInLinkedList(struct Stack *st,struct Node *p){
    while(p){
        push(st,p->data);
        p = p -> next;
    }
    return st -> s[(st->top + 1)/2];
}

int main(){
    Stack st;
    st.size = 7;
    st.top = -1;
    st.s = new int[st.size];
    int a[] = {1,2,3,4,5,6,7};
    create(a,7);
    //display(first);
    cout << FindingMiddleInLinkedList(&st,first);
}