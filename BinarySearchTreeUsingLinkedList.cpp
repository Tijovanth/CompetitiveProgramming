# include <iostream>
# include <stdio.h>
using namespace std;


struct Node{
    int data;
    struct Node * leftchild;
    struct Node * rightchild;
}*root = NULL;

struct Stack{
    Node ** data;
    int top;
    int size;
};


int isStackEmpty(struct Stack st){
    if(st.top == -1)
        return 1;
    else
        return 0;
}

Node * stackTop(struct Stack st){
    if(isStackEmpty(st))
        return NULL;
    else
        return st.data[st.top];
}

int isStackFull(struct Stack st){
    if(st.top == st.size - 1)
        return 1;
    else
        return 0;
}

void push(struct Stack *st, Node * num){
    if(isStackFull(*st))
        cout << "Stack Over flow " << endl;
    else{
        st->top++;
        st->data[st->top] = num;
    }  
}

Node * pop(struct Stack *st){
    if(isStackEmpty(*st)){
        cout << "Stack Under Flow " << endl;
        return NULL;
    }
    else{
        Node * x = st -> data[st ->top--];
       // st -> top--;
        return x;
    }
}

//Recursive version
Node * insertBinarySearchTree(struct Node *p, int key){
    if(p == NULL){
        Node *t = new Node;
        t -> data = key;
        t -> leftchild = t -> rightchild = NULL;
        return t;
    }
    if(key < p->data)
        p -> leftchild = insertBinarySearchTree(p -> leftchild,key);
    else if(key > p -> data)
        p -> rightchild = insertBinarySearchTree(p -> rightchild,key);
    return p;
}

//Iterative version
void insertBinarySearchTreeIterative(struct Node * p, int key){
    Node *t = NULL, *q = NULL;
    if(root == NULL){
        t = new Node;
        t -> data = key;
        t -> leftchild = t -> rightchild = NULL;
        root = t;
        return;
    }
    while(p != NULL){
        q = p;
        if(p -> data == key)
            return;
        else if(p -> data > key)
            p = p -> leftchild;
        else if(p -> data < key)
            p = p -> rightchild;
    }
    t = new Node;
    t -> data = key;
    t -> leftchild = t -> rightchild = NULL;
    if(key < q -> data)
        q -> leftchild = t;
    else
        q -> rightchild = t;
}

void DisplaySearchTreeInInorder(struct Node *p){
    if(p == NULL)
        return;
    DisplaySearchTreeInInorder(p ->leftchild);
    cout << p -> data << " ";
    DisplaySearchTreeInInorder(p -> rightchild);
}

//Recursive version
Node * SearchInBinarySearchTree(struct Node *p,int key){
    if( p == NULL)
        return NULL;
    if(p -> data == key)
        return p;
    if(key < p -> data)
        return SearchInBinarySearchTree(p -> leftchild,key);
    else
        return SearchInBinarySearchTree(p -> rightchild,key);
}

int CountLevelOfNodes(struct Node *t){
    int x,y;
    if(t != NULL){
        x = CountLevelOfNodes(t -> leftchild);
        y = CountLevelOfNodes(t -> rightchild);
        if(x > y)
            return x + 1;
        else
            return y + 1;
    }
    return 0;
}

Node * InPre(struct Node * p){
    while(p && p -> rightchild != NULL)
        p = p -> rightchild;
    return p;
}

Node * InSucc(struct Node * p){
    while(p && p -> leftchild != NULL)
        p = p -> leftchild;
    return p;
}

//Deleting from Binary Search Tree
Node * DeleteInBinarySearchTree(struct Node *p, int key){
    struct Node * q;
    if(p == NULL)
        return NULL;
    if(p -> leftchild == NULL && p -> rightchild == NULL)
    {
        if(root == p)
            root = NULL;
        delete p;
        return NULL;
    }
    if(key < p -> data)
        p -> leftchild = DeleteInBinarySearchTree(p -> leftchild,key);
    else if(key > p -> data)
        p -> rightchild = DeleteInBinarySearchTree(p -> rightchild,key);
    else{
        if(CountLevelOfNodes(p -> leftchild) > CountLevelOfNodes(p -> rightchild)){
            q = InPre(p -> leftchild);
            p -> data = q -> data;
            p -> leftchild = DeleteInBinarySearchTree(p -> leftchild,q -> data);
        }else{
            q = InSucc(p -> rightchild);
            p -> data = q -> data;
            p -> rightchild = DeleteInBinarySearchTree(p -> rightchild,q -> data);
        }
    }
    return p;
}

//My version
void GenerateBinarySearchTree(int * a, int n){
    struct Node * t = NULL; struct Node * p = NULL;struct Node * temp = NULL;
    int i = 1;
    struct Stack st;
    st.size = 100;
    st.top = -1;
    st.data = new Node *[100];
    t = new Node;
    t -> data = a[0];
    t -> leftchild = t -> rightchild = NULL;
    root = p = t;
    for(int i = 1; i < n; i++){
        if(a[i] < p -> data){
            t = new Node;
            t -> data = a[i];
            t -> leftchild = t -> rightchild = NULL;
            p -> leftchild = t;
            push(&st,p);
            p = t;
        }else if(a[i] > p -> data){
            int k = 0;
            while(k == 0){
                temp = stackTop(st);
                if(temp != NULL && a[i] >temp -> data  ){
                    p = pop(&st);
                }else{
                    k = 1;
                }
            }
            t = new Node;
            t -> data = a[i];
            t -> leftchild = t -> rightchild = NULL;
            if(a[i] > p -> data){
                p -> rightchild = t;
                p = t;
            }
            else{
                p -> leftchild = t;
                push(&st,p);
                p = t;
            }
        }else{
            continue;
        }
    }
}

int main(){
    // struct Node * temp;
    // root = insertBinarySearchTree(root,30);
    // root = insertBinarySearchTree(root,20);
    // root = insertBinarySearchTree(root,40);
    // root = insertBinarySearchTree(root,35);
    // root = insertBinarySearchTree(root,25);
    //
    insertBinarySearchTreeIterative(root,30);
    insertBinarySearchTreeIterative(root,20);
    insertBinarySearchTreeIterative(root,40);
    // insertBinarySearchTreeIterative(root,35);
    // insertBinarySearchTreeIterative(root,25);
    // insertBinarySearchTreeIterative(root,36);
    // DisplaySearchTreeInInorder(root);
    // temp =  SearchInBinarySearchTree(root,31);
    // if(temp)
    // cout << temp -> data << " " << endl;
    // else
    //     cout << "No data like that " << endl;
    DeleteInBinarySearchTree(root,40);
    DisplaySearchTreeInInorder(root);

    // int a[] = {30,20,10,15,25,40,50,45,8};
    // GenerateBinarySearchTree(a,9);
    // DisplaySearchTreeInInorder(root);
}   