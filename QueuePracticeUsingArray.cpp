#include <iostream>
#include <stdio.h>
using namespace std;

struct Queue{
    int front;
    int rear;
    int size;
    int *s;
};

int first(struct Queue *q){
    if(q->front == q->rear)
        return -1;
    else
        return q -> s[q -> front+1];
}

int last(struct Queue *q){
    if(q->front == q->rear)
        return -1;
    else
        return q -> s[q -> rear];
}

// normal queue
void enqueue(struct Queue *q, int x){
    if(q->rear == q->size - 1)
        return;
    else{
        q -> rear++;
        q -> s[q -> rear] = x; 
    }  
}

// normal queue
int dequeue(struct Queue *q){
    if(q->front == q->rear)
        return -1;
    else{
        q -> front++;
        return q -> s[q -> front];
    }
}

// circular queue
void circularEnqueue(struct Queue *q, int x){
    if((q -> rear + 1) % q -> size == q -> front){
        cout << "Queue is full" << " " << endl;
        return;
    }else{
        q -> rear = (q -> rear + 1) % q -> size;
        q -> s[q -> rear] = x;
    }
}

//circular queue
int circularDequeue(struct Queue *q){
    if(q -> front == q -> rear)
        return -1;
    else{
        q -> front = (q -> front + 1) % q -> size;
        return q -> s[q -> front];
    }
}

// normal queue
void display(struct Queue *q){
    for(int i = q->front + 1; i <= q -> rear; i++){
        cout << q -> s[i] << " ";
    }
    cout << endl;
} 

//circular queue
void circularDisplay(struct Queue *q){
    int first = q -> front + 1;
    while(first != (q -> rear + 1) % q -> size){
        cout << q -> s[first] << " ";
        first = (first + 1) % q -> size;
    }
    cout << endl;
}

int main(){
    Queue myQueue;
    myQueue.front = 0;
    myQueue.rear = 0;
    myQueue.size = 5;
    myQueue.s = new int[myQueue.size];
    circularEnqueue(&myQueue,1);
    circularEnqueue(&myQueue,2);
    circularEnqueue(&myQueue,3);
    circularEnqueue(&myQueue,4);
    circularEnqueue(&myQueue,5);
    circularEnqueue(&myQueue,6);
    circularDisplay(&myQueue);
    cout << circularDequeue(&myQueue) << endl;
    cout << circularDequeue(&myQueue) << endl;
    circularDisplay(&myQueue);
    circularEnqueue(&myQueue,5);
    circularEnqueue(&myQueue,6);
    circularDisplay(&myQueue);
    cout << first(&myQueue) << endl;
    cout << last(&myQueue) << endl;
}