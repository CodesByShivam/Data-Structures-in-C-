#include<iostream>
using namespace std;

int a[100];
int top = -1;

void push(int x){
    if(top == 99){
        cout<<"OVERFLOW";
    }
    a[++top] = x;
}

void pop(){
    if(top == -1 ){
        cout<<"No elements to pop. \n";
        return;
    }
    cout<<"Deleted  "<<a[top--];
}

bool isEmpty(){
    if(top == -1){
        return true;
    }else{
        return false;
    }
}

void Top(){
    if(top == -1){
        cout<<"Empty Stack \n";
    }else{
        cout<< "Top element : " <<a[top];
    }
}

void display(){
    if(top == -1){
        cout<<"Empty Stack \n";
        return;
    }
    for(int i=0; i<=top;i++){
        cout<< a[i] << " ";
    }
    cout<<"<---- TOP";
}

int main(){
    int flag = 1;
    int value = 0;
    int location = 0;
     while(flag){
          value = 0;
          location = 0;
          cout << " Array Stack Operations : \n 1. Print \n 2. Push \n 3. Pop \n 4. Top \n";
          cout << " 5. IsEmpty \n";
          cout << " 6. Exit \n\n";
          int input;
          cin>>input;
          switch (input)
          {
          case 1:
               display();
               break;
          
          case 2:
               cout<<"enter the data to be added to top of Stack. : ";
               cin>> value;
               push(value);
               break;
          case 3:
               pop();
               break;
          case 4:
               Top();
               break;
          case 5:
               cout<<isEmpty();
               break;
          case 6:
                exit(0);
          default:
               break;
          }
     }
}