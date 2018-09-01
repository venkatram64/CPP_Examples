#include <iostream>

using namespace std;


struct Node{
  int data;
  Node *left;
  Node *right;
};

class DList {

  private:
    Node *head,*tail;

  public:
    DList(){
      head = NULL;
      tail = NULL;
    }

    ~DList(){
      Node *temp = head;
      while(temp != NULL){
        Node *nd = temp;
        temp = temp->right;
        delete nd;
      }
    }
    //adding at end
    void append(int data){
      //construct node object
      Node *temp = new Node;
      temp->data = data;
      temp->left = NULL;
      temp->right = NULL;

      if(head == NULL){
        //head and tail points the newly created node
        head = temp;
        tail = temp;
      }else{  
        tail->right = temp;
        temp->left = tail;//previous node address
        tail = temp;//now tail points the temp, means it moves
      }
    }
    //adding at front
    void prepend(int data){
      //construct node object
      Node *temp = new Node;

      temp->data = data;
      temp->left = NULL;
      temp->right = NULL;
      //head should move previous node to newly created node
      temp->right = head;
      head->left = temp;
      //now head points to the newly created node
      head = temp;

    }
    //finding the length of list
    int length(){
      Node* current = head; 
      int count = 0; 
      while(current != NULL){
        current = current->right;
        count++;
      }
      return count;
    }

    //deleting the node
    void deleteElement(int value){
     
        //case 1: deleting first element
        Node* current = head;
        if(head->data == value){
          head = head->right;
          head->left = NULL;
          cout<<"deleting the element"<<endl;
          delete current;
          return;
        }
        
        Node* previous = head;
        current = head->right;
        while(current != NULL){
          if(current->data == value){
            cout<<"Deleting the element"<<endl;
            //case 2: middle element
            if(current->right != NULL){
              previous->right = current->right;
              Node* next = current->right;
              next->left = previous;
              delete current;
              break;
            }else{
              //case 3: if the elment is last
              previous->right = NULL;
              tail = previous;
              delete current;
              break;  
            }
          }else{
            previous = current;
            current = current->right;
          }
        }
        
    }

    void displayForward(){
      Node *temp = head;
      while(temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->right;
      }
    }

    void displayBackward(){
      Node *temp = tail;
      while(temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->left;
      }
    }

};


int main() {
  DList list;
  list.append(4);
  list.append(10);
  list.append(12);
  list.append(15);
  list.append(18);
  list.append(3);
  list.prepend(199);
  cout<<"forward display"<<endl;
  list.displayForward();
  cout<<"backward display"<<endl;
  list.displayBackward();
  cout<<"deleting element "<<endl;
  //testing deleting
  list.deleteElement(199);
  cout<<"forward display"<<endl;
  list.displayForward();
  cout<<"backward display"<<endl;
  list.displayBackward();
 
  //testing deleting for middle element
  list.deleteElement(15);
  cout<<"forward display"<<endl;
  list.displayForward();
  cout<<"backward display"<<endl;
  list.displayBackward();

  list.deleteElement(3);
  cout<<"forward display"<<endl;
  list.displayForward();
  cout<<"backward display"<<endl;
  list.displayBackward();
  
}
