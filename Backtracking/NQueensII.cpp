// 52. N-Queens II


/*
    Input: n = 4
    Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

void solve(int col, vector<int>& leftRow, vector<int>& lDiag, vector<int>& uDiag, int n, int& cnt){
    if(col == n){
        cnt++;
        return;
    }
    
    for(int row = 0;row<n;row++){
        if(leftRow[row] == 0 && lDiag[n - 1 + col - row] == 0 && uDiag[row + col] == 0){
            leftRow[row] = 1;
            lDiag[n - 1 + col - row] = 1;
            uDiag[row + col] = 1;
            
            solve(col+1, leftRow, lDiag, uDiag, n, cnt);
            
            leftRow[row] = 0;
            lDiag[n - 1 + col - row] = 0;
            uDiag[row + col] = 0;
        }
    }
}
int totalNQueens(int n) {
    int cnt = 0;
    
    vector<int> leftRow(n, 0), lDiag(2*n - 1, 0), uDiag(2*n - 1, 0);
    
    solve(0, leftRow, lDiag, uDiag, n, cnt);
    
    return cnt;
}


int main(){

    int n;
    cin>>n;
    cout<<totalNQueens(n);

    return 0;
}