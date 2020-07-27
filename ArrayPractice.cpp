#include <stdio.h>
#include <stdlib.h>
int main(){
    //Array declaration
    // int a[5];
    // int b[5] = {1,2,3,4,5};
    // int c[] = {1,2,3,4,5,6,7,8};
    // int d[5] = {1,2};
    // int e[5] = {0};
    // // for(int i = 0; i < 5; i++){
    //     printf("%u \n", &a[i]);
    // }

    //Array created in heap
    // int *p = (int *)malloc(5 * sizeof(int));
    // p[0] = 1;
    // p[2] = 3;
    // p[3] = 5;

    // for(int i = 0; i < 5; i++){
    //     printf("%d\n",p[i]);
    // }
    // printf("----------\n");
    // Increase size of the array in heap
    // int *q = (int *)malloc(10 * sizeof(int));
    // for(int i = 0; i < 5; i++){
    //     q[i] = p[i];
    // }
    // delete []p;
    // p = q;
    // q = NULL;
    // for(int i = 0; i < 10; i++){
    //     printf("%d\n",p[i]);
    // } 

    //Array created inside stack 
    // int arr[5];
    // arr[0] = 0;
    // arr[1] = 1;
    // arr[2] = 2;
    // arr[3] = 3;
    // arr[4] = 4;
    // for(int i = 0; i < 5; i++){
    //     printf("%d\n",arr[i]);
    // }
    // int arr1[10];
    // for(int i = 0; i < 5; i++){
    //     arr1[i] = arr[i];
    // }
    // printf("%u\n",arr);
    // printf("%u\n",&arr[0]);
    //arr = arr1;
    // for(int i = 0; i < 10; i++){
    //     printf("%d\n",arr[i]);
    // }

    // 2 D Arrays
    // array in stack
    int arrInStack[2][2] = {{0,0},{1,1}};
    // array partially in stack and partially in heap
    int *arrInBoth[2];
    arrInBoth[0] = new int[2];
    arrInBoth[1] = new int[2];
    // array in heap
    int **arrInHeap;
    arrInHeap = new int*[2];
    arrInHeap[0] = new int[2];
    arrInHeap[1] = new int[2]; 
}