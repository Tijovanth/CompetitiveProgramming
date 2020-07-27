#include <iostream>
#include <stdio.h>
using namespace std;

struct Queue{
    int front;
    int rear;
    int size;
    int *s;
};

void circularEnqueue(struct Queue *q, int x){
    if((q -> rear + 1) % q -> size == q -> front ){
        cout << "Queue is full " << endl;
        return;
    }else{
        q -> rear = (q -> rear + 1) % q -> size; 
        q -> s[q -> rear] = x;
    }
}

int circularDequeue(struct Queue *q){
    if(q -> front == q -> rear){
        cout << "Queue is empty " << endl;
        return -1;
    }else{
        q -> front = (q -> front + 1) % q -> size;
        return q -> s[q -> front];
    }
}

int findingInWhichQueueWehaveToDelete(struct Queue *high, struct Queue *med, struct Queue *low){
    if(high -> rear != high -> front){
        return circularDequeue(high);
    }else if(med -> front != med -> rear){
        return circularDequeue(med);
    }else if(low -> front != low -> rear){
        return circularDequeue(low);
    }else{
        return -1;
    }
}

void findingInWhichQueueWeHaveToInsert(struct Queue *high, struct Queue *med, struct Queue *low, int priority, int num){
    if(priority == 1){
        circularEnqueue(high,num);
    }else if(priority == 2){
        circularEnqueue(med,num);
    }else if(priority == 3){
        circularEnqueue(low,num);
    }else{
        cout << "give correct priority only 3 priority is available " << endl;
    }
}

void circularDisplay(struct Queue *q){
    int first = q -> front + 1;
    while(first != (q -> rear + 1) % q -> size){
        cout << q -> s[first] << " ";
        first = (first + 1) % q -> size;
    }
    cout << endl;
}

int main(){
    Queue high;
    high.front = 0;
    high.rear = 0;
    high.size = 5;
    high.s = new int[5];
    Queue med;
    med.front = 0;
    med.rear = 0;
    med.size = 5;
    med.s = new int[5];
    Queue low;
    low.front = 0;
    low.rear = 0;
    low.size = 5;
    low.s = new int[5];
    findingInWhichQueueWeHaveToInsert(&high,&med,&low,1,10);
    findingInWhichQueueWeHaveToInsert(&high,&med,&low,1,11);
    findingInWhichQueueWeHaveToInsert(&high,&med,&low,2,20);
    findingInWhichQueueWeHaveToInsert(&high,&med,&low,2,21);
    findingInWhichQueueWeHaveToInsert(&high,&med,&low,3,30);
    findingInWhichQueueWeHaveToInsert(&high,&med,&low,3,31);
    findingInWhichQueueWeHaveToInsert(&high,&med,&low,1,12);
    findingInWhichQueueWeHaveToInsert(&high,&med,&low,2,22);
    findingInWhichQueueWeHaveToInsert(&high,&med,&low,1,13);
    findingInWhichQueueWeHaveToInsert(&high,&med,&low,3,32);
    findingInWhichQueueWeHaveToInsert(&high,&med,&low,2,23);
    cout << findingInWhichQueueWehaveToDelete(&high,&med,&low) << endl;
    cout << findingInWhichQueueWehaveToDelete(&high,&med,&low) << endl;
    cout << findingInWhichQueueWehaveToDelete(&high,&med,&low) << endl;
    cout << findingInWhichQueueWehaveToDelete(&high,&med,&low) << endl;
    cout << findingInWhichQueueWehaveToDelete(&high,&med,&low) << endl;
    cout << findingInWhichQueueWehaveToDelete(&high,&med,&low) << endl;
    cout << findingInWhichQueueWehaveToDelete(&high,&med,&low) << endl;
    cout << findingInWhichQueueWehaveToDelete(&high,&med,&low) << endl;
    cout << findingInWhichQueueWehaveToDelete(&high,&med,&low) << endl;
    cout << findingInWhichQueueWehaveToDelete(&high,&med,&low) << endl;
    cout << findingInWhichQueueWehaveToDelete(&high,&med,&low) << endl;
    cout << findingInWhichQueueWehaveToDelete(&high,&med,&low) << endl;

}