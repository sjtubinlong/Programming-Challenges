class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        unordered_set<char> visited;
        for( int i = 0; i < 9; ++i ){
            visited.clear();
            for( int j = 0; j < 9; ++j ){
                if( board[i][j] <'0' || board[i][j] > '9') continue;
                if( visited.find(board[i][j]) != visited.end() ) return false;
                visited.insert( board[i][j] );
            }
            visited.clear();
            for( int j = 0; j < 9; ++j ){
                if( board[j][i] <'0' || board[j][i] > '9') continue;
                if( visited.find(board[j][i]) != visited.end() ) return false;
                visited.insert( board[j][i] );
            }
        }
        for( int i = 0; i < 3; ++i ){
            for( int j = 0; j < 3; ++j ){
                visited.clear();
                for( int p = 0; p < 3; ++p ){
                    for( int q = 0; q < 3; ++q ){
                        int x = 3*i+p;
                        int y = 3*j+q;
                        if( board[x][y] <'0' || board[x][y] > '9') continue;
                        if( visited.find(board[x][y]) != visited.end() ) return false;
                        visited.insert( board[x][y] );
                    }
                }
            }
        }
        return true;
    }
};