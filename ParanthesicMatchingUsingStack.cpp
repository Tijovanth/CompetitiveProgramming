#include <iostream>
#include <stdio.h>
using namespace std;

struct Stack{
    int size;
    int top;
    char *s;
};

struct EvaluationStack{
    int size;
    int top;
    int *s;
};

int isStackFull(struct Stack st){
    if(st.top == st.size - 1)
        return 1;
    else
        return 0;
}

//This is for evaluation stack
int isStackFull(struct EvaluationStack st){
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

//This is for evaluation stack
int isStackEmpty(struct EvaluationStack st){
    if(st.top == -1)
        return 1;
    else
        return 0;
}

char stackTop(struct Stack st){
    if(isStackEmpty(st))
        return '-1';
    else
        return st.s[st.top];
}

//This is for evaluation stack
int stackTopEval(struct EvaluationStack st){
    if(isStackEmpty(st))
        return -1;
    else
        return st.s[st.top];
}

void push(struct Stack *st, char bracket){
    if(isStackFull(*st))
        cout << "Stack Over flow " << endl;
    else{
        st->top++;
        st->s[st->top] = bracket;
    }  
}

// This is for evaluation stack
void pushEval(struct EvaluationStack *st, int num){
    if(isStackFull(*st))
        cout << "Stack Over flow " << endl;
    else{
        st->top++;
        st->s[st->top] = num;
    }  
}


char pop(struct Stack *st){
    if(isStackEmpty(*st)){
        cout << "Stack Under Flow " << endl;
        return '-1';
    }
    else{
        char x = st -> s[st ->top--];
        return x;
       // st -> top--;
    }
}

//This is for evaluation stack
int popEval(struct EvaluationStack *st){
    if(isStackEmpty(*st)){
        cout << "Stack Under Flow " << endl;
        return -1;
    }
    else{
        int x = st -> s[st ->top--];
        return x;
    }
}

// Checking Paranthesis only
int isBalanceParanthesis(struct Stack *st, char *exp){
    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '('){
            push(st,exp[i]);
        }else if(exp[i] == ')'){
            if(isStackEmpty(*st)){
                cout << "Not Balance " << endl;
                return -1;
            }else{
                char x = pop(st);
                if(x != exp[i]){
                    cout << "Not Balance " << endl;
                    return -1;
                }
            }
        }
    }
    if(isStackEmpty(*st)){
        cout << "Balance " << endl;
        return 1;
    }else{
        cout << "Not Balance " << endl;
        return 0;
    }
}

//Checking all types of Brackets
int isBalanceBrackets(struct Stack *st, char *exp){
    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(st,exp[i]);
        }else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(isStackEmpty(*st)){
                cout << "Not Balance " << endl;
                return -1;
            }else{
                pop(st);
            }
        }
    }
    if(isStackEmpty(*st)){
        cout << "Balance " << endl;
        return 1;
    }else{
        cout << "Not Balance " << endl;
        return 0;
    }
}

int isOperand(char character){
    if(character == '*' || character == '+' || character == '-' || character == '/')
        return 0;
    else
        return 1;
}

int precedence(char character){
    if(character == '*' || character == '/')
        return 2;
    else if(character == '+' || character == '-')
        return 1;
    return 0;
}

//Infix to Postfix
char * infixToPostfixConversion(struct Stack *st, char * exp){
    int i = 0, j = 0;
    char * postfix = new char[strlen(exp) + 1];
    while(exp[i] != '\0'){
        if(isOperand(exp[i])){
            postfix[j++] = exp[i++];
        }else{
            if(precedence(exp[i]) > precedence(stackTop(*st)))
                push(st,exp[i++]);
            else
                postfix[j++] = pop(st);
        }
    }
    while(!isStackEmpty(*st)){
        postfix[j++] = pop(st);
    }
    postfix[j] = '\0';
    return postfix;
}
int doingOperation(int first, int second, char symbol){
    int result = 0;
    switch (symbol)
    {
    case '+':
        result = first + second;
        break;
    case '-':
        result = first - second;
        break;
    case '*':
        result = first * second;
        break;
    case '/':
        result = first / second;
        break;
    default:
        break;
    }
    return result;
}
int EvalPostfix(struct EvaluationStack *st, char * exp){
    for(int i = 0; exp[i] != '\0'; i++){
        if(isOperand(exp[i])){
            pushEval(st,exp[i]-'0');
        }else{
            int second = popEval(st);
            int first = popEval(st);
            int result = doingOperation(first,second,exp[i]);
            pushEval(st,result); 
        }
    }
    return popEval(st);
}

int main(){
    char exp[] = "(a+b)+(c+b))";
    Stack st;
    st.size = strlen(exp);
    st.s = new char[st.size];
    st.top = -1;
    // cout << isBalanceParanthesis(&st,exp) << endl;
    char exp1[] = "a+b*c";
    //cout << isBalanceBrackets(&st,exp1) << endl;
    char * postfix = infixToPostfixConversion(&st,exp1);
    for(int i = 0; postfix[i] != '\0'; i++){
        cout << postfix[i];
    }
    cout << endl;
    postfix = "234*+82/-";
    EvaluationStack es;
    es.size = strlen(postfix);
    es.top = -1;
    cout << EvalPostfix(&es,postfix) << " ";
}