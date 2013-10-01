class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = triangle.size();
        if(n==1) return triangle[0][0];
        vector< vector<int> > dp( n, vector<int>(n,0) );
        dp[0][0] = triangle[0][0];
        int min = 0;
        for( int i = 1; i != n; ++i ){
            for( int j = 0; j != triangle[i].size(); ++j ){
                if( j == 0 ){
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }else if( j == triangle[i].size()-1 ){
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }else if( dp[i-1][j]+triangle[i][j] < dp[i-1][j-1]+triangle[i][j] ){
                    dp[i][j] = dp[i-1][j]+triangle[i][j]; 
                }else{
                    dp[i][j] = dp[i-1][j-1]+triangle[i][j]; 
                }
                if( i==n-1 ){
                    if( j==0 ) min = dp[i][j];
                    if( dp[i][j] < min ){
                        min = dp[i][j];
                    }
                }
            }
        }
        return min;
    }
};