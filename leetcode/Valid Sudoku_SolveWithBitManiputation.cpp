class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> row( 10, 0 );
        vector<int> col( 10, 0 );
        vector<int> block( 10, 0 );
        for( int i = 0; i < 9; ++i ){
            for( int j = 0; j < 9; ++j ){
                if( board[i][j] <'0' || board[i][j] > '9') continue;
                int cur = board[i][j]-'0';
                if( row[cur]&(1<<i) || col[cur]&(1<<j) || block[cur]&(1<<(i/3*3+j/3)) ) return false;
                row[cur] |= (1<<i);
                col[cur] |= (1<<j);
                block[cur] |= ( 1<<(i/3*3+j/3) );
            }
        }
        return true;
    }
};