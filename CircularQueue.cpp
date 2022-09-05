#include<iostream>

using namespace std;

class CircularQueue {
  public:
    int front;
    int rear;
    int arr[5];
    int count_Elements;

    CircularQueue(){
      count_Elements = 0;
      front = -1;
      rear = -1;
      for(int i = 0; i < 5; i++){
        arr[i] = 0;
      }
    }

  bool is_full(){
    if((rear+1) % 5 == front)
      return true;
    else
      return false;
  }
  
  bool is_empty(){
    if(front == -1 && rear == -1)
      return true;
    else
      return false;
  }

  void enqueue(int value){
    if(is_full()){
      cout<<" Error, Array is full, you cannot add "<<endl;
    }else if(is_empty()){
      front = 0;
      rear = 0;
      arr[rear]= value;
      count_Elements++;
    }else{
      rear = (rear + 1) % 5;
      arr[rear]= value;
      count_Elements++;
    }
  }

  int dequeue(){
    int copy;
    if(is_empty()){
      cout<<" Error, array is empty, you cannot take out any elements"<<endl;
      return 0;
    }
    else if(front==rear){
      copy = arr[front];
      arr[front] = 0;
      front = rear = -1;
      count_Elements--; 
      return copy;  

    }else{
      copy = arr[front];
      arr[front] = 0;
      front = (front+1) % 5;  
      count_Elements--; 
      return copy;
    }


  }

  int count(){
    return count_Elements;
  }

  void display(){
    for(int i = 0; i<5; i++){
      cout<<arr[i]<<" ";
    }
  }


};

int main() {

/*   CircularQueue q1;
  cout<<q1.count(); */

  int value;
  int choice;
  CircularQueue q1;
do
{
  cout<<"\n enter a choice below that you want to perform by number: 0 to exit: "<<endl;
  cout<<"1. enqueue"<<endl;
  cout<<"2. dequeue"<<endl;
  cout<<"3. is full?"<<endl;
  cout<<"4. is empty?"<<endl;
  cout<<"5. count "<<endl;
  cout<<"6. display"<<endl;
  cin>>choice;

  switch(choice){
    case 1:
      cout<<" 1. enqueue "<<endl;
      cout<<"enter a value to enqueue: ";
      cin>>value;
      q1.enqueue(value);
      break;

    case 2:
      cout<<"2. dequeue"<<endl;
      q1.dequeue();
      break;
    
    case 3:
      cout<<"3. is full?"<<endl;
      cout<<q1.is_full()<<endl;
      break;

    case 4:
      cout<<"4. is empty?"<<endl;
      cout<<q1.is_empty()<<endl;
      break;

    case 5:
      cout<<"5. count "<<endl;
      cout<<q1.count()<<endl;
      break;

    case 6:
      cout<<"6. display"<<endl;
      q1.display();
      break;
    
    default:
      cout<<" error, enter a correct choice"<<endl;
  }
  
} while (choice != 0);

  return 0;
}