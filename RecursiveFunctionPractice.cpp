#include <stdio.h>

// Tail Recursion
void fun(int n){
    if(n > 0){
    printf("%d \n",n);
    fun(n - 1);
    }
}
// Head Recursion
void fun1(int n){
    if(n > 0){
    fun1(n - 1);
    printf("%d \n",n);
    }
}

//Tree recursion
void fun3(int n){
    if(n > 0){
        printf("%d\n",n);
        fun3(n - 1); 
        fun3(n - 1);
    }
}

//Indirect Recursion
void functionA(int n);
void functionB(int n){
    if(n > 1){
        printf("%d\n",n);
        functionA(n/2);
    }
}

void functionA(int n){
    if(n > 0){
        printf("%d\n",n);
        functionB(n -1);
    }
}

//Nested Recursion
int fun4(int n){
    if( n > 100){
        return n - 10;
    }else{
        return fun4(fun4(n + 11));
    }
}

//Static variable and Global variable
int fun2(int n){
    static int x = 0;
    if(n > 0){
        x++;
        return fun2(n - 1) + x;
    }
    return 0;
}

//Sum of Natural Numbers
int sumOfNaturalNumbers(int n){
    if(n == 0)
     return 0;
    return sumOfNaturalNumbers(n-1)+n;
}
//Factorial Number
int factorial(int n){
    if(n == 0)
     return 1;
    return factorial(n - 1) * n;
}

//Power Using Recursion
int power(int m, int n){
    if(n > 0){
        return power(m,n-1)*m;
    }
    return 1;
}
// Faster version of power function
int fasterPower(int m, int n){
    if(n == 0)
     return 1;
    if(n % 2 == 0)
      return fasterPower(m*m,n/2);
    return m * fasterPower(m * m, (n - 1)/2);
}

//Taylor series
double taylorSeries(int x, int n){
    static double p = 1,f = 1;
    double r;
    if(n == 0)
     return 1;
    r = taylorSeries(x,n-1);
    p = p * x;
    f = f * n;
    return r + p / f;
}

//Taylor series with Horner's rule
double hornerTaylorSeries(int x, int n){
    static double s = 1;
    if( n == 0)
        return s;
    s = 1 + x / n * s;
    return hornerTaylorSeries(x,n-1);
}

//Fibonnaci series my version but obviously worst but time is O(n)
int fibonnaci(int n){
    static int b = 0;
    static int a = 1;
    static int c = 0;
    if (n == 0)
        return 0;
    fibonnaci(n-1);
    c = a + b;
    a = b;
    b = c;
    printf("%d\n",c);
    return c;
}

//Another version that time is also O(n) by Abdul bhari
int arr[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int fib(int n){
   if(n <= 1){
       arr[n] = n;
       return n;
   }else{
       if(arr[n-2] == -1)
            arr[n-2] =  fib(n-2);
        if(arr[n-1] == -1)
            arr[n-1] = fib(n-1);
        return arr[n-2]+arr[n-1];
   }
}

//Combination formula ncr
int combination(int n, int r){
    if( r == 0 || r == n){
        return 1;
    }else{
        return combination(n-1,r-1) + combination(n-1,r);
    }
}

int main(){
    int x = 3;
    // fun(x);
    //fun1(x);
    //printf("%d \n",fun2(5));
    //fun3(3);
    //functionA(20);
    //printf("%d\n",fun4(95));
    //printf("%d\n",sumOfNaturalNumbers(5));
    //printf("%d\n",factorial(-1));
    //printf("%d\n",power(2,8));
    //printf("%d\n",fasterPower(2,8));
    //printf("%lf\n",taylorSeries(1,10));
    //printf("%lf \n",hornerTaylorSeries(1,10));
    //fibonnaci(10);
    //printf("%d\n",fib(5));
    printf("%d\n",combination(4,2));
}

