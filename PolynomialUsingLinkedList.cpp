# include <iostream>
# include <stdio.h>
# include <math.h>
using namespace std;

struct Node{
    int coff;
    int exp;
    struct Node *next;
};

struct Node *poly = NULL;
struct Node *last = NULL;
struct Node *polysecond = NULL;
struct Node *polyAdd = NULL;

struct Node * createPoly(struct Node *p){
    Node *t;
    int num = 0;
    cout << "Enter the number of terms in polynomial " << endl;
    cin >> num;
    for(int i = 0; i < num; i++){
        t = new Node;
        cout << "Enter the coefficient of the term " << i << endl;
        cin >> t->coff;
        cout << "Enter the exponent of the term " << i << endl;
        cin >> t->exp;
        t -> next = NULL;
        if(p == NULL){
            p = last = t;
        }else{
            last -> next = t;
            last = t;
        }
    }
    return p;
}

void displayPoly(struct Node *p){
    while(p){
        if(p -> exp == 0)
            cout << p ->coff;
        else if(p -> exp == 1)
            cout << p ->coff << "x" << "+";
        else
            cout << p ->coff << "x" << p->exp << "+";
        p = p -> next;
    }
    cout << endl;
}

void evaluatePoly(struct Node *p, int x){
    int sum = 0;
    while(p){
       sum += p ->coff * pow(x,p->exp);
       p = p -> next;
    }
    cout << sum << " " << endl;
}

struct Node * AddingPoly(struct Node *p, struct Node *q, Node *r){
    Node *t;
    while(p && q){
        if(p->exp < q -> exp){
            t = new Node;
            t -> coff = q -> coff;
            t -> exp = q ->exp;
            t -> next = NULL;
            if(r == NULL){
                r = last = t;
            }else{
                last -> next = t;
                last = t;
            }
            q = q -> next;
        }else if(p -> exp > q -> exp){
            t = new Node;
            t -> coff = p -> coff;
            t -> exp = p ->exp;
            t -> next = NULL;
            if(r == NULL){
                r = last = t;
            }else{
            last -> next = t;
            last = t;
            }
            p = p -> next;
        }else{
            t = new Node;
            t -> exp = p ->exp;
            t -> coff = p -> coff + q -> coff;
            if(r == NULL){
                r = last = t;
            }else{
            last -> next = t;
            last = t;
            }
            p = p -> next;
            q = q -> next;
        }
    }
    while(p){
        t = new Node;
        t -> coff = p -> coff;
        t -> exp = p ->exp;
        t -> next = NULL;
        last -> next = t;
        last = t;
        p = p -> next;
    }
    while(q){
        t = new Node;
        t -> coff = q -> coff;
        t -> exp = q ->exp;
        t -> next = NULL;
        last -> next = t;
        last = t;
        q = q -> next;
    }
    return r;
}

int main(){
     poly = createPoly(poly);
     displayPoly(poly);
     evaluatePoly(poly,3);
     polysecond = createPoly(polysecond);
     displayPoly(polysecond);
     evaluatePoly(polysecond,3);
     polyAdd = AddingPoly(poly,polysecond,polyAdd);
     displayPoly(polyAdd);
}
