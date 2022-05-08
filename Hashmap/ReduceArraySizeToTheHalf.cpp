// 1338. Reduce Array Size to The Half


/*
    Input: arr = [3,3,3,3,5,5,5,2,2,7]
    Output: 2
    Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] 
    which has size 5 (i.e equal to half of the size of the old array).
    
    Possible sets of size 2 are {3,5},{3,2},{5,2}.
    
    Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5]
    which has a size greater than half of the size of the old array.    
*/

#include <bits/stdc++.h>
using namespace std;

    
    // Hashmap + Priority queue solution
    // Time Complexity - O(nlogn)
    // Space Complexity - O(n)
    int minSetSize(vector<int>& arr) {
        map<int,int> m;
        
        for(auto x:arr) m[x]++;
        
        priority_queue<pair<int,int>> pq;
        
        for(auto it = m.begin();it != m.end();it++){
            pq.push({it->second,it->first});
        }
        
        
        int removed = 0;
        int cnt = 0;
        while(pq.size()){
            pair<int,int> p = pq.top();
            pq.pop();
            removed += p.first;
            cnt++;
            if(removed >= arr.size()/2) return cnt;
        }
        
        return cnt;
    }


int main(){

    vector<int> arr = {3,3,3,3,5,5,5,2,2,7};

    cout<<minSetSize(arr);

    return 0;
}