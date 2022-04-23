// 1219. Path with Maximum Gold

/*
	Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
	Output: 24
	Explanation:
	[[0,6,0],
	 [5,8,7],
	 [0,9,0]]
	Path to get the maximum gold, 9 -> 8 -> 7.
*/

#include<bits/stdc++.h>
using namespace std;



    int getMaxPath(vector<vector<int>>& grid,vector<vector<int>>& visited,int i,int j,int m,int n){
        if(i > m - 1 || j > n - 1 || i < 0 || j < 0 || visited[i][j] == 1 || grid[i][j] == 0) return 0;
        
        visited[i][j] = 1;
        int down = getMaxPath(grid,visited,i+1,j,m,n);
        int up = getMaxPath(grid,visited,i-1,j,m,n);
        int left = getMaxPath(grid,visited,i,j-1,m,n);
        int right = getMaxPath(grid,visited,i,j+1,m,n);

        int ans = grid[i][j] + max({left,right,down,up});
        
        visited[i][j] = -1;
        
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,-1));
        int maxi = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(visited[i][j] == -1 && grid[i][j] != 0){
                    maxi = max(maxi,getMaxPath(grid,visited,i,j,m,n));
                }
            }
        }
        return maxi;
    }

int main(){

	vector<vector<int>> grid = {{0,6,0},{5,8,7},{0,9,0}};

	cout<<getMaximumGold(grid);

	return 0;
}