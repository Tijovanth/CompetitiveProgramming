#include <iostream>
using namespace std;

template <class T>

class Array{
    private:
    T *A;
    int length;
    int size;
    void Swap(int *a, int *b);

    public:
    Array(){
        size = 10;
        length = 0;
        A = new T[size];
    }
    Array(int sz){
        size = sz;
        length = 0;
        A = new T[size];
    }
    ~Array(){
        delete []A;
    }
    void Display();
    bool Add(T num);
    bool Insert(int index, T num);
    T Delete(int index);
    int LinearSearch(T num);
    int BinarySearch(T num, int low, int high);
    int BinarySearchUsingLoop(T num, int low, int high);
    T Get(int index);
    void Set(int index, T num);
    int Sum();
    T Max();
    T Min();
    int Avg();
    void ReversingArrayBySwaping();
    void LeftShift();
    void RightShift();
    void LeftRotate();
    void RightRotate();
    //My version
    void InsertingInASortedList(T num);
    //Abdul Bhari version
    void InsertingElementInSortedList(T num);
    bool CheckIfArraySorted();
    bool CheckIsNegative(T num);
    void ArrangeNegativeOnLeftSide();
    void ArrangeNegativeOnLeftSideByAbdulBhari();
    void MergingArraysMyversion(Array anotherarr, Array resultArray);
    void Union(Array anotherarr, Array resultArray);
    void Intersection(Array anotherarr, Array resultArray);
    void Difference(Array anotherarr, Array resultArray);
};

template<class T>
void Array<T>::Display(){
    cout<<"Display all the elements"<<endl;
    for(int i = 0 ; i < length; i++){
        cout<<A[i]<<" ";
        cout<<endl;
    }
}

template<class T>
bool Array<T>::Add(T num){
    if(length < size){
        A[length] = num;
        length++;
        return true;
    }else {
        cout<<"No more space"<<endl;
        return false;
    } 
   }

template<class T>
bool Array<T>::Insert(int index, T num){
    cout<<"array length and array size is "<<length<<" "<<size<<endl; 
    if(length < size){
        if(length >= index){
            for(int i = length ; i > index; i--){
                A[i] = A[i - 1];
            }
            A[index] = num;
            length++;
        return true;
        }else if(index >= size){
        cout<<"Enter the correct index"<<endl;
        return false;
       }
    }
    cout<<"No more space"<<endl;
    return false;
}

template<class T>
T Array<T>::Delete(int index){
   if(index < length){
       T j = A[index];
           for(int i = index; i < length-1; i++){
               A[i] = A[i + 1];
           }
        length--;
       return j;
       }else{
       cout<<"Enter correct index"<<endl;
       return -1;
   }
}

void Swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

template<class T>
int Array<T>::LinearSearch(T num){
    for(int i = 0; i < length; i++){
        // Transposition
        if(A[i] == num){
            Swap(&A[i],&A[i - 1]);
            return i;
        }

        //Move to front
        //  if(arr->A[i] == num){
        //     swap(&arr->A[i],&arr->A[0]);
        // }
    }
    return -1;
}

