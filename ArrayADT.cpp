#include <stdio.h>
#include <stdlib.h>
struct Array{
    int length;
    int size;
    int *A;
};

void Display(struct Array arr){
    printf("Display all the elements \n");
    for(int i = 0 ; i < arr.length; i++){
        printf("%d \n",arr.A[i]);
    }
}

bool Add(struct Array *arr, int num){
    if(arr->length < arr->size){
        arr->A[arr->length] = num;
        arr->length++;
        return true;
    }else {
        printf("No more space \n");
        return false;
    } 
   }

bool Insert(struct Array *arr, int index, int num){
    printf("array length and array size %d %d",arr->length,arr->size);
    if(arr->length < arr->size){
        if(arr->length >= index){
            for(int i = arr->length ; i > index; i--){
                arr->A[i] = arr->A[i - 1];
            }
            arr->A[index] = num;
            arr->length++;
        return true;
        }else if(index >= arr->size){
        printf("Enter the correct index");
        return false;
       }
    }
    printf("No more space \n");
    return false;
}

int Delete(struct Array *arr, int index){
   if(index < arr->length){
       int j = arr->A[index];
           for(int i = index; i < arr->length-1; i++){
               arr->A[i] = arr->A[i + 1];
           }
        arr->length--;
       return j;
       }else{
       printf("Enter correct index \n");
       return -1;
   }
}

void Swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int LinearSearch(struct Array *arr, int num){
    for(int i = 0; i < arr->length; i++){
        // Transposition
        if(arr->A[i] == num){
            Swap(&arr->A[i],&arr->A[i - 1]);
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
int BinarySearch(struct Array *arr, int num, int low, int high){
    int mid;
    if(low >= high){
    mid = (low + high) / 2;
    if(arr->A[mid] == num)
        return mid;
    if(arr->A[mid] < num)
        return BinarySearch(arr,num,mid+1,high);
    else if(arr->A[mid] > num)
        return BinarySearch(arr,num,low,mid-1);
    }
    return -1;
}
//Iterative version
int BinarySearchUsingLoop(struct Array *arr, int num, int low, int high){
    int mid;
    int result = -1;
    while(low <= high){
        mid = (low + high) / 2;
        if(arr->A[mid] == num){
            result = mid;
            break;
        }
        if(arr->A[mid] < num){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return result;
}

int Get(struct Array arr,int index){
    if(index < 0 && index >= arr.length){
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array *arr, int index, int num){
    if(index < 0 && index >= arr->length){
        arr->A[index] = num;
    }
}

int Sum(struct Array arr){
    if(arr.length > 0)
        return (arr.length * (arr.length + 1)) / 2;
    return -1;
}

int Max(struct Array arr){
    if(arr.length > 0){
        int max = arr.A[0];
        for(int i = 1; i < arr.length; i++){
            if(max < arr.A[i])
                max = arr.A[i];
        }
        return max;
    }
    return -1;
} 

int Min(struct Array arr){
    if(arr.length > 0){
        int min = arr.A[0];
        for(int i = 1; i < arr.length; i++){
            if(min > arr.A[i])
                min = arr.A[i];
        }
        return min;
    }
    return -1;
}

int Avg(struct Array arr){
    if(arr.length > 0){
    int sum = (arr.length * (arr.length + 1)) / 2;
    return sum / 2;
    }
    return -1;
}

void ReversingArrayBySwaping(struct Array *arr){
    int temp,i,j;
    for(i = 0,j = arr->length - 1; i < j; i++,j--){
       Swap(&arr->A[i],&arr->A[j]);
    }
}

void LeftShift(struct Array *arr){
    for(int i = 1; i < arr->length; i++)
        arr->A[i - 1] = arr->A[i];
    arr->A[arr->length - 1] = 0;
    arr->length--;
}

void RightShift(struct Array *arr){
    for(int i = arr->length - 1; i > 0; i--)
         arr->A[i] = arr->A[i - 1];
    arr->A[0] = 0;
    arr->length--;
}

void LeftRotate(struct Array *arr){
    int zeroValue = arr->A[0];
     for(int i = 1; i < arr->length; i++)
        arr->A[i - 1] = arr->A[i];
    arr->A[arr->length - 1] = zeroValue;
}

void RightRotate(struct Array *arr){
    int lastValue = arr->A[arr->length - 1];
    for(int i = arr->length - 2; i >= 0; i--){
        arr->A[i + 1] = arr->A[i];
    }
    arr->A[0] = lastValue;
}

//My version 
void InsertingInASortedList(struct Array *arr, int num){
    for(int i = arr->length - 1; i >= 0; i--){
        if(arr->A[i] < num){
        arr->A[i + 1] = num;
        arr->length++;
        break;
        }
        arr->A[i + 1] = arr->A[i];
        if(i == 0 && arr->A[i] >= num){
            arr->A[0] = num;
            arr->length++;
        }
    }
}

//Abdul Bhari version
void InsertingElementInSortedList(struct Array *arr, int num){
    int i = arr->length - 1;
    while(i >= 0 && arr->A[i] > num){
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = num;
    arr->length++;
}

bool CheckIfArraySorted(struct  Array arr){
    for(int i = 1; i < arr.length; i++){
        if(arr.A[i - 1] > arr.A[i]){
            return false;
        }
    }
    return true;
}

bool CheckIsNegative(int num){
    if(num < 0)
        return true;
    else
        return false;
}

//My version
void ArrangeNegativeOnLeftSide(struct Array *arr){
    int i=0,j=arr->length-1;
    while(i < j){
        if(!CheckIsNegative(arr->A[i])){
            while(i < j){
                if(CheckIsNegative(arr->A[j])){
                    Swap(&arr->A[i],&arr->A[j]);
                    break;
                }
                j--;
            }
        }
        i++;
    }
}

//Abdul Bhari version
void ArrangeNegativeOnLeftSideByAbdulBhari(struct Array *arr){
    int i = 0, j = arr->length - 1;
    while(i < j){
        while(arr->A[i] < 0) i++;
        while(arr->A[j] >= 0) j--;
        if(i < j) Swap(&arr->A[i],&arr->A[j]);
    }
}

void MergingArraysMyversion(struct Array *arr, struct Array *anotherarr, struct Array *resultArray){
    int i = 0; int j = 0; int a = 0 ;
    while(i < arr->length && j < anotherarr->length){
        if(arr->A[i] < anotherarr->A[j]){
            resultArray->A[a++] = arr->A[i++];
        }else{
            resultArray->A[a++] = anotherarr->A[j++];
        }
    }
    for(; i < arr->length ; i++){
        resultArray->A[a++] = arr->A[i];
            
    }
    for(; j < anotherarr->length ; j++){
        resultArray->A[a++] = anotherarr->A[j];
       
    }
    resultArray->length = arr->length + anotherarr->length;
}

//SetOperations
void Union(struct Array *arr, struct Array *anotherarr, struct Array *resultArray){
    int i = 0; int j = 0; int a = 0 ;
    while(i < arr->length && j < anotherarr->length){
        if(arr->A[i] < anotherarr->A[j]){
            resultArray->A[a++] = arr->A[i++];
        }else if(arr->A[i] > anotherarr->A[j]){
            resultArray->A[a++] = anotherarr->A[j++];
        }else{
            resultArray->A[a++] = arr->A[i++];
            j++;
        }
    }
    for(; i < arr->length ; i++){
        resultArray->A[a++] = arr->A[i];     
    }
    for(; j < anotherarr->length ; j++){
        resultArray->A[a++] = anotherarr->A[j];
    }
    resultArray->length = a;
}

void Intersection(struct Array *arr, struct Array *anotherarr, struct Array *resultArray){
    int i = 0; int j = 0; int a = 0 ;
    while(i < arr->length && j < anotherarr->length){
        if(arr->A[i] < anotherarr->A[j]){
           i++;
        }else if(arr->A[i] > anotherarr->A[j]){
            j++;
        }else{
            resultArray->A[a++] = arr->A[i++];
            j++;
        }
    }
    resultArray->length = a;
}

void Difference(struct Array *arr, struct Array *anotherarr, struct Array *resultArray){
    int i = 0; int j = 0; int a = 0 ;
    while(i < arr->length && j < anotherarr->length){
        if(arr->A[i] < anotherarr->A[j]){
           resultArray->A[a++] = arr->A[i++];
           i++;
        }else if(arr->A[i] > anotherarr->A[j]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    for(; i < arr->length ; i++){
        resultArray->A[a++] = arr->A[i];     
    }
    resultArray->length = a;
}

int main(){
    // printf("Welcome to Array ADT program \n");
    // struct Array arr;
    // printf("Enter the size of an Array \n");
    // scanf("%d",&arr.size);
    // arr.A =(int *) malloc(arr.size*sizeof(int));
    // printf("Enter the Length of the array \n");
    // scanf("%d",&arr.length);
    // printf("Enter the elements \n");
    // for(int i = 0; i < arr.length; i++){
    //     scanf("%d",&arr.A[i]);
    // }
    // Display(arr);
    // Add(&arr,4);
    // Insert(&arr,4,5);
    // Display(arr);
    // printf("returned value for delete function is %d\n",Delete(&arr,4));
    // Display(arr);
    // Insert(&arr,4,89);
    // Display(arr);
    // Insert(&arr,4,87);
    struct Array arr = {10,20,{11,-22,33,44,-55,-66,-77,-88,99,111}};
    // int index = BinarySearch(&arr,10,0,9);
    // printf("index is %d\n",index); 
    // int index1 = BinarySearchUsingLoop(&arr,5,0,9);
    // printf("index is %d\n",index1); 
    // Display(arr);
    // ReversingArrayBySwaping(&arr);
    // Display(arr);
    // LeftShift(&arr);
    // LeftShift(&arr);
    // LeftShift(&arr);
    // LeftShift(&arr);
    // LeftRotate(&arr);
    // LeftRotate(&arr);
    // LeftRotate(&arr);
    // LeftRotate(&arr);
    // LeftRotate(&arr);
    //RightRotate(&arr);
    //RightRotate(&arr);
    //InsertingInASortedList(&arr,1212);
    //printf("%d\n",CheckIfArraySorted(arr));
    //ArrangeNegativeOnLeftSide(&arr);
    //ArrangeNegativeOnLeftSideByAbdulBhari(&arr);
    struct Array arr1 = {5,20,{10,14,16,18,24}};
    struct Array arr2 = {5,20,{11,14,18,19,20}};
    struct Array resultArray;
    resultArray.size = 20;
    // MergingArraysMyversion(&arr1,&arr2,&resultArray);
    //Union(&arr1,&arr2,&resultArray);
    //Intersection(&arr1,&arr2,&resultArray);
    Difference(&arr1,&arr2,&resultArray);
    Display(resultArray);
}