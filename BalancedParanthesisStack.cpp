#include<iostream>
#include<string>
using namespace std;

int top = -1;
char stack[100];

void push(char c){
    stack[++top] = c;
}

void pop(){
    stack[top--];
}

bool isEmpty(){
    if(top == -1){
        return true;
    }else{
        return false;
    }
}

bool arePair(char opening, char closing){
    if(opening == '(' && closing == ')') return true;
    else if(opening == '{' && closing == '}') return true;
    else if(opening == '[' && closing == ']') return true;
    return false;
}

bool checkExpression(string exp){
    for(int i = 0; i<exp.length(); i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(exp[i]);
        }else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(isEmpty() || !arePair(exp[top],exp[i])){
                return false;
            }else{
                pop();
            }
        }
    }
    return isEmpty();
}

int main(){
    if(checkExpression("[]{)")){
        cout<<"BALANCED";
    }else{
        cout<<"NOT BALANCED";
    }
}