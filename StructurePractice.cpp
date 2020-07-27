#include <stdio.h>
#include <stdlib.h>
struct Rectangle{
        int length;
        int breadth;
    };

struct Card{
    int face;
    int shape;
    int color;
};
int main(){
    struct Rectangle r;
    struct Rectangle r1={10,5};
    printf("Area of Rectange is %d \n",r.length * r.breadth);
    struct Card deck[52];
    deck[0].color = 0;
    deck[0].face = 2;
    deck[0].shape = 2;
    printf("deck of zero is %d %d %d \n",deck[0].color,deck[0].face,deck[0].shape);
    printf("deck of one is %d %d %d \n",deck[1].color,deck[1].face,deck[1].shape);

    // structure in heap and accessing using pointer
    struct Rectangle *p;
    p =(struct Rectangle *) malloc(sizeof(struct Rectangle));
    p ->breadth = 20;
    p ->length = 30;
    printf("Structure created in heap and accessing using pointer %d %d \n",p ->breadth,p ->length);

    struct Rectangle r2 = {45,55};
    struct Rectangle *p1;
    p1 = (struct Rectangle *)malloc(sizeof(r2));
    printf("%d %d",p1->breadth,p1->length);
}