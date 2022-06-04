// 51. N-Queens


/*
    Input: n = 4
    Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
    Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
*/

#include <bits/stdc++.h>
using namespace std;

void solve(int col, vector<vector<string>>& ans,vector<string>& board,vector<int>& leftRow, vector<int>& lDiag, vector<int>& uDiag,int n){
    
    if(col == n){
        ans.push_back(board);
        return;
    }
    
    for(int row = 0;row<n;row++){
        if(leftRow[row] == 0 && lDiag[n - 1 + col - row] == 0 && uDiag[row + col] == 0){
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lDiag[n - 1 + col - row] = 1;
            uDiag[row + col] = 1;
            
            solve(col+1,ans,board,leftRow,lDiag,uDiag,n);
            board[row][col] = '.';
            leftRow[row] = 0;
            lDiag[n - 1 + col - row] = 0;
            uDiag[row + col] = 0;
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    
    vector<string> board(n);
    
    string s(n,'.');
    
    for(int i = 0;i<n;i++){
        board[i] = s;
    }
    
    vector<int> leftRow(n,0), lDiag(2*n - 1,0), uDiag(2*n - 1,0);
    
    solve(0,ans,board,leftRow,lDiag,uDiag,n);
    
    return ans;
}


int main(){

    int n;
    cin>>n;
    vector<vector<string>> ans = solveNQueens(n);

    for(auto x : ans){
        for(auto y : x){
            cout<<y<<endl;
        }
    }

    return 0;
}