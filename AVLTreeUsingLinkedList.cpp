# include <iostream>
# include <stdio.h>
using namespace std;

struct Node{
    struct Node * leftchild;
    int data;
    int height;
    struct Node * rightchild;
}*root = NULL;

int NodeHeight(struct Node * p){
    int hr,hl;
    hl = p && p -> leftchild ? p ->leftchild -> height : 0;
    hr = p && p -> rightchild ? p -> rightchild -> height : 0;
    return hl > hr ? hl+1:hr+1;
}

int BalanceFactor(struct Node * p){
    int hr,hl;
    hl = p && p -> leftchild ? p ->leftchild -> height : 0;
    hr = p && p -> rightchild ? p -> rightchild -> height : 0;
    return hl - hr;
}

Node * LLRotation(struct Node * p){
    struct Node *pl = NULL; struct Node * plr = NULL;
    pl = p -> leftchild;
    plr = pl -> rightchild;
    pl->rightchild = p;
    p -> leftchild = plr;
    p -> height = NodeHeight(p);
    pl -> height = NodeHeight(pl);
    if(root == p)
        root = pl;
    return pl;
}

Node * LRRotation(struct Node * p){
    struct Node *pl , *plr = NULL;
    pl = p -> leftchild;
    plr = pl -> rightchild;
    pl -> rightchild = plr -> leftchild;
    p -> leftchild = plr -> rightchild;
    plr -> leftchild = pl;
    plr -> rightchild = p;
    p -> height = NodeHeight(p);
    pl -> height = NodeHeight(pl);
    plr -> height = NodeHeight(plr);
    if(root == p)
        root = plr;
    return plr;
}

Node * RRRotation(struct Node * p){
    struct Node *pr , *prl = NULL;
    pr = p -> rightchild;
    prl = pr -> leftchild;
    pr -> leftchild = p;
    p -> rightchild = prl;
    p -> height = NodeHeight(p);
    pr -> height = NodeHeight(pr);
    if(root == p)
        root = pr;
    return pr; 
}

Node * RLRotation(struct Node * p){
    struct Node *pr , *prl = NULL;
    pr = p -> rightchild;
    prl = pr -> leftchild;
    p -> rightchild = prl -> leftchild;
    pr -> leftchild = prl -> rightchild;
    prl -> leftchild = p;
    prl -> rightchild = pr;
    if(root == p)
        root = prl;
    return prl;
}

Node * InPre(struct Node * p){
    while(p && p -> rightchild){
        p = p -> rightchild;
    }
    return p;
}

Node * InSucc(struct Node * p){
    while(p && p -> leftchild){
        p = p -> leftchild;
    }
    return p;
}

Node * AVLTreeInsert(struct Node * p, int key){
    struct Node * t = NULL;
    if(p == NULL){
        t = new Node;
        t -> data = key;
        t -> rightchild = t -> leftchild = NULL;
        t -> height = 1;
        return t;
    }
    else if( key < p -> data)
        p -> leftchild = AVLTreeInsert(p -> leftchild, key);
    else if( key > p -> data)
        p -> rightchild = AVLTreeInsert(p -> rightchild, key);
    p -> height = NodeHeight(p);
    if(BalanceFactor(p) == 2 && BalanceFactor(p->leftchild) == 1)
        return LLRotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->leftchild) == -1)
        return LRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rightchild) == -1)
        return RRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rightchild) == 1)
        return RLRotation(p);

    return p;
}

Node * AVLTreeDelete(struct Node * p, int key){
    struct Node * q = NULL;
    if(p == NULL){
        return NULL;
    }
    if(p -> leftchild == NULL && p -> rightchild == NULL){
        if(root == p)
            root = NULL;
        delete p;
        return NULL;
    }else if(key < p -> data)
        p -> leftchild = AVLTreeDelete(p -> leftchild, key);
    else if(key > p -> data)
        p -> rightchild = AVLTreeDelete(p -> rightchild, key);
    else{
        if(NodeHeight(p -> leftchild) > NodeHeight(p -> rightchild)){
             q = InPre(p -> leftchild);
            p -> data = q -> data;
            p -> leftchild = AVLTreeDelete(p -> leftchild,q -> data);
        }else{
            q = InSucc(p -> rightchild);
            p -> data = q -> data;
            p -> rightchild = AVLTreeDelete(p -> rightchild,q -> data);
        }
    }
    p -> height = NodeHeight(p);
    if(BalanceFactor(p) == 2 && BalanceFactor(p->leftchild) == 1)
        return LLRotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p -> leftchild) == -1)
        return LRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p -> rightchild) == -1)
        return RRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p -> rightchild) == 1)
        return RLRotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p ->leftchild) == 0)
        return LLRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p -> rightchild) == 0)
        return RRRotation(p);

    return p;
}

 void preOrderTraversal(struct Node *n){
    if(n){
    cout << n -> data << " ";
    preOrderTraversal(n -> leftchild);
    preOrderTraversal(n -> rightchild);
    }
}

int main(){
    root = AVLTreeInsert(root,30);
    root = AVLTreeInsert(root,10);
    root = AVLTreeInsert(root,20);
    root = AVLTreeInsert(root,40);
    root = AVLTreeInsert(root,5);
    
    cout << "Preorder Traversal \n";
    preOrderTraversal(root);
    root = AVLTreeDelete(root,40);
    cout << "Preorder Traversal \n";
    preOrderTraversal(root);
    return 0;
}
