#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
// call by value
// void swap(int a, int b){
//     int temp = a;
//     a = b;
//     b = temp;
// }

// call by address
// void swap(int *a, int *b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// call by referrence
// void swap(int &a, int &b){
//     int temp = a;
//     a = b;
//     b = temp;
// } 

//Array as parameter
// int * creatingArrayInHeap(int n){
//     int *p;
//     p =(int *)malloc(n * sizeof(int));
//     for(int i = 0; i < n; i++){
//         *(p + i) = i;
//     }
//     return p;
// }

//Structure as parameter

struct Test
{
  int id;
};

void fun(struct Test &t){
    t.id = 13;
    std::cout << t.id <<"\n";
}

int main(){
    // int x = 10;
    // int y = 15;
    // swap(x,y);
    // printf("the x and y is %d %d",x,y);

    // int * a;
    // a = creatingArrayInHeap(5);
    // for(int i = 0; i < 5; i++){
    //     std::cout << *(a + i) <<"\n";
    //     std::cout << &a[i] <<"\n";
    // }

    struct Test t = {12};
    fun(t);
    std::cout << t.id <<"\n";
}