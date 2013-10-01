class Solution {
public:
    static int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = triangle.size();
        if(n==1) return triangle[0][0];
        vector< int > dp( n,0 );
        dp[0] = triangle[0][0];
        int pre = dp[0];
        int min = 0;
        for( int i = 1; i != n; ++i ){
            for( int j = 0; j != triangle[i].size(); ++j ){
                if( j == 0 ){
                    pre = dp[j];
                    dp[j] = dp[j] + triangle[i][j];
                }else if( j == triangle[i].size()-1 ){
                    int tmp = dp[j];
                    dp[j] = pre + triangle[i][j];
                    pre = tmp;
                }else if( pre+triangle[i][j] < dp[j]+triangle[i][j] ){
                    int tmp = dp[j];
                    dp[j] = pre+triangle[i][j];
                    pre = tmp; 
                }else{
                    int tmp = dp[j];
                    dp[j] = dp[j]+triangle[i][j];
                    pre = tmp; 
                }
                if( i==n-1 ){
                    if( j==0 ) min = dp[0];
                    if( dp[j] < min ){
                        min = dp[j];
                    }
                }
            }
        }
        return min;
    }
};