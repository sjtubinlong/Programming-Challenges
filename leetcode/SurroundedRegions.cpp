class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = board.size();
        if( n <= 2 ) return;
        int m = board[0].size();
        unordered_set<int> visited;
        for( int i = 0; i < m; ++i ){
            if( board[0][i]=='O' && visited.find( i )==visited.end() ){
                visited.insert( i );
                dfs( board, n, 0, i, visited );
            }
            if( board[n-1][i]=='O' && visited.find( (n-1)*m + i )==visited.end() ){
                visited.insert( (n-1)*m + i );
                dfs( board, n, n-1, i, visited );
            }
        }
        for( int i = 0; i < n; ++i ){
            if( board[i][0]=='O' && visited.find( i*m )==visited.end() ){
                visited.insert( i*m );
                dfs( board, n, i, 0, visited );
            }
            if( board[i][m-1]=='O' && visited.find( i*m + m-1 )==visited.end() ){
                visited.insert( i*m + m-1 );
                dfs( board, n, i, m-1, visited );
            }
        }
        for( int i = 0; i < n; ++i ){
            for( int j = 0; j < m; ++j ){
                if( board[i][j]=='O' && visited.find(i*m+j)==visited.end() ) board[i][j] = 'X';
            }
        }
        for( unordered_set<int>::iterator it = visited.begin(); it != visited.end(); ++it ){
            board[ *it/n ][*it%n ] = 'O';
        }
    }
    void dfs( vector<vector<char>> &board, int &n,  int x, int y, unordered_set<int>& visited ){
        if( x<0 || y<0 || x>n-1 || y>n-1 ) {
            return;
        }
        if( board[x][y] == 'X' ) return;
        int step[4][2] = { {1, 0}, {-1, 0}, {0,1}, {0,-1} };
        for( int i = 0; i < 4; ++i ){
            if( x + step[i][0] < 0 || x+step[i][0] >= n ) continue;
            if( y + step[i][1] < 0 || y+step[i][1] >= n ) continue;
            int newX = x + step[i][0];
            int newY = y + step[i][1];
            if( board[newX][newY]=='X') continue;
            if( visited.find( newX*n+newY ) != visited.end() ) continue;
            visited.insert( newX*n+newY );
            dfs( board, n, newX, newY, visited );
        }
    }
};