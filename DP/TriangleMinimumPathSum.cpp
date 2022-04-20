#include<bits/stdc++.h>
using namespace std;


/*  No - 1
    First Approach - Simple Recursive solution 
    Time Complexity - Exponential
    Space Complexity - O(n*n) [Auxillary Recursion Stack Space]
*/

int minSum_Simple_Recur(int i,int j,vector<vector<int>>& triangle,int n){
    if(i == n - 1) return triangle[n-1][j];
        
    int down = triangle[i][j] + minSum_Simple_Recur(i+1,j,triangle,n);
    int diagonal = triangle[i][j] + minSum_Simple_Recur(i+1,j+1,triangle,n);
        
    return min(down,diagonal);
}

/*
    No - 2
    Second Approach - Recursion With Memoization
    Time Complexity - O(n*n) [n is no. of rows in triangle]
    Space Complexity - O(n*n) [For Memo Cache matrix ]
*/

int minSum_Recur_With_Memo(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp,int n){
    if(i == n - 1) return triangle[n-1][j];

    if(dp[i][j] != -1) return dp[i][j];

    int down = triangle[i][j] + minSum_Recur_With_Memo(i+1,j,triangle,dp,n);
    int diagonal = triangle[i][j] + minSum_Recur_With_Memo(i+1,j+1,triangle,dp,n);

    return dp[i][j] = min(down,diagonal);
}

// Starter function for approach 1 & 2
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();

    // Cache for approach 2
    vector<vector<int>> dp(n,vector<int>(n,-1));

    // return minSum_Simple_Recur(0,0,triangle,n);
    return minSum_Recur_With_Memo(0,0,triangle,dp,n);
}


/*
    No - 3
    Third Approach - Tablution (Bottom-up)
    Time Complexity - O(n*n) [n is no. of rows in triangle]
    Space Complexity - O(n*n) [For Memo Cache matrix ]
*/


int minimumTotal_Tabulation(vector<vector<int>>& triangle){
    int n = triangle.size();
    vector<vector<int>> dp(n,vector<int>(n,0));

    for(int j = 0;j<n;j++){
        dp[n-1][j] = triangle[n-1][j];
    }

    for(int i = n-2;i>=0;i--){
        for(int j = i;j>=0;j--){
            int down = triangle[i][j] + dp[i+1][j];
            int diagonal = triangle[i][j] + dp[i+1][j+1];

            dp[i][j] = min(down,diagonal);
        }
    }
    return dp[0][0];
}

/*
    No - 4
    Fourth Approach - Tablution (Bottom-up) + Space Optimization
    Time Complexity - O(n*n) [n is no. of rows in triangle]
    Space Complexity - O(n) [ Only 1D vector carried to calculate current row from next row(bottom row) ]
*/

int minimumTotal_Tabulation_Space_Optimized(vector<vector<int>>& triangle){
    int n = triangle.size();
    vector<int> front(n,0);

    for(int j = 0;j<n;j++){
        front[j] = triangle[n-1][j];
    }

    for(int i = n-2;i>=0;i--){
        vector<int> curr(n,0);

        for(int j = i;j>=0;j--){
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j+1];

            curr[j] = min(down,diagonal);
        }
        front = curr;
    }
    return front[0];
}

int main(){
    
    vector<vector<int>> triangle{{2},{3,4},{6,5,7},{4,1,8,3}};
    
    /* For approach 1 & 2
        cout<<minimumTotal(triangle);
    */

    /* For approach 3
        cout<<minimumTotal_Tabulation(triangle);
    */

    /* For approach 4
        cout<<minimumTotal_Tabulation_Space_Optimized(triangle);
    */

    return 0;

}