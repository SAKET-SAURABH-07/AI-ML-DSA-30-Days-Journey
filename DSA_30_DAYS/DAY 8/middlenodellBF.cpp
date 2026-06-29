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

    ListNode* middleNode(ListNode* head) {

        ListNode* counter = head;
        int icounter = 0;

        while(counter != NULL){

            icounter++;
            counter = counter->next;
        }

        int middle = icounter / 2;

        ListNode* trav = head;

        for(int i = 0; i < middle; i++){

            trav = trav->next;
        }

        return trav;
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
    head->next->next->next->next = new ListNode(5);


    cout << "Original Linked List: ";
    printList(head);


    Solution obj;

    ListNode* middle = obj.middleNode(head);


    cout << "Middle Node: ";
    cout << middle->val << endl;


    return 0;
}