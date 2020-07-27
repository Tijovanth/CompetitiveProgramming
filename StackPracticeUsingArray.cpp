# include<iostream>
# include <stdio.h>
using namespace std;

struct Stack{
    int size;
    int top;
    int *s;
};

int isStackFull(struct Stack st){
    if(st.top == st.size - 1)
        return 1;
    else
        return 0;
}

int isStackEmpty(struct Stack st){
    if(st.top == -1)
        return 1;
    else
        return 0;
}

void push(struct Stack *st, int num){
    if(isStackFull(*st))
        cout << "Stack Over flow " << endl;
    else{
        st->top++;
        st->s[st->top] = num;
    }  
}

int pop(struct Stack *st){
    if(isStackEmpty(*st)){
        cout << "Stack Under Flow " << endl;
        return -1;
    }
    else{
        int x = st -> s[st ->top--];
       // st -> top--;
        return x;
    }
}

int peek(struct Stack st, int pos){
    if(st.top - pos + 1 < 0 || st.top - pos + 1 > st.top)
        return -1;
    else{
        return st.s[st.top - pos + 1];
    }
}

void display(struct Stack st){
    for(int i = st.top; i > -1; i--){
        cout << st.s[i] << endl;
    }
}

int stackTop(struct Stack st){
    if(isStackEmpty(st))
        return -1;
    else
        return st.s[st.top];
}

int main(){
    Stack st;
    cout << "Enter the size of the stack";
    cin >> st.size;
    st.s = new int[st.size];
    st.top = -1;
    push(&st,1);
    push(&st,2);
    push(&st,3);
    push(&st,4);
    push(&st,5);
    cout << pop(&st) << endl;
    cout << peek(st,0) << endl;
    display(st);
    cout << stackTop(st) << endl;
}