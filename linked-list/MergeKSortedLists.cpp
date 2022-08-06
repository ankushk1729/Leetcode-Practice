// 23. Merge k Sorted Lists


/*
    Input: lists = [[1,4,5],[1,3,4],[2,6]]
    Output: [1,1,2,3,4,4,5,6]
    Explanation: The linked-lists are:
    [
      1->4->5,
      1->3->4,
      2->6
    ]
    merging them into one sorted list:
    1->1->2->3->4->4->5->6
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};    

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;
    
    for(auto l : lists){
      if(l) pq.push(l);  
    } 
    
    if(pq.empty()) return NULL;
    
    ListNode* head = pq.top();
    pq.pop();
    
    if(!head) return NULL;
    if(head->next) pq.push(head->next);
    
    ListNode* temp = head;
    
    while(!pq.empty()){
        temp->next = pq.top();
        pq.pop();
        temp = temp->next;
        if(temp->next) pq.push(temp->next);
    }
    
    return head;
}

// Driver code
void printList(ListNode* list){
    ListNode* temp = list;

    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}

int main(){

    /* Driver Code
    ListNode* l1 = new ListNode(1);
    ListNode* l1_1 = new ListNode(4);
    l1->next = l1_1;
    ListNode* l1_2 = new ListNode(5);
    l1_1->next = l1_2;

    ListNode* l2 = new ListNode(1);
    ListNode* l2_1 = new ListNode(3);
    l2->next = l2_1;
    ListNode* l2_2 = new ListNode(4);
    l2_1->next = l2_2;

    ListNode* l3 = new ListNode(2);
    ListNode* l3_1 = new ListNode(6);
    l3->next = l3_1;
    */

    vector<ListNode*> lists;

    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);

    ListNode* list = mergeKLists(lists);

    printList(list);

    return 0;
}