// 74. Search a 2D Matrix

/*
	Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
	Output: true
*/

#include<bits/stdc++.h>
using namespace std;

	// Simple binary search on each row until we find the solution
	// Time Complexity - O(n*logm) or O(m*logn)
	// Space Complexity - O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0;i<m;i++){
            int low = 0,high = n-1;            
            while(low <= high){
                int mid = (low + high) / 2;
                
                if(matrix[i][mid] == target) return true;
                
                else if(matrix[i][mid] > target){
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
        }
        return false;
    }


int main(){

	vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};

	// True Case
	int t1 = 3;

	cout<<searchMatrix(matrix,t1)<<endl;

	// False Case
	int t2 = 69;

	cout<<searchMatrix(matrix,t2);

	return 0;
}