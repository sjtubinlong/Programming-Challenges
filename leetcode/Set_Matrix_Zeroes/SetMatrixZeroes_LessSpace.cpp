// use O(m + n) space to record the zero positions
// if zero number is bigger than m+n, the matrix should be set to a pure zero matrix
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if(n < 1) return;
        int m = matrix[0].size();
        vector<int> zeroes(m + n, -1);
        int count = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(matrix[i][j] == 0){
                    if(count >= m + n) break;
                    rec[count++] = i * m + j;
                }
            }
        }
        for(int i = 0; i < count; ++i){
            int x = rec[i] / m;
            int y = rec[i] % m;
            for(int j = 0; j < m; ++j){
                matrix[x][j] = 0;
            }
            for(int j = 0; j < n; ++j){
                matrix[j][y] = 0;
            }
        }
    }
};