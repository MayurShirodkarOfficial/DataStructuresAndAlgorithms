#include<iostream>
#include<vector>
using namespace std;


// O(n)  solution
class solution {
    private:
    bool checkPalindrome(vector<int> arr){
        int n = arr.size();
        int s = 0;
        int e =n - 1;
        while(s <= e){
            if(arr[s] != arr[e]){
                return 0;

            }
            s++;
            e--;
        }
        return 1;

    }
    public:
    bool isPalindrome(Node* head){
        vector<int> arr;
        Node* temp = head;

        
        while(temp != NULL){
            arr.push_back(temp->data);
            temp = temp ->next;
        }
        return checkPalindrome(arr);
    }
};


//Approach 2 O(n)


class Solution{
    private:
    Node* getMid(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            fast = fasst->next->next;
            slow = slow->next;
        }
        return slow;
    }

    Node* reverse(Node* head)
    {
        Node* curr = head;
        Node* prev =NULL;
        Node* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next =prev;
        }

    }
    public:


    bool isPalindrome(node* head){
        if(head == NULL){
            return true;
        }

        Node* middle = getMid(head);
        Node* temp = middle->next;
        middle->next = reverse(temp);


        //compare both halves
        Node* head1 = head;
        Node* head2 = middle->next;

        while(head2 != NULL){
            if(head1->data != head2->data){
                return false;
            }
            head1 = head->next;
            head2 = head->next;
        }
        //returning reversed list as it is ....wichninitially was reversed
        temp = middle ->next;
        middle->next= reverse(temp);
        return true;

    }

};