// Recursive version
template<class T>
int Array<T>::BinarySearch(T num, int low, int high){
    int mid;
    if(low >= high){
    mid = (low + high) / 2;
    if(A[mid] == num)
        return mid;
    if(A[mid] < num)
        return BinarySearch(num,mid+1,high);
    else if(A[mid] > num)
        return BinarySearch(num,low,mid-1);
    }
    return -1;
}
//Iterative version
template<class T>
int Array<T>::BinarySearchUsingLoop(T num, int low, int high){
    int mid;
    int result = -1;
    while(low <= high){
        mid = (low + high) / 2;
        if(A[mid] == num){
            result = mid;
            break;
        }
        if(A[mid] < num){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return result;
}

template<class T>
T Array<T>::Get(int index){
    if(index < 0 && index >= length){
        return A[index];
    }
    return -1;
}

template<class T>
void Array<T>::Set(int index, T num){
    if(index < 0 && index >= length){
        A[index] = num;
    }
}

template<class T>
int Array<T>::Sum(){
    if(length > 0)
        return (length * (length + 1)) / 2;
    return -1;
}

template<class T>
T Array<T>::Max(){
    if(length > 0){
        int max = A[0];
        for(int i = 1; i < length; i++){
            if(max < A[i])
                max = A[i];
        }
        return max;
    }
    return -1;
} 

template<class T>
T Array<T>::Min(){
    if(length > 0){
        int min = A[0];
        for(int i = 1; i < length; i++){
            if(min > A[i])
                min = A[i];
        }
        return min;
    }
    return -1;
}

template<class T>
int Array<T>::Avg(){
    if(length > 0){
    int sum = (length * (length + 1)) / 2;
    return sum / 2;
    }
    return -1;
}

template<class T>
void Array<T>::ReversingArrayBySwaping(){
    int temp,i,j;
    for(i = 0,j = length - 1; i < j; i++,j--){
       Swap(&A[i],&A[j]);
    }
}

template<class T>
void Array<T>::LeftShift(){
    for(int i = 1; i < length; i++)
        A[i - 1] = A[i];
    A[length - 1] = 0;
    length--;
}

template<class T>
void Array<T>::RightShift(){
    for(int i = length - 1; i > 0; i--)
         A[i] = A[i - 1];
    A[0] = 0;
    length--;
}

template<class T>
void Array<T>::LeftRotate(){
    T zeroValue = A[0];
     for(int i = 1; i < length; i++)
        A[i - 1] = A[i];
    A[length - 1] = zeroValue;
}

template<class T>
void Array<T>::RightRotate(){
    T lastValue = A[length - 1];
    for(int i = length - 2; i >= 0; i--){
        A[i + 1] = A[i];
    }
    A[0] = lastValue;
}

//My version 
template<class T>
void Array<T>::InsertingInASortedList(T num){
    for(int i = length - 1; i >= 0; i--){
        if(A[i] < num){
        A[i + 1] = num;
        length++;
        break;
        }
        A[i + 1] = A[i];
        if(i == 0 && A[i] >= num){
            A[0] = num;
            length++;
        }
    }
}

//Abdul Bhari version
template<class T>
void Array<T>::InsertingElementInSortedList(T num){
    int i = length - 1;
    while(i >= 0 && A[i] > num){
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = num;
    length++;
}

template<class T>
bool Array<T>::CheckIfArraySorted(){
    for(int i = 1; i < length; i++){
        if(A[i - 1] > A[i]){
            return false;
        }
    }
    return true;
}

template<class T>
bool Array<T>::CheckIsNegative(T num){
    if(num < 0)
        return true;
    else
        return false;
}

//My version
template<class T>
void Array<T>::ArrangeNegativeOnLeftSide(){
    int i=0,j=length-1;
    while(i < j){
        if(!CheckIsNegative(A[i])){
            while(i < j){
                if(CheckIsNegative(A[j])){
                    Swap(&A[i],&A[j]);
                    break;
                }
                j--;
            }
        }
        i++;
    }
}

//Abdul Bhari version
template<class T>
void Array<T>::ArrangeNegativeOnLeftSideByAbdulBhari(){
    int i = 0, j = length - 1;
    while(i < j){
        while(A[i] < 0) i++;
        while(A[j] >= 0) j--;
        if(i < j) Swap(&A[i],&A[j]);
    }
}

template<class T>
void Array<T>::MergingArraysMyversion(Array<T> anotherarr, Array<T> resultArray){
    int i = 0; int j = 0; int a = 0 ;
    while(i < length && j < anotherarr.length){
        if(A[i] < anotherarr.A[j]){
            resultArray.A[a++] = A[i++];
        }else{
            resultArray.A[a++] = anotherarr.A[j++];
        }
    }
    for(; i < length ; i++){
        resultArray.A[a++] = A[i];
            
    }
    for(; j < anotherarr.length ; j++){
        resultArray.A[a++] = anotherarr.A[j];
       
    }
    resultArray.length = length + anotherarr.length;
}

//SetOperations
template<class T>
void Array<T>::Union(Array<T> anotherarr, Array<T> resultArray){
    int i = 0; int j = 0; int a = 0 ;
    while(i < length && j < anotherarr.length){
        if(A[i] < anotherarr.A[j]){
            resultArray.A[a++] = A[i++];
        }else if(A[i] > anotherarr.A[j]){
            resultArray.A[a++] = anotherarr.A[j++];
        }else{
            resultArray.A[a++] = A[i++];
            j++;
        }
    }
    for(; i < length ; i++){
        resultArray.A[a++] = A[i];     
    }
    for(; j < anotherarr.length ; j++){
        resultArray.A[a++] = anotherarr.A[j];
    }
    resultArray.length = a;
}

template<class T>
void Array<T>::Intersection(Array<T> anotherarr, Array<T> resultArray){
    int i = 0; int j = 0; int a = 0 ;
    while(i < length && j < anotherarr.length){
        if(A[i] < anotherarr.A[j]){
           i++;
        }else if(A[i] > anotherarr.A[j]){
            j++;
        }else{
            resultArray.A[a++] = A[i++];
            j++;
        }
    }
    resultArray.length = a;
}

template<class T>
void Array<T>::Difference(Array<T> anotherarr, Array<T> resultArray){
    int i = 0; int j = 0; int a = 0 ;
    while(i < length && j < anotherarr.length){
        if(A[i] < anotherarr.A[j]){
           resultArray.A[a++] = A[i++];
           i++;
        }else if(A[i] > anotherarr.A[j]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    for(; i < length ; i++){
        resultArray.A[a++] = A[i];     
    }
    resultArray.length = a;
}

int main(){
    cout<<"Welcome to the ArrayADT program in c++ version"<<endl;
    Array<int> arr(20);
    arr.Display();
    arr.Insert(0,1);
    arr.Insert(1,2);
    arr.Insert(2,3);
    arr.Display();
    arr.Delete(2);
    arr.Display();
}

// #include <iostream>
// using namespace std;
// template<class T>
// class Array
// {
// private:
//  T *A;
//  int size;
//  int length;
// public:
//  Array()
//  {
//  size=10;
//  A=new T[10];
//  length=0;
//  }
//  Array(int sz)
//  {
//  size=sz;
//  length=0;
//  A=new T[size];
//  }
//  ~Array()
//  {
//  delete []A;
//  }
//  void Display();
//  void Insert(int index,T x);
//  T Delete(int index);
// };
// template<class T>
// void Array<T>::Display()
// {
//  for(int i=0;i<length;i++)
//  cout<<A[i]<<" ";
//  cout<<endl;
// }
// template<class T>
// void Array<T>::Insert(int index,T x)
// {
//  if(index>=0 && index<=length)
//  {
//  for(int i=length-1;i>=index;i--)
//  A[i+1]=A[i];
//  A[index]=x;
//  length++;
//  }
// }
// template<class T>
// T Array<T>::Delete(int index)
// {
//  T x=0;
//  if(index>=0 && index<length)
//  {
//  x=A[index];
//  for(int i=index;i<length-1;i++)
//  A[i]=A[i+1];
//  length--;
//  }
//  return x;
// }
// int main()
// {
//  Array<char> arr(10);

//  arr.Insert(0,'a');
//  arr.Insert(1,'c');
//  arr.Insert(2,'d');
//  arr.Display();
//  cout<<arr.Delete(0)<<endl;
//  arr.Display();
//  return 0;
// }