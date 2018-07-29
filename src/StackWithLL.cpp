#include <iostream>
using namespace std;

struct Node{
  int data;
  Node *next;
};

class Stack {

  private:
    Node* top;

  public:

    Stack(){
      top = NULL;
    }

    ~Stack(){
      top = NULL;
    } 

    /*
      insertion will happen at the top
    */
    void push(int num){

      Node *temp = new Node();
      temp->data = num;
      temp->next = NULL;

      if(top == NULL){
        top = temp; //top will have temp address
      }else{
        temp->next = top;  //address of newly created temp will be in rear next location
		top = temp;//move the pointer
      }

    } 
    /*
      deletion will happen at the front
    */
    void pop(){
	
      Node* temp = top;

      if(isEmpty()){
        cout<<"Queue is empty"<<endl;
        return;
      }
      
      top = top->next;
      delete(temp); //freeing memery for deleted node
    }
    /*
      To check stack is empty or not empty
    */
    bool isEmpty(){
      if(top == NULL){
        return true;
      }else{
        return false;
      }
    }

    /*
      with display top element.
    */
    void showTop(){
	
      if(isEmpty()){
        cout<<"Top is empty"<<endl;
      }else{
        cout<<top->data;
      }
    }

    /*
      display all the elements
    */

    void displayStack(){

      if(isEmpty()){
        cout<<"Stack is empty" <<endl;
        return;
      }

      cout<<"Data: "<<endl;
      
      Node* temp = top;
      while(temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
      }
    }
};

int main(){
  Stack s;

  s.push(5);
  s.push(8);
  s.push(21);
  s.push(15);
  s.push(68);
  s.push(291);

  s.displayStack();

  //delete one element
  s.pop();
  s.displayStack();

  s.showTop();

}
