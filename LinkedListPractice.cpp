#include <iostream>
#include <stdio.h>
using namespace std;

struct Node *first = NULL;
struct Node *last = NULL;
struct Node *second = NULL;
struct Node *third = NULL;
struct Node{
    int data;
    struct Node *next;
};

void Create(int a[], int n){
    struct Node *t, *last;
    first = new Node;
    first->data = a[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i < n; i++){
        t = new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void CreateSecond(int a[], int n){
    struct Node *t, *last;
    second = new Node;
    second->data = a[0];
    second->next = NULL;
    last = second;

    for(int i = 1; i < n; i++){
        t = new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Iterative version
void Display(struct Node *p){
    while(p != NULL){
        cout << p->data << endl;
        p = p->next;
    }
}

//recursive version
void RecursiveDisplay(struct Node *p){
    if(p == NULL){
        return;
    }
    RecursiveDisplay(p->next);
    cout << p->data << " ";
}
 //Iterative version
int CountingLinkedList(struct Node *p){
    int sum = 0;
    while(p){
        sum ++;
        p = p->next;
    }
    return sum;
}

//Recursive version
int CountingLinkedListRecursively(struct Node *p){
    if(p){
        return CountingLinkedListRecursively(p->next)+1;
    }else{
        return 0;
    }
}

//Iterative version
int SumOfLinkedList(struct Node *p){
    int sum = 0;
    while(p){
        sum += p->data;
        p = p->next;
    }
    return sum;
}

//Recursive version
int SumOfLinkedListRecursively(struct Node *p){
    if(p == NULL){
        return 0;
    }else{
        return SumOfLinkedListRecursively(p->next)+p->data;
    }
}

//Interative version
int FindingMax(struct Node *p){
    int max = INT16_MIN;
    while(p){
        if(p->data > max)
            max = p->data;
        p = p -> next;
    }
    return max;
}

//Recursive Version and it is My version
int FindingMaxRecursively(struct Node *p){
    static int max = INT16_MIN;
    if(!p)
        return 0;
    if(p->data > max){
        max = p->data;
    }
    FindingMaxRecursively(p->next);
    return max;
}

//Abdul Bhari Version
int FindingMaxRecursivelyAbdulBhari(struct Node *p){
    int x = 0;
    if(!p)
        return INT16_MIN;
    x = FindingMaxRecursivelyAbdulBhari(p->next);
    return x > p->data ? x : p->data;
}

//Iterative version
Node * LinearSearch(struct Node *p, int num){
    while(p){
        if(p-> data == num){
            return p;
        }
        p = p ->next;
    }
    return NULL;
}

//Recursive Version
Node * LinearSearchRecursively(struct Node *p, int num){
    if(p == NULL)
        return NULL;
    if(p-> data == num){
        return p;
    }
    return LinearSearchRecursively(p->next,num);
}

Node * LinearSearchMoveToHeadMethod(struct Node *p, int num){
    Node * q = p;
    while(p){
        if(p->data == num){
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

void InsertingNode(struct Node *p, int num, int pos){
    Node *t;
    if(pos == 0){
        t = new Node;
        t->data = num;
        t->next = first;
        first = t;
    }else{
        int count = 1;
            while(p){
            if(count == pos){
                t = new Node;
                t->data = num;
                t->next = p->next;
                p->next = t;
                break;
            }
            count++;
            p = p ->next;
        }
    }
}

 void InsertLast(struct Node *p, int num){
     Node *t;
     if(first == NULL){
         t = new Node;
         t->data = num;
         t->next = NULL;
         first = last = t;
     }else{
         t = new Node;
         t->data = num;
         t->next = NULL;
         last->next = t;
         last = t;
     }
 }

//My version
 void InsertInSortedList(struct Node *p,int num){
     Node *t,*q;
     while(p){
         if(first->data == p->data && p->data > num){
             t = new Node;
             t->data = num;
             t->next = p;
             first = t;
             break;
         }
         if(p->data > num){
            t = new Node;
            t->data = num;
            t-> next = p;
            q->next = t;
            break;
         }else{
             q = p;
             p = p->next;
         }
     }

     if(!p){
         t = new Node;
         t->data = num;
         t->next = p;
         q->next = t;
     }
 }

 //Abdul Bhari Version 
void InsertInSortedListAbdulBhariVersion(struct Node *p, int num){
    Node *t,*q = NULL;
    t = new Node;
    t->data = num;
    t->next = NULL;
    if(first == NULL){
        first = t;
    }else{
        while(p && p->data < num){
            q = p;
            p = p->next;
        }
        if(p == first){
            t->next = first;
            first = t;
        }else{
        t->next = q->next;
        q->next = t;
        }
    }
}

int DeleteFirstNode(struct Node *p){
    first = p -> next;
    int x = p->data;
    delete p;
    return x;
}

int DeleteAnyOtherNode(struct Node *p, int pos){
    Node *q = NULL;
    for(int i = 0; i < pos - 1 && p; i++){
        q = p;
        p = p -> next;
    }
    q->next = p->next;
    int x = p->data;
    delete p;
    return x;
}

void CheckIfListIsSorted(struct Node *p){
    int x = INT16_MIN;
    while(p){
        if(p->data < x){
            cout << "Linked List is not sorted " << endl;
            break;
        }
        x = p -> data;
        p = p -> next;
    }
    if(!p){
        cout << "Linked List is sorted " << endl;
    }
}  

void RemovingDuplicatesInList(struct Node *p){
    Node *q = p->next;
    while( q != NULL){
        if(p->data != q->data){
            p = q;
            q = q -> next;
        }else{
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

void ReversingLinkedListUsingSlidePointer(struct Node *p){
    Node *q = NULL,*r = NULL;
    while(p){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void ReversingLinkedListUsingRecursion(struct Node *p, struct Node *q){
    if(p == NULL){
        first = q;
        return;
    }
    ReversingLinkedListUsingRecursion(p->next,p);
    p -> next = q;
}

void ConcatenatingOfLinkedList(struct Node *p, struct Node *q){
    while(p->next != NULL){
        p = p -> next;
    }
    p -> next = q;
}

void MergingLinkedList(struct Node *p, struct Node *q){
    Node *s = NULL;
    if(p->data > q->data){
        third = s = q;
        q = q -> next;
        s -> next = NULL;
    }else{
        third = s = p;
        p = p -> next;
        s -> next = NULL;
    }
    while(p && q){
        if(p -> data > q -> data){
            s -> next = q;
            s = q;
            q = q -> next;
            s -> next = NULL;
        }else{
            s -> next = p;
            s = p;
            p = p -> next;
            s -> next = NULL;
        }
    }
    if(p != NULL){
        s -> next = p;
    }else{
        s -> next = q;
    }
} 

void CheckingWhetherListIsLoop(struct Node *p){
    Node *q = NULL;
    q = p;
    while(p && q){
        p = p ->next;
        q = q -> next;
        q = q != NULL ? q -> next : NULL;
        if(p == q){
            break;
        }
    }
    if(p == q){
        cout << "This is LOOp " << endl; 
    }else{
        cout << "This is not Loop " << endl;
    }
}

void FindingMiddleNode(struct Node *p){
    Node *q = p;
    while(q != NULL){
        q = q -> next;
        if(q){
            q = q -> next;
            p = p -> next;
        }
    }
    cout << p -> data << " ";
}

int main(){
    // int a[] = {1,2,3,4,5};
    // Create(a,5);
    //display(first);
    // RecursiveDisplay(first);
    // cout << CountingLinkedList(first) << endl;
    // cout << CountingLinkedListRecursively(first) << endl;
    // cout << SumOfLinkedList(first) << endl;
    // cout << SumOfLinkedListRecursively(first) << endl;
    // cout << FindingMax(first) << endl;
    // cout << FindingMaxRecursively(first) << endl;
    // Node *p = LinearSearch(first,3);
    // cout << p->data << endl;
    // p = LinearSearchRecursively(first,3);
    // cout << p->data << endl;
    //cout << LinearSearchMoveToHeadMethod(first,5) << endl;
    //cout << first->data << endl;
    //Display(first);
    // InsertingNode(first,13,0);
    // InsertingNode(first,12,1);
    // InsertingNode(first,3,5);
    // InsertingNode(first,15,0);
    // Display(first);
    InsertLast(first,11);
    //Display(first);
    InsertLast(first,22);
    //InsertLast(first,22);
    //InsertLast(first,22);
    //Display(first);
    InsertLast(first,33);
    //Display(first);
    InsertLast(first,44);
    InsertLast(first,55);
    InsertLast(first,66);
    InsertLast(first,77);
    //InsertLast(first,13);
    //Display(first);
    //InsertInSortedList(first,15);
    //InsertInSortedListAbdulBhariVersion(first,32);
    //Display(first);
    //cout << DeleteFirstNode(first) << endl;
    //Display(first);
    //cout << DeleteAnyOtherNode(first, 4) << endl;
    //cout << endl;
    // Display(first);
    //CheckIfListIsSorted(first);
    //RemovingDuplicatesInList(first);
    //ReversingLinkedListUsingSlidePointer(first);
    // ReversingLinkedListUsingRecursion(first,NULL);
    // Display(first);
    int b[] = {12,23,34,36};
    CreateSecond(b,4);
    // Display(second);
    // Display(first);
    // ConcatenatingOfLinkedList(first, second);
    // Display(first);
    // MergingLinkedList(first, second);
    // Display(third);
    //CheckingWhetherListIsLoop(first);
    FindingMiddleNode(first);
}