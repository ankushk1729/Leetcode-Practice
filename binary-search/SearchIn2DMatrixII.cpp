// 240. Search a 2D Matrix II


/*
	Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
	Output: true

	Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
	Output: false
*/

#include <bits/stdc++.h>
using namespace std;

    // We start from top right corner and element a row or a column one by one
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, col = matrix[0].size()-1;
        
        while(col >= 0 && row <= matrix.size()-1){
            if(matrix[row][col] == target) return true;
            
            // target > current cell means it will not exist in that entire row
            // so we can move to next row
            else if(matrix[row][col] < target) row++;
            
            // target < current cell means it will not exist in that entire col
            // as everything below in that column would be greater than current cell
            // so we can move to prev col
            else col--;
        }
        return false;
    }


int main(){

	vector<vector<int>> matrix =  {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

	int target = 5;

	// Returns true if target exists in matrix otherwise false.
	cout<<searchMatrix(matrix,target);

	return 0;
}