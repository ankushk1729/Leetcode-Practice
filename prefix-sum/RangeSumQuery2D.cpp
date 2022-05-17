// 304. Range Sum Query 2D - Immutable


/*
    Input
    ["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
    [[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
    
    Output
    [null, 8, 11, 12]

    Explanation
    NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
    numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
    numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
    numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)
*/

#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
public:
    // Every cell in prefix sum grid contains sum of all cells from (0,0) to that cell
    vector<vector<int>> prefixSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        prefixSum.resize(m,vector<int>(n,0));
        
        int left,up,diag;
        
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                
                // Edges cases for 0th row and 0th column
                left = (j == 0) ? 0 : prefixSum[i][j-1];
                up = (i == 0) ? 0 : prefixSum[i-1][j];
                diag = (i == 0 || j == 0 ) ? 0 : prefixSum[i-1][j-1];
                
                // the diag region is common in left region and up region
                // that is why it is subtracted to avoid duplication
                prefixSum[i][j] = matrix[i][j] + left + up - diag;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int left,up,diag;
        
        // Edges cases for 0th row and 0th column
        left = (col1 == 0) ? 0 : prefixSum[row2][col1-1];
        up = (row1 == 0) ? 0 : prefixSum[row1-1][col2];
        diag = (row1 == 0 || col1 == 0 ) ? 0 : prefixSum[row1-1][col1-1];
        
        int ans = prefixSum[row2][col2] - left - up + diag;
        
        return ans;
    }
};

int main(){

    int m,n;
    cin>>m>>n;

    vector<vector<int>> matrix(m,vector<int>(n));

    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            cin>>matrix[i][j];
        }
    }

    NumMatrix* obj = new NumMatrix(matrix);

    int q;
    cin>>q;

    while(q--){
        int row1,col1,row2,col2;
        cin>>row1>>col1>>row2>>col2;
        cout<<obj->sumRegion(row1,col1,row2,col2)<<endl;
    }
  
  return 0;  
}
  
