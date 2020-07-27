 #include <iostream>
 #include <math.h> 
 #include <stdio.h>
using namespace std;

template <class T>

class DiagonalMatrix{
    private:
    T A[10];
    int n;
    public:
    DiagonalMatrix(){
        n = 3;
    }
    DiagonalMatrix(int num){
        n = num;
    }
    // ~Matrix(){
    //     delete []A;
    // }
    void SetMatrix(int i, int j, T x);
    T GetMatrix(int i, int j);
    void Display();
};

template<class T>
void DiagonalMatrix<T>::SetMatrix(int i, int j, T x){
    if( i == j){
        A[i - 1] = x;
    }
}

template<class T>
T DiagonalMatrix<T>::GetMatrix(int i, int j){
    if(i == j){
        return A[i];
    }else{
        return 0;
    }
}

template<class T>
void DiagonalMatrix<T>::Display(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                cout << A[i] << " ";
            }else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

template<class T>
class LowerTriangularMatrix{
    private:
    T *A;
    public:
    int n;
    LowerTriangularMatrix(int num){
        n = num;
        A = new T[n*(n+1)/2];
    }

    LowerTriangularMatrix(){
        n = 5;
        A = new T[n*(n+1)/2];
    }

    ~LowerTriangularMatrix(){
        delete []A;
    }

    void SetMatrix(int i, int j, int x);
    T GetMatrix(int i, int j);
    void Display();
};

template<class T>
void LowerTriangularMatrix<T>::SetMatrix(int i, int j, int x){
    if(i >= j){
        // Row Major formula
        //A[i*(i-1)/2+j-1] = x;
        // Column Major Formula
          A[n*(j-1)-(j-2)*(j-1)/2+i-j] = x;
    }
}

template<class T>
T LowerTriangularMatrix<T>::GetMatrix(int i, int j){
    if( i >= j){
        // Row Major formula
        //return A[i*(i-1)/2+j-1];
        // Column Major Formula
         return A[n*(j-1)-(j-2)*(j-1)/2+i-j];
    }
    return 0;
}

