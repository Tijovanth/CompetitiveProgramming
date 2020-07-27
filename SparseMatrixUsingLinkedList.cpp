# include <iostream>
# include <stdio.h>
using namespace std;

struct Node{
    int data;
    int column;
    struct Node *next;
};

struct SparseMatrix{
    int m;
    int n;
    struct Node *e;
}*Matrix = NULL;

struct SparseMatrix *Matrix2 = NULL;

void createMatrix(SparseMatrix *p){
    int row = 0;Node *q = NULL, *t = NULL;
    t = new Node;
    cout << "Enter the row you want " << endl;
    cin >> row;
    cout << "Enter the column number you want " << endl;
    cin >> t->column;
    cout << "Enter the data " << endl;
    cin >> t -> data;
    t -> next = NULL;
    //q = &p->e[row];
    q = &(*p).e[row];
    cout << q << " ";
    cout << q->data << " ";
    cout << (q-> next == NULL) << " ";
    if(q == NULL){
        cout << "inside if " << endl;
        q = t;
        p->e[row] = *q;
        cout <<"cout q " << q->column << q->data << endl;
    }else{
        cout << "inside else " << endl;
        while(q->next != NULL){
            cout << "while " << endl;
            cout << "q " << q->column << q->data << endl; 
            q = q -> next;
        }
        q -> next = t;
    }
}

void displayMatrix(SparseMatrix *p){
    Node *q;
    for(int i = 0; i < p->m; i++){
        q = &p->e[i];
        for(int j = 0; j < p->n; j++){
            if(q->column == j){
                cout << q->data << " ";
                q = q -> next;
            }else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main(){
    Matrix = new SparseMatrix;
    cout << "Enter the no of rows " << endl;
    cin >> Matrix->m;
    cout << "Enter the no of cols " << endl;
    cin >> Matrix->n;
    Matrix -> e = new Node[Matrix -> m];
    createMatrix(Matrix);
    createMatrix(Matrix);
    displayMatrix(Matrix);
}