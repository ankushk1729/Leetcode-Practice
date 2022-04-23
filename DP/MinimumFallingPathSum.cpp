// 931. Minimum Falling Path Sum

/*
    Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
    Output: 13
*/

#include<bits/stdc++.h>
using namespace std;

    /*
        No - 1
        First Approach - Recursion With Memoization
        Time Complexity - O(n*n) [n is no. of rows]
        Space Complexity - O(n*n) [For Memo Cache matrix ]
    */
    long long minSum(vector<vector<int>>& mat,vector<vector<int>>& dp,int i,int j){
        if(i >= mat.size() || j >= mat.size() || j < 0) return INT_MAX;
        
        if(dp[i][j] != -1) return dp[i][j];
            
        if(i == mat.size()-1) return mat[i][j];
        
        return dp[i][j] = mat[i][j] + min({minSum(mat,dp,i+1,j),minSum(mat,dp,i+1,j+1),minSum(mat,dp,i+1,j-1)});
        
    }

    int minFallingPathSumI(vector<vector<int>>& matrix) {
        long long mini = INT_MAX;
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int x = 0;x<matrix.size();x++){
            mini = min(mini,minSum(matrix,dp,0,x));
        }
        return mini;
    }


    /*
        No - 2
        Second Approach - Tablution (Bottom-up)
        Time Complexity - O(n*n) [n is no. of rows]
        Space Complexity - O(n*n) [For Memo Cache matrix ]
    */
    int minFallingPathSumII(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        for(int j = 0;j<n;j++){
            dp[n-1][j] = matrix[n-1][j];
        }
        int leftD,rightD,down;
        for(int i = n-2;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(j == 0) leftD = INT_MAX;
                else leftD = dp[i+1][j-1];
                
                if(j == n - 1) rightD = INT_MAX;
                else rightD = dp[i+1][j+1];
                
                int down = dp[i+1][j];
                
                dp[i][j] = matrix[i][j] + min({leftD,rightD,down});
            }
        }
        int mini = INT_MAX;
        
        for(int j = 0;j<n;j++){
            mini = min(mini,dp[0][j]);
        }
        return mini;
    }


    /*
    No - 3
        Third Approach - Tablution (Bottom-up) + Space Optimization
        Time Complexity - O(n*n) [n is no. of rows]
        Space Complexity - O(n) [ Only 1D vector carried to calculate current row from next row(bottom row) ]
    */
    int minFallingPathSumIII(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> next(n,0);
        
        for(int j = 0;j<n;j++){
            next[j] = matrix[n-1][j];
        }
        int leftD,rightD,down;
        for(int i = n-2;i>=0;i--){
            vector<int> curr(n,0);
            for(int j = n-1;j>=0;j--){
                if(j == 0) leftD = INT_MAX;
                else leftD = next[j-1];
                
                if(j == n - 1) rightD = INT_MAX;
                else rightD = next[j+1];
                
                int down = next[j];
                
                curr[j] = matrix[i][j] + min({leftD,rightD,down});
            }
            next = curr;
        }
        int mini = INT_MAX;
        
        for(int j = 0;j<n;j++){
            mini = min(mini,next[j]);
        }
        return mini;
    }


int main(){
    vector<vector<int>> grid = {{2,1,3},{6,5,4},{7,8,9}};

    cout<<minFallingPathSumI(grid)<<endl;
    cout<<minFallingPathSumII(grid)<<endl;
    cout<<minFallingPathSumIII(grid);

    return 0;
}    