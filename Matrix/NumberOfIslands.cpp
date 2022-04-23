// 200. Number of Islands

/*
	Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
  ]
	Output: 1
*/

#include<bits/stdc++.h>
using namespace std;

	// Approach - 1
	// Time Complexity - O(m*n) 
	// Space Complexity - O(m*n)
	// Using visited matrix
    void countIsland(vector<vector<char>>& grid,vector<vector<int>>& visited,int i,int j,int m,int n){
        if(i < 0 || j < 0 || i > m - 1 || j > n - 1 || visited[i][j] == 1 || grid[i][j] == '0') return;
        
        visited[i][j] = 1;
        
        countIsland(grid,visited,i+1,j,m,n);
        countIsland(grid,visited,i,j+1,m,n);
        countIsland(grid,visited,i-1,j,m,n);
        countIsland(grid,visited,i,j-1,m,n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,-1));
        int cnt = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(visited[i][j] == -1 && grid[i][j] == '1'){
                    countIsland(grid,visited,i,j,m,n);
                    cnt++;
                }
            }
        }
        return cnt;
    }

// Approach - 2
// Time Complexity - O(m*n) 
// Space Complexity - O(1)
// Without using extra visited array and making visited values as '0' in original matrix itself

void countIsland2(vector<vector<char>>& grid,int i,int j,int m,int n){
        if(i < 0 || j < 0 || i > m - 1 || j > n - 1  || grid[i][j] == '0') return;
        
        grid[i][j] = '0';
        
        countIsland2(grid,i+1,j,m,n);
        countIsland2(grid,i,j+1,m,n);
        countIsland2(grid,i-1,j,m,n);
        countIsland2(grid,i,j-1,m,n);
    }
    int numIslands2(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '1'){
                    countIsland2(grid,i,j,m,n);
                    cnt++;
                }
            }
        }
        return cnt;
    }


int main(){
	vector<vector<char>> grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
	cout<<numIslands(grid)<<endl;

	cout<<numIslands2(grid)<<endl;
	return 0;
}    