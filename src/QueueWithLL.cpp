#include <iostream>
using namespace std;

struct Node{
  int data;
  Node *next;
};

class Queue {

  private:
    Node* front,*rear;

  public:

    Queue(){
      front = NULL;
      rear = NULL;
    }

    ~Queue(){
      front = NULL;
      rear = NULL;
    } 

    /*
      insertion will happen at the end for Queue
    */
    void enqueue(int num){

      Node *temp = new Node();
      temp->data = num;
      temp->next = NULL;

      if(front == NULL){
        front = temp; //front will have temp address
        rear = temp; //rear will have temp address
      }else{
        rear->next = temp;  //address of newly created temp will be in rear next location
        rear = temp; 
      }

    } 
    /*
      deletion will happen at the front
    */
    void dequeue(){
      Node* temp = front;

      if(isEmpty()){
        cout<<"Queue is empty"<<endl;
        return;
      }
      
      if(front == rear){
        front = rear = NULL;
      }else{
        front = front->next;
      }
      free(temp); //freeing memery for deleted node
    }
    /*
      To check queue is empty or not empty
    */
    bool isEmpty(){
      if(front == NULL && rear == NULL){
        return true;
      }else{
        return false;
      }
    }

    /*
      with display front element.
    */
    void showFront(){
      if(isEmpty()){
        cout<<"Queue is empty"<<endl;
      }else{
        cout<<front->data;
      }
    }

    /*
      display all the elements
    */

    void displayQueue(){

      if(isEmpty()){
        cout<<"Queue is empty" <<endl;
        return;
      }

      cout<<"Data: "<<endl;
      
      Node* temp = front;
      while(temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
      }
    }
};

int main(){
  Queue q;

  q.enqueue(5);
  q.enqueue(8);
  q.enqueue(21);
  q.enqueue(15);
  q.enqueue(68);
  q.enqueue(291);

  q.displayQueue();

  //delete one element
  q.dequeue();
  q.displayQueue();

  q.showFront();

}
