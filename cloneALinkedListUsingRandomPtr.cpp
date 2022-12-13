#include<iostream>
using namespace std;





// class solution{

// private:
// void insertAtTail(Node* &head,Node* &tail,int d){
//     Node* newNode = new Node(d);

//     if(head == NULL){
//         head = newNode;
//         tail = newNode;
//         return;

//     }
//     else{
//         tail->next = newNode;
//         tail = newNode;
//     }
// }


// public:
// Node *copyList(Node* head){

// //step 1 create a clone list
// Node* cloneHead =NULL;
// Node* cloneTail = NULL;

// Node* temp = head;

// while(temp != NULL){

//     insertAtTail(cloneHead,cloneTail,temp->data);
//     temp = temp->next;
// }

// //step 2

// //create a map unordered
// unordered_map<Node*,Node*> oldToNewNode;

// Node* originalNode = head;
// Node* cloneNode = cloneHead;

// while(originalNode != NULL && cloneNode != NULL){

//     oldToNewNode[originalNode] = cloneNode;
//     originalNode = originalNode->next;
//     cloneNode =cloneNode->next;
// }



//     while(originalNode != NULL){
//         cloneNode->random = oldToNewNode[originalNode->random];
//          originalNode = originalNode->next;
//          cloneNode =cloneNode->next;
//     }


// }



// };





//approach 3 wothout maps changing links of list
class solution{

private:
void insertAtTail(Node* &head,Node* &tail,int d){
    Node* newNode = new Node(d);

    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;

    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}


public:
Node *copyList(Node* head){

//step 1 create a clone list
Node* cloneHead =NULL;
Node* cloneTail = NULL;

Node* temp = head;

while(temp != NULL){

    insertAtTail(cloneHead,cloneTail,temp->data);
    temp = temp->next;
}

//step 2 ///add clone nodes into original list

Node* originalNode = head;
Node* cloneNode = cloneHead;


while(originalNode != NULL && cloneNode != NULL){

    Node* next = originalNode->next;
    orignalNode->next = cloneNode;
    originalNode = next;

    next = cloneNode->next;
    cloneNode->next = originalNode;
    cloneNode = next;
}

//step3
temp = head;
while (temp != NULL)
{
    if(temp->next != NULL){
        if(temp->random != NULL){
            temp->next->random = temp->random->next;
        }
    }
    else{
        temp->next = temp->random;
    }
    temp = temp->next->next;
}


//step4
originalNode = head;
cloneNode =cloneHead;
while(originalNode != NULL && cloneNode != NULL){

    originalNode->next = cloneNode->next;
    originalNode = originalNode->next;

    if(originalNode != NULL){
        cloneNode->next = originalNode->next;
    }
    cloneNode = cloneNode->next;
}




return cloneHead;
}
};