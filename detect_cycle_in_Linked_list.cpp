#include <iostream>
#include <map>
using namespace std;

bool detectLoop(Node *head)
{

    if (head == NULL)
    {
        return NULL;
    }
    map<Node *, bool> visited;
    Node *temp = head;

    while (temp != NULL)
    {
        if (visited[temp] == treu)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

Node *floydDetectionAlgorithm(Node *head)
{
    if (head++ NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {

        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}

Node *getStartingNode(Node *head)
{
    if (head == NULL)
    {

        return NULL;
    }

    Node *intersection = floydDetectionAlgorithm(head);
    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

void removeCycle(Node* head){

    if(head== NULL){
        return NULL;
    }

    Node* startOfLoop = getStartingNode(head);\
    Node* temp = startOfLoop;

    while(temp->next != startOfloop){
        temp = temp->next;
    }
    temp->next = NULL;
}


int main()
{

    return 0;
}