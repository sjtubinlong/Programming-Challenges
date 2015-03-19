// O(1) Space complexity, use the first zero as pivot to record if a col or row need to be set zero
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if(n < 1) return;
        int m = matrix[0].size();
        int x = -1, y = -1;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(matrix[i][j] == 0){
                    if(x == -1 && y == -1){
                        x = i;
                        y = j;
                    }else{
                        matrix[x][j] = 0;
                        matrix[i][y] = 0;
                    }
                }
            }
        }
        if(x == -1 && y == -1) return;
        for(int i = 0; i < n; ++i){
            if(i == x) continue;
            for(int j = 0; j < m; ++j){
                if(j == y) continue;
                if(matrix[x][j] == 0 || matrix[i][y] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < n; ++i) matrix[i][y] = 0;
        for(int j = 0; j < m; ++j) matrix[x][j] = 0;
    }
};