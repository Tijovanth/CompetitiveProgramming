#include <iostream>
using namespace std;
class Rectangle{
    private:
     int length;
     int breadth;
    public:
    Rectangle(int length, int breadth){
        this->breadth = breadth;
        this->length = length;
    }
    void area(){
        std::cout << length * breadth <<"\n";
    }
    void changeDimensions(int length, int breadth){
        this->breadth = breadth;
        this->length = length;
    }
};

int main(){
    Rectangle r(10,15);
    r.area();
    r.changeDimensions(2,3);
    r.area();
}

