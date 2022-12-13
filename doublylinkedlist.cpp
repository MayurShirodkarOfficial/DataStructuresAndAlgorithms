#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node(){

        int val = this->data;
        if(next!=NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory free for node with data "<<val<<endl;
    }
};

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int length(Node *head)
{
    Node *temp = head;
    int length = 0;

    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    return length;
}

void insertAtHead(Node* &head,int d){
    Node* temp = new Node(d);
    temp->next=head;
    head->prev =temp;
    head = temp;

}

insertAtTail(Node* &tail,int d){
    Node * temp =new Node(d);

    tail->next = temp;
    temp->prev =tail;
    tail = temp;

}

void insertAtPosition(Node* &head, Node* &tail,int position,int d){
    //insert at head
    if(position == 1){
        insertAtHead(head,d);
        return;
    }

    //traversing and reaching the reuired poition - 1
    Node* temp =head;
    int cnt =1;
    while(cnt < position - 1 ){
        temp = temp->next ;
        cnt++;
    }
    //inserting at last or tail position
    if(temp->next == NULL){
        insertAtTail(tail,d);
        return;
    }

    //inserting at position
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next =temp->next;
    temp->next->prev = nodeToInsert;
    temp ->next = nodeToInsert;
    nodeToInsert->prev =temp;

}

void deleteNode(Node* &head,Node* &tail, int position){
    //delete at head

    if(position == 1){

        Node* temp = head;
        temp->next->prev =NULL;
        head =temp->next;
        temp->next = NULL;
        delete temp;

    }

    else{
        Node* curr= head;
        Node* prev = NULL;
        int cnt =1;
        while(cnt<position){

            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if(curr->next == NULL){
            tail = prev;
        }
        curr ->prev = NULL;
        prev->next =curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertAtHead(head,11);
    print(head);
    insertAtTail(tail,11);
    print(head);
    insertAtPosition(head,tail,2,25);
    print(head);
    insertAtPosition(head,tail,1,100);
    print(head);
    deleteNode(head ,1);
    print(head);
    return 0;
}
