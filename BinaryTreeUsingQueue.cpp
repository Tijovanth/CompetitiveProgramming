# include <iostream>
# include <stdio.h>
using namespace std;

struct Node{
    struct Node *leftchild;
    int data;
    struct Node *rightchild;
}*root = NULL;

struct Queue{
    int front;
    int rear;
    int size;
    Node **q;
};

struct Stack{
    int top;
    int size;
    long long int *s;
};

int isStackFull(struct Stack st){
    if(st.top == st.size - 1)
        return 1;
    else
        return 0;
}

int isStackEmpty(struct Stack st){
    if(st.top == -1)
        return 1;
    else
        return 0;
}

void push(struct Stack *st, long long int num){
    if(isStackFull(*st))
        cout << "Stack Over flow " << endl;
    else{
        st->top++;
        st->s[st->top] = num;
    }  
}

long long int pop(struct Stack *st){
    if(isStackEmpty(*st)){
        cout << "Stack Under Flow " << endl;
        return -1;
    }
    else{
        long int x = st -> s[st ->top--];
       // st -> top--;
        return x;
    }
}

void create(struct Queue *q, int size){
    q -> size = size;
    q -> front = q -> rear = 0;
    q -> q = new Node*[size];
}

void circularEnqueue(struct Queue *q, Node * x){
    if((q -> rear + 1) % q -> size == q -> front){
        cout << "Queue is full" << " " << endl;
        return;
    }else{
        q -> rear = (q -> rear + 1) % q -> size;
        q -> q[q -> rear] = x;
    }
}

Node * circularDequeue(struct Queue *q){
    if(q -> front == q -> rear)
        return NULL;
    else{
        q -> front = (q -> front + 1) % q -> size;
        return q -> q[q -> front];
    }
}

int isEmpty(struct Queue *q){
    return q -> front == q -> rear;
}

void treeCreate(){
    struct Node *p; struct Node *t;
    int x;
    struct Queue q;
    create(&q,100);
    root = new Node;
    cout << "Enter the root value \n";
    cin >> root -> data;
    root -> leftchild = root -> rightchild = NULL;
    circularEnqueue(&q,root);
    while(!isEmpty(&q)){
        p = circularDequeue(&q);
        cout << "Enter the left child value of " << p -> data << "\n";
        cin >> x;
        if(x != -1){
            t = new Node;
            t -> data = x;
            t -> leftchild = t -> rightchild = NULL;
            p -> leftchild = t;
            circularEnqueue(&q,t);
        }
        cout << "Enter the right child value of " << p -> data << "\n";
        cin >> x;
        if(x != -1){
            t = new Node;
            t -> data = x;
            t -> leftchild = t -> rightchild = NULL;
            p -> rightchild = t;
            circularEnqueue(&q,t);
        }
    }
}

void preOrderTraversal(struct Node *n){
    if(n){
    cout << n -> data << " ";
    preOrderTraversal(n -> leftchild);
    preOrderTraversal(n -> rightchild);
    }
}

void inOrderTraversal(struct Node *n){
    if(n){
    inOrderTraversal(n -> leftchild);
    cout << n -> data << " ";
    inOrderTraversal(n -> rightchild);
    }
}

void postOrderTraversal(struct Node *n){
    if(n){
    postOrderTraversal(n -> leftchild);
    postOrderTraversal(n -> rightchild);
    cout << n -> data << " ";
    }
}

// PreOrderTraversal for iterative order
// void preOrderTraversalInterativeOrder(struct Node * t, struct Stack * st){
//     st ->size = 100;
//     st ->top = -1;
//     st ->s = new Node *[100];
//     cout << "preorder traversal iterative procedure " << endl;
//     while(t != NULL || !isStackEmpty(*st)){
//         if(t != NULL){
//             cout << t -> data << " ";
//             push(st,t);
//             t = t -> leftchild;
//         }else{
//             t = pop(st);
//             t = t -> rightchild;
//         }
//     }
//     delete st -> s;
// }

// // InorderTraversal for iterative order
// void inOrderTraversalInterativeOrder(struct Node * t, struct Stack *st){
//     st ->size = 100;
//     st ->top = -1;
//     st ->s = new Node *[100];
//     cout << "inorder traversal iterative procedure " << endl;
//     while(t != NULL || !isStackEmpty(*st)){
//         if(t != NULL){
//             push(st,t);
//             t = t -> leftchild;
//         }else{
//             t = pop(st);
//             cout << t -> data << " ";
//             t = t -> rightchild;
//         }
//     }
//     delete st -> s;
// }

