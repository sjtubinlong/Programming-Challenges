/*
(i,i)----------(i,n-i-1)
  |                |
  |                |
  |                |
(n-i-1, i)-----(n-i-1, n-i-1)

(    i,j    )----------( j, n-i-1 )
      |                     | 
      |                     |
      |                     |
      |                     |
(  n-j-1, i )----------(n-i-1, n-j-1)


*/

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = matrix.size();
        for( int i = 0; i < n/2; ++i ){
            for( int j = i; j < n-1-i; ++j ){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = temp;
            } 
        }
    }
};