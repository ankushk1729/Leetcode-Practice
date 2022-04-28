#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

    ListNode* mergeNodes(ListNode* head) {
        ListNode* prev = head;
        ListNode* temp = prev->next;
        int sum = 0;
        int cnt = 0;
        while(temp!= NULL){
            if(temp->val == 0){
                ListNode* node = new ListNode(sum);
                node->next = temp->next;
                prev->next = node;
                sum = 0;
                prev = node;
                if(cnt == 0) head = node;
                cnt++;
                temp = temp->next;
            }
            else{
                sum += temp->val;
                temp = temp->next;
            }
        }
        return head;
    }


int main(){

	ListNode* head = new ListNode(0);
	ListNode* n1 = new ListNode(3);
	head->next = n1;
	ListNode* n2 = new ListNode(1);
	n1->next = n2;
	ListNode* n3 = new ListNode(0);
	n2->next = n3;
	ListNode* n4 = new ListNode(4);
	n3->next = n4;
	ListNode* n5 = new ListNode(5);
	n4->next = n5;
	ListNode* n6 = new ListNode(2);
	n5->next = n6;
	ListNode* n7 = new ListNode(0);
	n6->next = n7;

	ListNode* ans = mergeNodes(head);

	while(ans!=NULL){
		cout<<ans->val<<" ";
		ans = ans->next;
	}

	return 0;
}    