// 160. Intersection of Two Linked Lists


/*
    Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
    Output: Intersected at '2'
    Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
    From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4].
     There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == NULL || headB == NULL) return NULL;
    ListNode* t1 = headA;
    ListNode* t2 = headB;
    
    while(t1 != t2){
        
        t1 = !t1 ? headB : t1->next;
        t2 = !t2 ? headA : t2->next;
    }
    return t1;
}


int main(){

    ListNode* l1_1 = new ListNode(1);
    ListNode* l1_2 = new ListNode(9);
    l1_1->next = l1_2;
    ListNode* l1_3 = new ListNode(1);
    l1_2->next = l1_3;
    ListNode* l1_4 = new ListNode(2);
    l1_3->next = l1_4;
    ListNode* l1_5 = new ListNode(4);
    l1_4->next = l1_5;

    ListNode* l2_1 = new ListNode(3);
    ListNode* l2_2 = new ListNode(2);
    l2_1->next = l2_1;
    ListNode* l2_3 = new ListNode(4);
    l2_2->next = l1_3;

    ListNode* ans = getIntersectionNode(l1_1,l2_1);

    cout<<"Intersection at : "<<ans->val;

    return 0;
}