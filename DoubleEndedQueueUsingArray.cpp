#include <iostream>
#include <stdio.h>
using namespace std;

struct Queue{
    int front;
    int rear;
    int size;
    int *s;
};

void enqueueUsingfront(struct Queue *q, int x){
    if(q -> front == -1){
        cout << "In this side queue is full check another side " << endl;
        return;
    }else{
        q -> s[q ->front] = x;
        q -> front--;
    }
}

void enqueueUsingRear(struct Queue *q, int x){
    if(q->rear == q->size - 1)
        return;
    else{
        q -> rear++;
        q -> s[q -> rear] = x; 
    }  
}

int dequeueUsingfront(struct Queue *q){
    if(q->front == q->rear)
        return -1;
    else{
        q -> front++;
        return q -> s[q -> front];
    }
}

int dequeueUsingRear(struct Queue *q){
    if(q -> rear == -1 || q -> rear == q -> front){
        cout << "Queue is empty " << endl;
        return -1;
    }else{
        int x = q -> s[q -> rear];
        q -> rear--;
        return x;
    }
}

void display(struct Queue *q){
    for(int i = q->front + 1; i <= q -> rear; i++){
        cout << q -> s[i] << " ";
    }
    cout << endl;
}

int main(){
    Queue q;
    q.front = -1;
    q.rear = -1;
    q.size = 5;
    q.s = new int[5];
    enqueueUsingRear(&q,1);
    enqueueUsingRear(&q,2);
    enqueueUsingRear(&q,3);
    enqueueUsingRear(&q,4);
    enqueueUsingRear(&q,5);
    display(&q);
    enqueueUsingfront(&q,6);
    dequeueUsingfront(&q);
    display(&q);
    enqueueUsingfront(&q,6);
    display(&q);
    dequeueUsingRear(&q);
    dequeueUsingRear(&q);
    dequeueUsingRear(&q);
    dequeueUsingRear(&q);
    dequeueUsingRear(&q);
    dequeueUsingRear(&q);
}