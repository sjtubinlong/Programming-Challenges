class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector< vector<int> > result;
        vector<int> cur;
        result.push_back(cur);
        if( S.empty() ) return result;
        unordered_set<int> hash;
        dfs( S, hash, result, cur, 0 );
        return result;
    }
    void dfs( vector<int>& S, unordered_set<int>&hash, vector< vector<int> >&result, vector<int>&cur, int k ){
        if( k > S.size() ) return;
        if( k > 0 ) result.push_back(cur);
        int n = S.size();
        for( int i = 0; i < n; ++i ){
            if( (k==0||S[i] >= cur[k-1]) && hash.find(S[i]) == hash.end() ){
                hash.insert( S[i] );
                cur.push_back(S[i]);
                dfs(S, hash, result, cur, k+1);
                cur.pop_back();
                hash.erase( S[i] );
            }
        }
    }
};