// 419. Battleships in a Board


/*
	Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
	Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

    void traverse(vector<vector<char>>& board,int i,int j){
        if(i < 0 || j < 0 || i > board.size()-1 || j > board[0].size()-1 || board[i][j] == '.') return;
        
        board[i][j] = '.';
        
        traverse(board,i+1,j);
        traverse(board,i,j+1);
            
    }
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int cnt = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j] == 'X'){
                    traverse(board,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }

int main(){

	vector<vector<char>> board = {{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}};

	cout<<countBattleships(board);

	return 0;
}