// 695. Max Area of Island

/*
    Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
    Output: 6
    Explanation: The answer is not 11, because the island must be connected 4-directionally.

    Input: grid = [[0,0,0,0,0,0,0,0]]
    Output: 0
*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& grid, int i, int j){
    if(i > grid.size() -1 || j > grid[0].size() - 1 || i < 0 || j < 0 || grid[i][j] == 0) return 0;
    grid[i][j] = 0;
    
    int left = solve(grid, i, j - 1);
    int right = solve(grid, i, j + 1);
    int up = solve(grid, i - 1, j);
    int down = solve(grid, i + 1, j);
    
    return 1 + left + right + up + down;

}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxi = 0;
    for(int i = 0;i<grid.size();i++){
        for(int j = 0;j<grid[0].size();j++){
            if(grid[i][j] == 1) {
                maxi = max(maxi, solve(grid, i, j));
            }
        }
    }
    return maxi;
}

int main(){

    vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
        };

    cout<<maxAreaOfIsland(grid);

    return 0;
}