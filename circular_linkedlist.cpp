#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data " << val << endl;
    }
};

void insertNode(Node *&tail, int element, int d)
{
    if (tail == NULL)
    {

        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }

    else
    {
        // non empty list

        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}




void deleteNode(Node* &tail, int value){

     //empty list
     if(tail == NULL){
        cout<<"List is empty please check list ";
        return;
     }


    //non empty list
     else{
        //assume value is present is list;
        Node* prev=tail;
        Node* curr = prev->next;

        while(curr->data != value)
        {
            prev =curr;
            curr = curr->next;
        }
        //only one node
        if(curr == prev){
            tail = NULL;
        }
        prev->next = curr->next;
        if(tail == curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;


     }

}

void print(Node *tail)
{
    if(tail == NULL){
        cout<<"list is empty"<<endl;
        return;
    }
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}
bool isCircular(Node* head){
    if(head == NULL){
        return false;

    }
    Node* temp = head->next;

    while(temp != NULL && temp !=head){
        temp = temp->next;

    }

    if(temp == head){
        return true;

    }

    return false;

}

int main()
{

    Node *tail = NULL;
    insertNode(tail, 5, 3);
    print(tail);
    insertNode(tail, 3, 2);
    print(tail);

    // deleteNode(tail,3);
    // print(tail);
    // insertNode(tail, 3, 5);
    // print(tail);
    // insertNode(tail, 5, 7);
    // print(tail);
    // insertNode(tail, 7, 9);
    // print(tail);
    // insertNode(tail, 5, 6);
    // print(tail);
    // insertNode(tail, 9, 10);
    // print(tail);
    // insertNode(tail, 3, 4);
    // print(tail);
    // deleteNode(tail,3);
    // print(tail);
    bool m = isCircular(tail);
    cout<<endl<<m<<endl;

    return 0;
}