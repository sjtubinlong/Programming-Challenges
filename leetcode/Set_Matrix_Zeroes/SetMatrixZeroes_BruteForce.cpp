class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if(n < 1) return;
        int m = matrix[0].size();
        vector<vector<bool> > flag(n, vector<bool>(m, false));
        for(int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (matrix[i][j] == 0){
                    flag[i][j] = true;
                }
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(matrix[i][j] == 0 && flag[i][j]){
                    for(int k = 0; k < m; ++k){
                        matrix[i][k] = 0;
                    }
                    for(int k = 0; k < n; ++k){
                        matrix[k][j] = 0;
                    }
                }
            }
        }
    }
};