// 341. Flatten Nested List Iterator

/*
    Input: nestedList = [[1,1],2,[1,1]]
    Output: [1,1,2,1,1]
    Explanation: By calling next repeatedly until hasNext returns false, 
    the order of elements returned by next should be: [1,1,2,1,1].
*/

#include <bits/stdc++.h>
using namespace std;

  class NestedInteger {
    public:
      // Return true if this NestedInteger holds a single integer, rather than a nested list.
      bool isInteger() const;
 
      // Return the single integer that this NestedInteger holds, if it holds a single integer
      // The result is undefined if this NestedInteger holds a nested list
      int getInteger() const;
 
      // Return the nested list that this NestedInteger holds, if it holds a nested list
      // The result is undefined if this NestedInteger holds a single integer
      const vector<NestedInteger> &getList() const;
  };
 

class NestedIterator {
public:
    vector<int> l;
    int ind = 0;
    
    // Recursively fill our list
    void fillList(vector<NestedInteger> &nestedList){
        for(auto x : nestedList){
            if(x.isInteger()){
                l.push_back(x.getInteger());
            }   
            else {
                fillList(x.getList());
            }
        } 
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        fillList(nestedList);
    }
    
    int next() {
        return l[ind++];
    }
    
    bool hasNext() {
        return ind < l.size();
    }
};

int main(){

  // Couldn't recreate the input list in this problem.

  NestedIterator i(nestedList);
  while (i.hasNext()) cout << i.next();
}