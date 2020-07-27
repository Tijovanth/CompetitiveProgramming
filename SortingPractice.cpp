#include <iostream>
#include <stdio.h>
using namespace std;

struct Node{
    int data;
    struct Node * next;
}*first = NULL;

void Swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void BubbleSortUsingArray(int a[], int n){
    int flag = 0;
    for(int i = 0; i < n - 1; i++){
        flag = 0;
        for(int j = 0; j < n - 1 - i; j++){
            if(a[j] > a[j+1]){
                Swap(a,j,j+1);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
}

void InsertionSortUsingArray(int a[], int n){
    int x;int j;
    for(int i = 1; i < n; i++){
        x = a[i];
        for(j = i - 1;  j >= 0 && x < a[j]; j--){
            a[j+1] = a[j];
        }
        a[j+1] = x;
    }
}

void createLinkedList(int a[], int n){
    struct Node *last = NULL, *t = NULL;
    first = new Node;
    first ->data = a[0];
    first-> next = NULL;
    last = first;
    for(int i = 1; i < n; i++){
        t = new Node;
        t -> data = a[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

void InsertionSortUsingLinkedList(){
    struct Node *p=first->next;
    struct Node *t;
    struct Node *q=first;
    first->next=NULL;
    while(p){
        t=p;
        p=p->next;
        if(t->data<first->data){
            t->next=first;
            first=t;
        }else{
            q=first;
            while(q->next && q->next->data<t->data)
            q=q->next;
            t->next=q->next;
            q->next=t;
        } 
    }
}

void BubbleSortUsingLinkedList(int n){
    struct Node *p = NULL, *q = NULL;int flag = 0;
    for(int i = 0; i < n; i++){
        flag = 0;
        p = first;
        q = first -> next;
        while(q){
            if(p -> data > q -> data){
                int temp = p -> data;
                p -> data = q -> data;
                q -> data = temp;
                flag = 1;
            }
            p = p -> next;
            q = q -> next;
        }
        if(flag == 0)break;
    }
}

void SelectionSortUsingArray(int a[], int n){
    int j,k;
    for(int i = 0; i < n - 1; i++){
        for(j = k = i; j < n; j++){
            if(a[j] < a[k])
               k = j;
        }
        if(i != k)Swap(a,i,k);
    }
}

int Partition(int a[], int l, int h){
    int pivot = a[l];
    int i = l, j = h;
    do{
    do{i++;}while(pivot >= a[i]);
    do{j--;}while(pivot < a[j]);
    if(i < j)Swap(a,i,j);
    }while(i < j);
    Swap(a,l,j);
    return j;
}

void QuickSort(int a[], int l, int h){
    int j;
    if(l < h){
    j = Partition(a,l,h);
    QuickSort(a,l,j);
    QuickSort(a,j+1,h);
    }
}

void Merge(int a[], int l, int mid, int h){
    int b[100];
    int i,j,k;
    i = l;
    j = mid+1;
    k = l;
    while(i <= mid && j <= h){
    if(a[i] < a[j])
        b[k++] = a[i++];
    else
        b[k++] = a[j++];
    }
    while(i <= mid)
        b[k++] = a[i++];
    while(j <= h)
        b[k++] = a[j++];
    for(i = l; i <= h; i++){
        a[i] = b[i];
    }
}

void MergeSortIterative(int a[], int n){
    int p,l,h,mid;
    for(p = 2; p <= n; p=p*2){
        for(int i = 0; i+p-1 < n; i=i+p){
            l = i;
            h = i+p-1;
            mid = (l + h) / 2;
            Merge(a,l,mid,h);
        }
    }
    if(p/2 < n){
        Merge(a,0,p/2-1,n-1);
    }
}

void MergeSortRecursive(int a[], int l, int h){
    int mid;
    if(l < h){
        mid = (l+h) / 2;
        MergeSortRecursive(a,l,mid);
        MergeSortRecursive(a,mid+1,h);
        Merge(a,l,mid,h);
    }
}

int findMax(int a[], int n){
    int max = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    return max;
}

void CountSort(int a[], int n){
    int max,i = 0,j = 0;
    max = findMax(a,n);
    int *c;
    c = new int[max+1];
    for(int i = 0; i < n; i++)
        c[i] = 0;
    for(int i = 0; i < n; i++)
        c[a[i]]++;
    while(i <= max){
        if(c[i] > 0){
            a[j++] = i;
            c[i]--;
        }else{
            i++;
        }
    }
    delete []c;
}

void Insert(struct Node **t, int idx){
    Node *q = new Node;
    q ->data = idx;
    q -> next = NULL;
    if(t[idx] == NULL){
        t[idx] = q;
    }else{
        Node *p = t[idx];
        while(p -> next)
            p = p -> next;
        p -> next = q;
    }
}

int Delete(struct Node **t, int idx){
    int x = 0;
        Node *p = t[idx];
        t[idx] = t[idx] -> next;
        x = p -> data;
        delete p;
    return x;
}

void BinSort(int a[], int n){
    int max;int j = 0,i = 0;
    max = findMax(a,n);
    struct Node **Bin;
    Bin = new Node *[max + 1];
    for(i = 0; i < max+1; i++){
        Bin[i] = NULL;
    }
    i = 0;
    for(i = 0; i < n; i++){
        Insert(Bin,a[i]);
    }
    i =0; j = 0;
    while(i <= max){
        while(Bin[i] != NULL){
            a[j++] = Delete(Bin,i);
        }
        i++;
    }
    delete []Bin;
}

int main(){
    int a[] = {11,13,7,12,16,9,24,5,10,3};
    // createLinkedList(a,12);
    // BubbleSortUsingLinkedList(12);
    // InsertionSortUsingArray(a,11);
    // for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    //     cout << a[i] << " "; 
    // cout << endl;
    // int b[] = {8,5,7,3,2};
    // createLinkedList(b,5);
    // InsertionSortUsingLinkedList();
    // struct Node *p = first;
    // while(p){
    // cout<<p->data<<" ";
    // p=p->next;
    // }
    //SelectionSortUsingArray(a,12);
    //QuickSort(a,0,10);
    //MergeSortRecursive(a,0,10-1);
    //CountSort(a,10);
    BinSort(a,10);
    for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
        cout << a[i] << " "; 
    cout << endl;
}