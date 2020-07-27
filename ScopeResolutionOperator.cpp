#include <iostream>
using namespace std;

// case 1 : accessing global variable
// int x = 10;
// int main(){
//     int x = 20;
//     std::cout << ::x <<"\n";
//     std::cout << x <<"\n";
// }

//case 2: to define a funcion outside a class
// class Rectangle{
//     private:
//      int length;
//      int breadth;
//     public:
//     void area();
//     Rectangle(int length, int breadth);
//     int getLength();
//     ~Rectangle();
// };

// void Rectangle::area(){
//     std::cout << length*breadth <<"\n";
// }

// Rectangle::Rectangle(int length, int breadth){
//     this->length = length;
//     this->breadth = breadth;
// }

// int Rectangle::getLength(){
//     return length;
// }

// Rectangle::~Rectangle(){}

// int main(){
//     Rectangle r(10,15);
//     r.area();
//     std::cout<< r.getLength();
//     r.~Rectangle();
// }

//case 3 To access class static variable