template<class T>
void LowerTriangularMatrix<T>::Display(){
    for(int i = 1; i <= n; i++){
        for(int j = 1 ; j <= n; j++){
            if(i >= j){
                // Row Major Formula
               //cout << A[i*(i-1)/2+j-1] << " ";
                // Column Major Formula
                cout << A[n*(j-1)-(j-2)*(j-1)/2+i-j] << " ";
            }else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

// class TriDiagonalMatrix{
    
// }

class Elements{
    public:
    int i; //row number
    int j; //column number
    int x;   // Element
};

class SparseMatrix{
    public:
    int m;
    int n;
    int nonzero;
    Elements *e; 
    SparseMatrix(int a, int b, int c){
        m = a;
        n = b;
        nonzero = c;
        e = new Elements[nonzero];
    }
    SparseMatrix(){
        m = 5;
        n = 5;
        nonzero =  5;
        e = new Elements[nonzero];
    }
    ~SparseMatrix(){
        delete []e;
    }

    friend ostream & operator<<(ostream &os, SparseMatrix &s);
    friend istream & operator>>(istream &is, SparseMatrix &s);
    SparseMatrix operator+(SparseMatrix &s);
};

istream & operator>>(istream &is, SparseMatrix &s){
    cout << "Enter the elements" << endl;
for(int i = 0; i < s.nonzero; i++){
        cin >> s.e[i].i >> s.e[i].j >> s.e[i].x;
    }
    return is;
}

 ostream & operator<<(ostream &os, SparseMatrix &s){
     cout << "The elements are " << endl;
    int k = 0;
    for(int i = 0; i < s.m; i++){
        for(int j = 0; j < s.n; j++){
            if(i == s.e[k].i && j == s.e[k].j){
                cout << s.e[k++].x << " ";
            }else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
    return os;
}

SparseMatrix SparseMatrix::operator+(SparseMatrix &s){
    int i,j,k;
    i=j=k=0;
    if(m!=s.m && n!=s.n){
        return SparseMatrix(0,0,0);
    }
    SparseMatrix *sum = new SparseMatrix(m,n,nonzero+s.nonzero);
    while(i < nonzero && j < s.nonzero){
        if(e[i].i < s.e[j].i){
            sum->e[k++] = e[i++];
        }else if(e[i].i > s.e[j].i){
            sum->e[k++] = s.e[j++];
        }else{
            if(e[i].j < s.e[j].j){
                sum->e[k++] = e[i++];
            }else if(e[i].j > s.e[j].j){
                sum->e[k++] = s.e[j++];
            }else{
                sum->e[k] = e[i];
                sum->e[k++].x = e[i++].x + s.e[j++].x;
            }
        }
    }
    for(;i<nonzero;i++)sum->e[k++]=e[i];
    for(;j<s.nonzero;j++)sum->e[k++]=s.e[j];
    sum->nonzero=k;
    return *sum;
}

class Term{
    public:
    int exp;
    int coff;
    char var[20];
};

class Polynomial{
    public:
    int n;
    Term *terms;
    Polynomial(){

    }
    Polynomial(int n){
        this->n = n;
        terms = new Term[n];
    }
    ~Polynomial(){
        delete []terms;
    }
    Polynomial operator+(Polynomial &p);
    friend istream & operator>>(istream &is, Polynomial &p);
    friend ostream & operator<<(ostream &os, Polynomial &p);
    int DerivationOfPolynomial(Polynomial &p);
};

istream & operator>>(istream &is, Polynomial &p){
    for(int i = 0; i < p.n; i++){
        cout << "Enter the coefficient and exponent and var of " << i <<  endl;
        cin >> p.terms[i].coff >> p.terms[i].exp >> p.terms[i].var[0];
        cout << endl;
    }
    return is;
}

ostream & operator<<(ostream &os, Polynomial &p){
    for(int i = 0; i < p.n; i++){
        printf("%d",p.terms[i].coff);
        printf("%c",p.terms[i].var[0]);
        printf("%d",p.terms[i].exp);
    }
    cout << endl;
    return os;
}

Polynomial Polynomial::operator+(Polynomial &p){
    int i,j,k;
    i=j=k=0;
    Polynomial *sum = new Polynomial(n+p.n);
    while(i < n && j < p.n){
        if(terms[i].exp > p.terms[j].exp){
            sum->terms[k++] = terms[i++];
        }else if(terms[i].exp < p.terms[j].exp){
            sum->terms[k++] = p.terms[j++];
        }else{
            sum->terms[k].exp = terms[i].exp;
            sum->terms[k].var[0] = terms[i].var[0];
            sum->terms[k++].coff = terms[i++].coff+p.terms[j++].coff;
        }
    }
    for(;i<n;i++)sum->terms[k++] = terms[i++];
    for(;j<n;j++)sum->terms[k++] = p.terms[j++];
    sum->n = k;
    return *sum;
}

int Polynomial::DerivationOfPolynomial(Polynomial &p){
    cout << p;
    cout << "Enter the value of variable x y z" << endl;
    int x,y,z,sum;
    sum = 0;
    cin >> x;
    cin >> y;
    cin >> z;
    for(int i = 0; i < p.n; i++){
        if(p.terms[i].var[0] == 'x'){
            sum += p.terms[i].coff * pow(x,p.terms[i].exp);
        }else if(p.terms[i].var[0] == 'y'){
            sum += p.terms[i].coff * pow(y,p.terms[i].exp);
        }else{
            sum += p.terms[i].coff * pow(z,p.terms[i].exp);
        }
    }
    return sum;
}

int main(){
    // DiagonalMatrix<int> mat(5);
    // mat.SetMatrix(1,1,1);
    // mat.SetMatrix(2,2,2);
    // mat.SetMatrix(3,3,3);
    // mat.SetMatrix(4,4,4);
    // mat.SetMatrix(5,5,5);
    // cout << mat.GetMatrix(2,2) << endl;
    // mat.Display();
    //  cout << "Enter the Dimensions" << endl;
    //  int n;
    //  cin >> n;
    // LowerTriangularMatrix<int> mat(n);
    // int x;
    // cout << "Set the  LowerTriangular Matrix" << endl;
    // for(int i = 1; i <= mat.n ; i++){
    //     for(int j = 1; j <= mat.n; j++){
    //         cin >> x;
    //         mat.SetMatrix(i,j,x);
    //     }
    //     cout << endl;
    // }

    // mat.Display();
    // cout << mat.GetMatrix(3,3);
//     int a,b,c;
//     cout << "Enter the first Matrix row Dimension" << endl;
//     cin >> a;
//     cout << "Enter the first Matrix column Dimension" << endl;
//     cin >> b;
//     cout << "Enter the first Matrix non zero Element" << endl;
//     cin >> c;
//     SparseMatrix mat1(a,b,c);
//     cin >> mat1;
//     cout << "Enter the Second Matrix row Dimension" << endl;
//     cin >> a;
//     cout << "Enter the Second Matrix column Dimension" << endl;
//     cin >> b;
//     cout << "Enter the Second Matrix non zero Element" << endl;
//     cin >> c;
//     SparseMatrix mat2(a,b,c);
//     cin >> mat2;

//     SparseMatrix sum = mat1 + mat2;
//     cout << mat1;
//     cout << mat2;
//     cout << sum;
int n;
cout << "Enter the First Polynomial total terms" << endl;
cin >> n;
Polynomial poly1(n);
cin >> poly1;
cout << "Enter the Second Polynomial total terms" << endl;
cin >> n;
Polynomial poly2(n);
cin >> poly2;
Polynomial sum = poly1 + poly2;
cout << sum.DerivationOfPolynomial(sum);
}


