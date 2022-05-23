// 1337. The K Weakest Rows in a Matrix


/*
    Input: mat = 
    [[1,1,0,0,0],
     [1,1,1,1,0],
     [1,0,0,0,0],
     [1,1,0,0,0],
     [1,1,1,1,1]], 
    k = 3
    Output: [2,0,3]
    Explanation: 
    The number of soldiers in each row is: 
    - Row 0: 2 
    - Row 1: 4 
    - Row 2: 1 
    - Row 3: 2 
    - Row 4: 5 
    The rows ordered from weakest to strongest are [2,0,3,1,4]

*/

#include <bits/stdc++.h>
using namespace std;


vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    int rows = mat.size();
    int columns = mat[0].size();
    vector<int> ans;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i = 0;i<rows;i++){
        int ans = -1;
        int start = 0,end = columns-1;
        while(end >= start){
            int mid = (start + end)/2;
            if(mat[i][mid] == 1){
                ans = mid;
                start = mid + 1;
            }    
            else {
                end = mid - 1;
            }
        }
        pq.push(make_pair(ans+1,i));
    }
   while(k--){
       ans.push_back(pq.top().second);
       pq.pop();
   }
    
    return ans;
}


int main(){

    vector<vector<int>> mat = {
            {1,1,0,0,0},
            {1,1,1,1,0},
            {1,0,0,0,0},
            {1,1,0,0,0},
            {1,1,1,1,1}
        };

    vector<int> ans = kWeakestRows(mat,3);

    for(auto x : ans) cout<< x << " ";

    return 0;
}