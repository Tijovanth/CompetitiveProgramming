#include <iostream>
using namespace std;

template <class T>
class Array
{
private:
    int size;
    int length;
    T A[10] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};

public:
    Array()
    {
        size = 10;
        length = 10;
    }

    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new T[size];
    }

    T FindingMissingElementInAnArrayIfArrayStartedWithOne();
    T FindingMissingElementInAnArrayIfArrayNotStartedWithOne();
    void MultipleElementIsMissingFromSortedArray();
    void MultipleElementIsMissingInUnsortedArray(T high);
    void FindingDuplicateElementInSortedArray();
    void CountingDuplicateElementInSortedArray();
    void CoutingDuplicateElementsInSortedArrayAbdulBhariVerion();
};

template <class T>
T Array<T>::FindingMissingElementInAnArrayIfArrayStartedWithOne()
{
    int n = A[length - 1];
    int sumOfNaturalNumbers = (n * (n + 1)) / 2;
    int sum = 0;
    for (int i = 0; i < length; i++)
        sum = sum + A[i];
    return sumOfNaturalNumbers - sum;
}

template <class T>
T Array<T>::FindingMissingElementInAnArrayIfArrayNotStartedWithOne()
{
    int diff = A[0] - 0;
    for (int i = 0; i < length; i++)
    {
        if (A[i] - i != diff)
            return i + diff;
    }
    return -1;
}

template <class T>
void Array<T>::MultipleElementIsMissingFromSortedArray()
{
    T diff = A[0] - 0;
    for (int i = 0; i < length; i++)
    {
        if (A[i] - i != diff)
        {
            T currentDiff = A[i] - i;
            while (diff < currentDiff)
            {
                cout << i + diff << endl;
                diff++;
            }
        }
    }
}

template <class T>
void Array<T>::MultipleElementIsMissingInUnsortedArray(T high)
{
    T arr[high + 1];
    for (int i = 0; i <= high; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; i < length; i++)
    {
        arr[A[i]] = 1;
    }
    for (int i = 1; i <= high; i++)
    {
        if (arr[i] == 0)
            cout << i << endl;
    }
}

template <class T>
void Array<T>::FindingDuplicateElementInSortedArray()
{
    T lastDuplicate = -1;
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] == lastDuplicate)
            continue;
        else if (A[i] == A[i + 1])
        {
            cout << A[i] << endl;
            lastDuplicate = A[i];
        }
    }
}

// Myversion
template <class T>
void Array<T>::CountingDuplicateElementInSortedArray()
{
    T lastDuplicate = -1;
    int count = 1;
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] == A[i + 1] && A[i] == lastDuplicate)
        {
            count++;
        }
        else if (A[i] != A[i + 1] && count > 1)
        {
            cout << "The duplicate element is " << lastDuplicate << "and the count is " << count << endl;
            count = 1;
        }
        else if (A[i] == A[i + 1])
        {
            lastDuplicate = A[i];
            count++;
        }
    }
}

//Abdul Bhari Version
template <class T>
void Array<T>::CoutingDuplicateElementsInSortedArrayAbdulBhariVerion()
{
    for(int i = 0; i < length - 1; i++){
        if(A[i] == A[i + 1]){
            int j = i + 1;
            while(A[i] == A[j]) j++;
            cout << "The duplicate element is " << A[i]<< "and the count is " << j - i << endl;
            i = j - 1;
        }
    }
}

int main()
{
    Array<int> arr;
    //cout<<"the missing element is "<<arr.FindingMissingElementInAnArrayIfArrayStartedWithOne()<<endl;
    //cout<<"the missing element is "<<arr.FindingMissingElementInAnArrayIfArrayNotStartedWithOne()<<endl;
    //arr.MultipleElementIsMissingFromSortedArray();
    //arr.MultipleElementIsMissingInUnsortedArray(12);
    //arr.FindingDuplicateElementInSortedArray();
    //arr.CountingDuplicateElementInSortedArray();
    //arr.CoutingDuplicateElementsInSortedArrayAbdulBhariVerion();
}
