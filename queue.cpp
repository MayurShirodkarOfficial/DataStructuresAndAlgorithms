#include<iostream>
using namespace std;

class nQueue{
public:     
    int* arr;
    int front;
    int rear ;
    int size;
public:
    nQueue(){
        arr = new int[10000];
        front = 0;
        rear = 0;
    }
    void enque(int data){
        if(rear == size){
            cout<<"Queue is full"<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }
    int dequeue(){
        if(front == rear){
            return -1;
        }
        else{
            arr[front] = -1 ;
            front++;
            if(front == rear){
                front =0;
                rear = 0;
            }
        }
    }
    
    bool isEmpty(){
        if(front == rear){
            return true;
        }
        else return false;
    }

    int mfront(){
        if(front == rear){
            return -1;
        }
        else{
            return arr[front];
        }
    }



};






int main(){


nQueue q;
q.enque(5);
q.enque(4);
q.enque(5);
q.enque(4);
q.enque(5);
q.enque(8);
q.dequeue();

cout<<q.mfront()<<endl;
// cout<<q.front;


    return 0;
}



















// int main()
// {
//     queue<int> q;
//     q.push(5);
//     q.push(10);
//     cout<<q.front()<<endl;
//     cout<<q.size();
//     return 0;
// }