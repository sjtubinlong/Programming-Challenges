class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = grid.size();
        int n = grid[0].size();
        vector< vector<int> > dp( m, vector<int>(n,0) );
        //初始化第一行，第一列
        dp[0][0] = grid[0][0];
        for( int i = 1; i != n; ++i ){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        for( int i = 1; i != m; ++i ){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        //利用缓存值，滚动计算出所有值
        for( int i = 1; i != m; ++i ){
            for( int j = 1; j != n; ++j ){
                if( dp[i-1][j]+grid[i][j] < dp[i][j-1]+grid[i][j] ){
                    dp[i][j] = dp[i-1][j]+grid[i][j];
                }else{
                    dp[i][j] = dp[i][j-1]+grid[i][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
};