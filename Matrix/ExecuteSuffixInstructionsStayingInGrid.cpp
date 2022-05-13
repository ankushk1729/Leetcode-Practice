// 2120. Execution of All Suffix Instructions Staying in a Grid


/*
    Input: n = 3, startPos = [0,1], s = "RRDDLU"
    Output: [1,5,4,3,1,0]
    Explanation: Starting from startPos and beginning execution from the ith instruction:
    - 0th: "RRDDLU". Only one instruction "R" can be executed before it moves off the grid.
    - 1st:  "RDDLU". All five instructions can be executed while it stays in the grid and ends at (1, 1).
    - 2nd:   "DDLU". All four instructions can be executed while it stays in the grid and ends at (1, 0).
    - 3rd:    "DLU". All three instructions can be executed while it stays in the grid and ends at (0, 0).
    - 4th:     "LU". Only one instruction "L" can be executed before it moves off the grid.
    - 5th:      "U". If moving up, it would move off the grid.
*/

#include <bits/stdc++.h>
using namespace std;


void count(int n,int i,int j,int& cnt,int ind,string& s){
    if(i < 0 || j < 0 || i > n - 1 || j > n - 1) return;
    
    cnt++;
    
    if(s[ind] == 'D'){
        count(n,i+1,j,cnt,ind+1,s);
    }
    if(s[ind] == 'U'){
        count(n,i-1,j,cnt,ind+1,s);
    }
    if(s[ind] == 'L'){
        count(n,i,j-1,cnt,ind+1,s);
    }
    if(s[ind] == 'R'){
        count(n,i,j+1,cnt,ind+1,s);
    }
    
}
vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
    int cnt = -1;
    int len = s.length();
    vector<int> ans(len);
    for(int i = 0;i<len;i++){
        count(n,startPos[0],startPos[1],cnt,i,s);
        ans[i] = cnt;
        cnt = -1;
    }
    
    return ans;
}


int main(){

    vector<int> startPos = {0,1};
    string s = "RRDDLU";

    vector<int> ans = executeInstructions(3,startPos,s);

    for(auto x : ans) cout<<x<<" ";

    return 0;
}