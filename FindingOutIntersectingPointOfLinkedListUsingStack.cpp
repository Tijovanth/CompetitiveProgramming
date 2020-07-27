#include <iostream>
#include <stdio.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
Node *first = NULL, *second = NULL;

struct Stack{
    int size;
    int top;
    struct Node **s;
};

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

void Intersect(Node *p, int pos){
    Node * h = first;
    for(int i = 0; h != NULL && i < pos - 1; i++)
        h = h -> next;
    if(h)
        p -> next = h;
}

void createSecond(int a[], int n, int pos){
    Node * t = NULL, *last = NULL;
    t = new Node;
    t -> data = a[0];
    t -> next = NULL;
    second = last = t;
    for(int i = 1; i < n; i++){
        t = new Node;
        t -> data = a[i];
        last -> next = t;
        t -> next = NULL;
        last = t;
    }
    Intersect(last,pos);
}

void display(Node *p){
    while(p){
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}

int Length(struct Node *p){
    int count = 0;
    while(p){
        count++;
        p = p -> next;
    }
    return count;
}

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

void push(struct Stack *st, Node * p){
    if(isStackFull(*st))
        return;
    else{
        st->top++;
        st->s[st->top] = p;
    }
    
}

struct Node * pop(struct Stack *st){
    if(isStackEmpty(*st))
        return NULL;
    else{
        Node * x = st->s[st->top--];
        return x;
    }
}

void storingLinkedListInStack(struct Stack *st, Node * p){
    while(p){
        push(st,p);
        p = p -> next;
    }
}

int findingIntersectionPoint(struct Stack *firstStack, struct Stack *secondStack){
    Node * p = NULL;
    while(firstStack->s[firstStack->top] == secondStack->s[secondStack->top]){
        p = pop(firstStack);
        pop(secondStack);
    }
    return p -> data;
}

int main(){
    int a[] = {1,2,3,4,5,6,7,8};
    create(a,8);
    int b[] = {11,22,33,44};
    createSecond(b,4,4);
    display(first);
    display(second);
    Stack firstStack;
    firstStack.size = Length(first);
    firstStack.top = -1;
    firstStack.s =  (struct Node **)malloc(firstStack.size*sizeof(struct Node *));
    Stack secondStack;
    secondStack.size = Length(second);
    secondStack.top = -1;
    secondStack.s = (struct Node **)malloc(secondStack.size*sizeof(struct Node *));
    storingLinkedListInStack(&firstStack,first);
    storingLinkedListInStack(&secondStack,second);
    cout << findingIntersectionPoint(&firstStack,&secondStack);
}