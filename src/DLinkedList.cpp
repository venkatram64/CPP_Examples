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
      head = NULL;
      tail = NULL;
    }
  public:
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
        temp->left = tail;
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

      temp->right = head;
      head->left = temp;
      head = temp;

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
}
