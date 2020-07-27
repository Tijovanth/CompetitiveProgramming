#include <iostream>
#include <stdio.h>
using namespace std;

struct Array{
    int size;
    int length;
    int *array;
};

void insertByMaxHeap(struct Array *arr, int num, int n){
   arr->array[n] = num;
   int temp,i = n;
   temp = arr->array[n];
   while(i > 1 && temp > arr->array[i/2]){
       arr->array[i] = arr->array[i/2];
       i = i / 2;
   }
   arr->array[i] = temp;
   arr->length++;
}

void display(struct Array arr){
    for(int i = 1; i < arr.length; i++)
        cout << arr.array[i] << " ";
    cout << "\n";
}

void Swap(struct Array *arr, int i, int j){
    int temp;
    temp = arr->array[i];
    arr->array[i] = arr->array[j];
    arr->array[j] = temp;
}

int DeleteHeap(struct Array *arr){
    int i,j;
    int x = arr->array[1];
    arr->array[1] = arr->array[arr->length - 1];
    //arr->array[arr->length - 1] = x;
    arr -> length--;
    i = 1;
    j = 2 * i;
    while(j <= arr->length - 1){
        if(arr->array[j+1] > arr->array[j])
            j = j + 1;
        if(arr->array[i] < arr->array[j]){  
            Swap(arr,i,j);
            i = j;
            j = 2 * j;
        }
        else
            break;
    }
    return x;
}

void Swap2(int a[] , int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void Heapify(int a[], int n){
    int j,k;
    for(int i = (n/2)-1; i >=0; i--){
        k = i;
        j = 2 * k + 1;
        while(j < n - 1){
            if(a[j] < a[j+1])
                j = j + 1;
            if(a[k] < a[j]){
                Swap2(a,k,j);
                k = j;
                j = 2 * j + 1;
            }else{
                break;
            }
        }
    }
}

int main(){
    struct Array arr;
    arr.array = new int[10];
    arr.size = 10;
    arr.length = 1;
    insertByMaxHeap(&arr,6,arr.length);
    insertByMaxHeap(&arr,15,arr.length);
    insertByMaxHeap(&arr,35,arr.length);
    insertByMaxHeap(&arr,40,arr.length);
    insertByMaxHeap(&arr,8,arr.length);
    display(arr);
    cout << DeleteHeap(&arr) << " \n";
    display(arr);
    cout << DeleteHeap(&arr) << " \n";
    display(arr);
    cout << DeleteHeap(&arr) << " \n";
    display(arr);
    cout << DeleteHeap(&arr) << " \n";
    display(arr);
    cout << DeleteHeap(&arr) << " \n";
    display(arr);
    int a[] = {5, 10, 30, 20, 35, 40, 15};
    cout << sizeof(a) << " ";
    cout << sizeof(a[0]) << " ";
    Heapify(a,sizeof(a)/sizeof(a[0]));
    for(int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
        cout << a[i] << " ";
    }