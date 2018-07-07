#include <iostream>
using namespace std;

/*https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr
*/

struct Node{
  int data;
  Node *next;
};

class LinkedList{

  private:
    Node *head,*tail;
     public:
    LinkedList(){
      head = NULL;
      tail = NULL;
    }

    ~LinkedList(){
      head = NULL;
      tail = NULL;
    }
    /*
      insertion will happen at the end
    */
    void insert(int num){

      Node *temp = new Node();
      temp->data = num;
      temp->next = NULL;

      if(head == NULL){
        head = temp; //head will have temp address
        tail = temp; //tail will have temp address
      }else{
        tail->next = temp;  //address of newly create temp will be in tails next location
        tail = temp; 
      }

    }

    void print(){

      cout<<"Data: "<<endl;
      Node* temp = head;
      while(temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
      }
    }
    /*
      adds the element at first
    */
    void insertFront(int value){

      Node *temp = new Node();
      temp->data = value;
      temp->next = head;
      head = temp;
    }

    void deleteElement(int value){

      if(head != NULL){
        Node* current = head;
        if (head->data == value){
            head = head->next;
            cout<<"Deleting the Element "<<endl;
            delete current;
            return;
        }else{      
          Node *previous = head;
          current = head->next;
          while(current != NULL){
            if(current->data == value){
              break;
            }else{
              previous = current; 
              current = current->next; 
            }
          }
          if(current == NULL){
            cout << "Can't remove value: no match found.\n";  
          }else{
            cout<<"Deleting the Element "<<endl;
            previous->next = current->next; 
            delete current; 
          }
        }
      }
    }
    /*
      below method finds wheather element exists in list or not
    */
    bool find(int value){
      Node* temp = head;
      while(temp != NULL){
        if(temp->data == value){
          return true;
        }
        temp = temp->next;
      }
      return false;
    }



};

int main() {

  LinkedList ll;
  ll.insert(5);
  ll.insert(8);
  ll.insert(21);
  ll.insert(15);
  ll.insert(68);
  ll.insert(291);

  ll.print();

  ll.deleteElement(8);
  ll.print();

}