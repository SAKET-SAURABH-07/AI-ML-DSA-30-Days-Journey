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

ListNode* mergeTwoLists(ListNode* h1, ListNode* h2){

    if(h1 == NULL || h2 == NULL)
        return h1 == NULL ? h2 : h1;

    if(h1->val <= h2->val){
        h1->next = mergeTwoLists(h1->next, h2);
        return h1;
    }
    else{
        h2->next = mergeTwoLists(h1, h2->next);
        return h2;
    }
}

void printList(ListNode* head){

    while(head){
        cout << head->val << " ";
        head = head->next;
    }
}

int main(){

    ListNode* h1 = new ListNode(1);
    h1->next = new ListNode(3);
    h1->next->next = new ListNode(5);

    ListNode* h2 = new ListNode(2);
    h2->next = new ListNode(4);
    h2->next->next = new ListNode(6);

    ListNode* merged = mergeTwoLists(h1, h2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}