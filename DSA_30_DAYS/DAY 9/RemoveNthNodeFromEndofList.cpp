#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int x){
        val = x;
        next = NULL;
    }
};

ListNode* removeNthFromEnd(ListNode* head, int n){

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* slow = dummy;
    ListNode* fast = dummy;

    for(int i = 0; i < n; i++){
        fast = fast->next;
    }

    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;

    return dummy->next;
}

void printList(ListNode* head){

    while(head){
        cout << head->val << " ";
        head = head->next;
    }
}

int main(){

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    cout << "Original List: ";
    printList(head);

    head = removeNthFromEnd(head, n);

    cout << "\nAfter Removing Node: ";
    printList(head);

    return 0;
}