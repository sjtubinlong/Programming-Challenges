class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> row(10, 0);
        vector<int> col(10, 0);
        vector<int> block(10, 0);
        for( int i = 0; i < 9; ++i ){
            for( int j = 0; j < 9; ++j ){
                if( board[i][j] != '.' ) {
                    int c = board[i][j]-'0';
                    row[i] |= (1<<c);
                    col[j] |= (1<<c);
                    block[i/3*3+j/3] |= (1<<c);
                }
            }
        }
        dfs( board, row, col, block, 0 );
    }
    bool dfs( vector<vector<char> > &board, vector<int>&row, vector<int>&col, vector<int>&block, int k ){
        while( k < 81 && board[k/9][k%9] != '.' ) ++k;
        if( k >= 81 ) return true;
        int x = k/9, y = k%9;
        for( int i = 1; i <= 9; ++i ){
            if( row[x]&(1<<i) || col[y]&(1<<i) || block[x/3*3+y/3]&(1<<i) ) continue;
            board[x][y] = i + '0';
            row[x] |= (1<<i);
            col[y] |= (1<<i);
            block[x/3*3+y/3] |= (1<<i);
            bool ret = dfs( board, row, col, block, k+1 );
            if( ret ) return true;
            row[x] ^= (1<<i);
            col[y] ^= (1<<i);
            block[x/3*3+y/3] ^= (1<<i);
        }
        board[x][y] = '.';
        return false;
    }
};