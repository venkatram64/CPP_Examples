#include <iostream>
using namespace std;


struct Node{
  int data;
  Node *next;
};

class CircularLinkedList{

  private:
    Node *last,*first;

  public:

    CircularLinkedList(){
      last = NULL;
      first = NULL;
    }

    ~CircularLinkedList(){
      last = NULL;
      first = NULL;
    }
    /*
      insertion will happen at the end
    */
    void insert(int num){

      Node *temp = new Node();
      temp->data = num;
      temp->next = NULL;

      if (last == NULL){
          last = temp;
          temp->next = last;   
      }else{
          temp->next = last->next; 
          last->next = temp;
          last = temp;
      }

    }

    void deleteByValue(int value){

      /* If List has only one element*/
      if (last->next == last && last->data == value){
          Node *temp = last;
          last = NULL;
          delete temp;
          return;
      }
      Node *current = last->next;
      /*First Element Deletion*/
      if (current->data == value){
          Node *temp = current;
          last->next = current->next;
          delete temp;
          return;
      }
      while (current->next != last){
        /*Deletion of Element in between*/
        if (current->next->data == value) {
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
            return;
        }
        current = current->next;
      }

      /*Deletion of last element*/
      if (current->next->data == value){
          Node *temp = current->next;
          current->next = last->next;
          delete temp;		
          last = current;
          return;
      }
    }

    void print(){

      cout<<"Data: "<<endl;
      Node* temp = last->next;
     
      while(temp != last){
        cout<<temp->data<<endl;
        temp = temp->next;
      }
      cout<<temp->data<<endl;
    }

};

int main() {

  CircularLinkedList ll;
  ll.insert(5);
  ll.insert(8);
  ll.insert(21);
  ll.insert(15);
  ll.insert(68);
  ll.insert(291);
  ll.print();
  /* deleting first element*/
  cout<<"Deleting First element"<<endl;
  ll.deleteByValue(5);
  ll.print();
  /* deleting middle element*/
  cout<<"Deleting middle element"<<endl;
  ll.deleteByValue(21);
  ll.print();
  /* deleting middle element*/
  cout<<"Deleting last element"<<endl;
  ll.deleteByValue(291);
  ll.print();

}
