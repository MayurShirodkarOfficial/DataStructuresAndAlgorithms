#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // coonstructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    //destructor
    ~Node(){
        int value = this->data;
        delete next;
        this->next=NULL;
        cout<<"Memory is free for node with data" <<value <<endl;

    }
};

void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void InsertAtPosition(Node *&tail, Node *&head, int d, int position)
{
    // handing if the position is 1
    if (position == 1)
    {
        InsertAtHead(head, d);
        return;
    }

    // reaching node before the position
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // handing inserting at tail condition
    if (temp->next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }

    // creating a node of d tbe inserted at position
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}



void deleteNode(int position , Node* head){
    //first node
    if(position==1){
        Node* temp = head;
        head = head->next;
        //memory free
        temp->next=NULL;
        delete temp; 
    }

    //case1 delete middle node
    else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;



        while(cnt < position){
            prev = curr;
            curr=curr->next;
            cnt++;
        }
        

        prev->next = curr->next;
        if(curr->next == NULL){
            prev->next = NULL;
        }
        curr->next=NULL;
        delete curr;

    }

}


void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    print(head);
    InsertAtHead(head, 12);
    print(head);
    InsertAtHead(head, 20);
    print(head);
    InsertAtTail(tail, 18);
    print(head);

    InsertAtPosition(tail, head, 22, 3);
    print(head);
    // cout << node1->data << endl;
    // cout << node1->next << endl;
    deleteNode(5,head);
    print(head);
    return 0;
}



