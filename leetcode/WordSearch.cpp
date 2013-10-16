class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = board.size();
        if( n==0 ) return false;
        int m = board[0].size();
        if( m==0 ) return false;
        vector<int> vis(n*m, 0);
        for( int i = 0; i < n; ++i ){
            for( int j = 0; j < m; ++j ){
                vis[i*m+j] = 1;
                bool flag = dfs( board, i, j, word, 0, vis );
                vis[i*m+j] = 0;
                if( flag ) return true;
            }
        }
        return false;
    }
    bool dfs( vector< vector<char> > &board, int i, int j, string& word, int pos, vector<int>&vis ){
        if( board[i][j] != word[pos] ) return false;
        if( pos==word.size()-1 ){
            return true;    
        }
        int step[4][2] = { {1, 0}, {-1, 0}, {0,1}, {0,-1} };
        int n = board.size();
        int m = board[0].size();
        for( int k = 0; k < 4; ++k ){
            int x = i+step[k][0];
            int y = j+step[k][1];
            if( x < 0 || x >= n ) continue;
            if( y < 0 || y >= m ) continue;
            if( vis[ x*m+y ]==1 ) continue;
            vis[x*m+y] = 1;
            bool flag = dfs( board, x, y, word, pos+1, vis );
            vis[x*m+y] = 0;
            if( flag ) return true;
        }
        return false;
    }
};