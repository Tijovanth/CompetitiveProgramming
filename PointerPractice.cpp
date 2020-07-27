# include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
int main(){
    int a = 10;
    int *p = &a;
    printf("a is %d \n",a);
    printf("accessing a using p %d \n", *p);

    int *c = (int *)malloc(5 * sizeof(int));
    printf(" c is %d \n",*c);

    // reference
    int &d = a;
    std::cout << d;
}