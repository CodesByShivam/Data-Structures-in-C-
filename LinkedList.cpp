#include<iostream>

using namespace std;

struct Node{
     int data;
     struct Node *next;
};

Node *head = NULL;

void append(int value){
     Node *newNode = new Node();
     newNode->data = value;
     if(head == NULL){
             head = newNode;
     }
     else{
          Node *temp = head;
          while(temp->next){
               temp = temp->next;            
          }
          temp->next = newNode;
     }
}

void prepend(int value){
     Node *newNode = new Node();
     newNode -> data = value;
     if(head == NULL){
          head = newNode;
     }else{
          newNode->next = head;
          head = newNode;
     }
}

void addAtNthLocation(int value, int location){
     Node *newNode = new Node();
     newNode->data = value;
     if(head == NULL){
          head = newNode;
     }else if(location == 1){
         prepend(value);
     }else{
          Node *temp = head;
          for(int i=1; i<location-1;i++){
                // if(temp->next ==NULL && i<location-2){
                //      cout<< "apply append logic";
                // }else{
                //      temp = temp -> next;
                // }
              temp = temp->next;
          }
          Node *temp2 = temp->next;
          temp->next = newNode;
          newNode->next = temp2;
     }
}

void deleteFromNthLocation(int location){
     if(head == NULL){
          cout<<"Nothing to delete \n";
     }else if(location == 1){
          Node *temp = head->next;
          head = temp;
     }else{
          Node *temp = head;
          for(int i=1;i<location-1;i++){
               temp = temp->next;
          }
          Node *temp2 = temp->next;
          temp->next = temp2->next;
          free(temp2);
     }
}

void deleteValue(int value){
     if(head == NULL){
          cout<< "Nothing to delete \n";
     }else{
          int count = 0;

          //delete all the heads if they match the value
          while(head && head->data == value){
               count++;
               Node *temp = head;
               head = head->next;
               free(temp);
          }

          //delete other nodes
          Node *temp2 = head;
          while(temp2->next){
               if(temp2->next->data == value){
                    count++;
                    temp2->next = temp2->next->next;
               }else{
                    temp2 = temp2->next;
               }
          }

          cout <<"total nodes deleted = " <<count << "\n";
     }
}

void display(){
     Node *temp = head;
     while(temp){
         cout << temp->data << " ";
         temp = temp->next;
     }
     cout << "\n";
}

void reverseLinkedListRecursion(struct Node *n){
     if(head == NULL){
          cout << "No data to reverse \n";
          return;
     }
     if(n->next == NULL){
          head = n;
          return;
     }
     reverseLinkedListRecursion(n->next);
     Node *m = n->next;
     m->next = n;
     n->next = NULL;
}

void reverseLinkedListIteration(){
     Node *currentNode = head;
     Node *prev = NULL;
     Node *nextNode = NULL;
     while(currentNode){
          nextNode = currentNode->next;
          currentNode->next = prev;
          prev = currentNode;
          currentNode = nextNode;
     }
     head = prev;
}

void displayReverse(struct Node *head){
     if(head == NULL) return;
     displayReverse(head->next);
     cout<<head->data<<" ";
}

int main(){
    int flag = 1;
    int value = 0;
    int location = 0;
     while(flag){
          value = 0;
          location = 0;
          cout << "Linked List Operations : \n 1. Print \n 2. Append \n 3. Prepend \n 4. Enter data at Nth Position \n";
          cout << " 5. Delete from Nth Position \n 6. Delete a Value from all Nodes \n 7. Display reverse of Linked List \n";
          cout << " 8. Reverse Linked List using Recursion \n 9. Reverse Linked List using Iteration \n 10. Exit \n\n";
          int input;
          cin>>input;
          switch (input)
          {
          case 1:
               display();
               break;
          
          case 2:
               cout<<"enter the data to be added to end of the Linked list. : ";
               cin>> value;
               append(value);
               break;
          case 3:
               cout<<"enter the data to be added to start of the Linked list. : ";
               cin>> value;
               prepend(value);
               break;
          case 4:
               cout<<"enter number to be added : ";
               cin>> value;
               cout<<"enter the position to be entered : ";
               cin>> location;
               addAtNthLocation(value,location);
               break;
          case 5:
               cout<<"enter the position of the node to be deleted : ";
               cin >> location;
               deleteFromNthLocation(location);
               break;
          case 6:
               cout<<"enter the number to be deleted : ";
               cin >> value;
               deleteValue(value);
               break;
          case 7:
               displayReverse(head);
               break;
          case 8:
               reverseLinkedListRecursion(head);
               break;
          case 9:
               reverseLinkedListIteration();
               break;
          case 10:
               exit(0);
          default:
               break;
          }
     }
}