// 1381. Design a Stack With Increment Operation

/*
	Input
		["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]
		[[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]
	Output
		[null,null,null,2,null,null,null,null,null,103,202,201,-1]
	Explanation
		CustomStack customStack = new CustomStack(3); // Stack is Empty []
		customStack.push(1);                          // stack becomes [1]
		customStack.push(2);                          // stack becomes [1, 2]
		customStack.pop();                            // return 2 --> Return top of the stack 2, stack becomes [1]
		customStack.push(2);                          // stack becomes [1, 2]
		customStack.push(3);                          // stack becomes [1, 2, 3]
		customStack.push(4);                          // stack still [1, 2, 3], Don't add another elements as size is 4
		customStack.increment(5, 100);                // stack becomes [101, 102, 103]
		customStack.increment(2, 100);                // stack becomes [201, 202, 103]
		customStack.pop();                            // return 103 --> Return top of the stack 103, stack becomes [201, 202]
		customStack.pop();                            // return 202 --> Return top of the stack 102, stack becomes [201]
		customStack.pop();                            // return 201 --> Return top of the stack 101, stack becomes []
		customStack.pop();                            // return -1 --> Stack is empty return -1.
*/

#include<bits/stdc++.h>
using namespace std;

class CustomStack {
public:
    vector<int> stack;
    int top;
    int size;
    int capacity;
    CustomStack(int maxSize) {
        stack.resize(maxSize,-1);
        top = -1;
        size = 0;
        capacity = maxSize;
    }
    
    void push(int x) {
        if(size == capacity) return;
        top++;
        stack[top] = x;
        size++;
    }
    
    int pop() {
        if(size == 0) return -1;
        int topE = stack[top];
        stack[top] = -1;
        top--;
        size--;
        return topE;
    }
    
    void increment(int k, int val) {
        int n = min(size,k);
        for(int i = 0;i<n;i++){
            stack[i] += val;
        }
    }
};


 int main(){
 	int maxSize = 3;
 	CustomStack* obj = new CustomStack(maxSize);
  	obj->push(1);                     
	obj->push(2);                         

	cout<<obj->pop()<<endl;                           

	obj->push(2);                         
	obj->push(3);                         
	obj->push(4);                         

	obj->increment(5, 100);               
	obj->increment(2, 100);

	cout<<obj->pop()<<endl;
	cout<<obj->pop()<<endl;
	cout<<obj->pop()<<endl;
	cout<<obj->pop()<<endl;

	return 0;
 }

  
 