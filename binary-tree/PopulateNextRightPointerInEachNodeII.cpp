// 117. Populating Next Right Pointers in Each Node II


/*
    Input: root = [1,2,3,4,5,null,7]
    Output: [1,#,2,3,#,4,5,7,#]
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


// Utility function to create binary tree for the question
Node* takeInputLevelWise() {
    int rootData;
    cout<<"Enter root data :"<<endl;
    cin>>rootData;
    if(rootData == -1) {
        return NULL;
    }
    Node* root = new Node(rootData);
    queue<Node*> remainingNodes;
    remainingNodes.push(root);
    while(remainingNodes.size()!= 0) {
        Node* front = remainingNodes.front();
        remainingNodes.pop();
        cout<<"Enter left child of "<<front->val<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData!= -1){
            Node* child = new Node(leftChildData);
            front->left = child;
            remainingNodes.push(child);
        }
        cout<<"Enter right child of "<<front->val<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData!= -1){
            Node* child = new Node(rightChildData);
            front->right = child;
            remainingNodes.push(child);
        }

    }
    return root;

}

// Utility function to print binary tree
void printTreeLevelWise(Node* root) {
    queue<Node*> remainingNodes;
    remainingNodes.push(root);
    while(remainingNodes.size()!= 0) {
        Node* front = remainingNodes.front();
        remainingNodes.pop();
        cout<<front->val<<":";
        if(front->left!= NULL) {
            cout<<"L"<<front->left->val<<", ";
            remainingNodes.push(front->left);
        }
        if(front->right!= NULL) {
            cout<<"R"<<front->right->val<<", ";
            remainingNodes.push(front->right);
        }
        if(front->next != NULL){
            cout<<"N"<<front->next->val;
        }
        cout<<endl;
    }
}



Node* connect(Node* root) {
    if(root == NULL) return NULL;
    
    queue<Node*> q;
    q.push(root);
    root->next = NULL;
    Node* prev = NULL;
    while(!q.empty()){
        int size = q.size();
        for(int i = 0;i<size;i++){
            Node* front = q.front();
            if(prev){
                prev->next = front;
            }
            q.pop();
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
            prev = front;
        }
        prev->next = NULL;
        prev = NULL;
    }
    return root;
}


int main(){

    Node* root = takeInputLevelWise();

    connect(root);

    printTreeLevelWise(root);

    return 0;
}