class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if( n==0 ) return vector< vector<int> >();
        vector< vector<int> > matrix( n, vector<int>(n, -1) );
        int x = 0, y = 0;
        int cur = 1;
        matrix[0][0] = 1;
        while( cur < n*n ){
            //right
            while( y+1 < n && matrix[x][y+1] == -1 ){
                matrix[ x ][ ++y ] = ++cur;
            }
            //down
            while( x+1 < n && matrix[x+1][y] == -1 ){
                matrix[++x][y] = ++cur;
            }
            //left
            while( y-1 >= 0 && matrix[x][y-1] == -1 ){
                matrix[x][--y] = ++cur;
            }
            //up
            while(x-1 >= 0 && matrix[x-1][y] == -1 ){
                matrix[--x][y] = ++cur;
            }
        }
        return matrix;
    }
};