#include <iostream>
using namespace std;



struct ListNode {

    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};



class Solution {

public:

    ListNode* reverseList(ListNode* head) {


        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* next = NULL;


        while(current != NULL){

            next = current->next;

            current->next = prev;

            prev = current;

            current = next;
        }


        return prev;
    }

};



void printList(ListNode* head){

    while(head != NULL){

        cout << head->val << " ";

        head = head->next;
    }

    cout << endl;
}



int main(){


    

    ListNode* head = new ListNode(1);

    head->next = new ListNode(2);

    head->next->next = new ListNode(3);

    head->next->next->next = new ListNode(4);



    cout << "Before Reverse: ";
    printList(head);



    Solution obj;

    head = obj.reverseList(head);



    cout << "After Reverse: ";
    printList(head);



    return 0;
}