void postOrderTraversalInterativeOrder(struct Node *t, struct Stack *st){
    st ->size = 100;
    st ->top = -1;
    st ->s = new long long int[100];
    long long int temp;
    cout << "postorder traversal iterative procedure " << endl;
    while(t != NULL || !isStackEmpty(*st)){
        if(t != NULL){
            push(st,(long long int)t);
            t = t -> leftchild;
        }else{
            temp = (long long int)pop(st);
            if(temp > 0){
                push(st,-temp);
                t = ((Node *) temp) -> rightchild;
            }else{
                cout << ((Node *)-temp) -> data << " ";
                t = nullptr;
            }
        }
    }
    delete st -> s;
}

void LevelOrderTraverasal(struct Node *t){
    struct Queue q1; struct Node *x;
    create(&q1,100);
    circularEnqueue(&q1,t);
    cout << "Level Order Traversal " << endl;
    while(!isEmpty(&q1)){
        x = circularDequeue(&q1);
        cout << x -> data << " ";
        if(x->leftchild)
            circularEnqueue(&q1,x -> leftchild);
        if(x -> rightchild)
            circularEnqueue(&q1,x -> rightchild);
    }
    cout << endl;
}

int CountNodes(struct Node *t){
    int x,y;
    if(t != NULL){
        x = CountNodes(t -> leftchild);
        y = CountNodes(t -> rightchild);
        return x + y + 1;
    }
    return 0;
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

int CountNumberOfLeafNodes(struct Node *t){
    int x,y;
    if(t != NULL){
        x = CountNumberOfLeafNodes(t -> leftchild);
        y = CountNumberOfLeafNodes(t -> rightchild);
        if(t -> rightchild == NULL && t -> leftchild == NULL){
            return x + y + 1;
        }else{
            return x + y;
        }
    }
    return 0;
}

int CountNumberOfNodesHaveTwoChildNodes(struct Node *t){
    int x,y;
    if(t != NULL){
        x = CountNumberOfNodesHaveTwoChildNodes(t -> leftchild);
        y = CountNumberOfNodesHaveTwoChildNodes(t -> rightchild);
        if(t -> rightchild != NULL && t -> leftchild != NULL){
            return x + y + 1;
        }else{
            return x + y;
        }
    }
    return 0;
}

int CountNumberOfNonLeafNodes(struct Node *t){
    int x,y;
    if(t != NULL){
        x = CountNumberOfNonLeafNodes(t -> leftchild);
        y = CountNumberOfNonLeafNodes(t -> rightchild);
        if(t -> rightchild != NULL || t -> leftchild != NULL){
            return x + y + 1;
        }else{
            return x + y;
        }
    }
    return 0;
}

int CountNumberOfNodesHavingOneChild(struct Node *t){
    int x,y;
    if(t != NULL){
        x = CountNumberOfNodesHavingOneChild(t -> leftchild);
        y = CountNumberOfNodesHavingOneChild(t -> rightchild);
        if(t -> rightchild != NULL ^ t -> leftchild != NULL){
            return x + y + 1;
        }else{
            return x + y;
        }
    }
    return 0;
}

int main(){
    treeCreate();
    cout << "preorder traversal \n";
    preOrderTraversal(root);
    cout << endl;
    cout << "inorder traversal \n";
    inOrderTraversal(root);
    cout << endl;
    cout << "postorder traversal \n";
    postOrderTraversal(root);
    cout << endl;
    Stack st;
    // preOrderTraversalInterativeOrder(root,&st);
    // cout << endl;
    // inOrderTraversalInterativeOrder(root,&st);
    // cout << endl;
    // postOrderTraversalInterativeOrder(root,&st);
    LevelOrderTraverasal(root);
    cout << "Number of Nodes " << CountNodes(root) << endl;
    cout << "Level of Nodes " << CountLevelOfNodes(root) << endl;
    cout << "Leaf Nodes " << CountNumberOfLeafNodes(root) << endl;
    cout << "CountNumber of NonLeafNodes " << CountNumberOfNonLeafNodes(root) << endl;
    cout << "CoutNumber of Nodes having two child " << CountNumberOfNodesHaveTwoChildNodes(root) << endl;
    cout << "CoutNumber of Nodes having one child " << CountNumberOfNodesHavingOneChild(root) << endl;
}
