#include <bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp,int i,int j){
    if(i < 0 || j < 0 || i > obstacleGrid.size()-1 || j > obstacleGrid[0].size()-1 || obstacleGrid[i][j] == 1) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    if(i == obstacleGrid.size()-1 && j == obstacleGrid[0].size()-1) return 1;
    
    int down = solve(obstacleGrid,dp,i+1,j);
    int right = solve(obstacleGrid,dp,i,j+1);
    
    return dp[i][j] = down + right;
    
}

// TC - O(m*n)
// SC - O(m*n)
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
    
    int ans = solve(obstacleGrid,dp,0,0);

    return ans;
}

int main(){

    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};

    cout<<uniquePathsWithObstacles(obstacleGrid);

    return 0;
}