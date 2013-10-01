class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if( m==0 || n==0 || obstacleGrid[0][0] ) return 0;
        vector< vector<int> > dp( m, vector<int>(n, 0) );
        dp[0][0] = 1;
        for( int i = 1; i != n; ++i ){
            dp[0][i] = (obstacleGrid[0][i]>0||!dp[0][i-1])?0:1;
        }
        for( int i = 1; i != m; ++i ){
            dp[i][0] = (obstacleGrid[i][0]>0||!dp[i-1][0])?0:1;
        }
        for( int i = 1; i != m; ++i ){
            for( int j = 1; j != n; ++j ){
                if( obstacleGrid[i][j] || (obstacleGrid[i-1][j]&&obstacleGrid[i][j-1]) ){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];   
                }
            }
        }
        return dp[m-1][n-1];
    }
};