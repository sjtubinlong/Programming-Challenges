class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = matrix.size();
        if( n==1 ) return matrix[0];
        vector<int> result;
        if( n==0 ) return result;
        int m = matrix[0].size();
        if( m==0 ) return result;
        if( m==1 ){
            for( int i = 0; i < n; ++i )
                result.push_back( matrix[i][0]);
            return result;
        }
        int circleNum = ( min(n, m)+1 )/2;
        for( int i = 0; i < circleNum; ++i ){
            if( result.size()==n*m-1 ){
                result.push_back( matrix[i][i] );
                break;
            }
            //right
            for( int j = i; j < m-i-1; ++j ){
                result.push_back( matrix[i][j] );
            }
            //down
            for( int j = i; j < n-i-1; ++j ){
                result.push_back( matrix[j][m-i-1] );
            }
            //left
            for( int j = m-i-1; j > i; --j ){
                result.push_back( matrix[n-i-1][j] );
            }
            //up
            for( int j = n-i-1; j > i; --j ){
                result.push_back( matrix[j][i] );
            }
        }
        return result;
    }
};