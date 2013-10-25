class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > result;
        vector<int> ans( num.size(), 0 );
        vector<int> visited( num.size(), 0 );
        sort( num.begin(), num.end() );
        dfs( result, ans, num, visited, 0 );
        return result;
    }
    void dfs( vector<vector<int> > &result, vector<int>&ans, vector<int>&num, vector<int>& visited, int k ){
        if( k >= num.size() ){
            result.push_back(ans);
            return;
        }
        for( int i = 0; i < num.size(); ++i ){
            if( visited[i] ) continue;
            if( i >= 0 && num[i]==num[i-1] && visited[i-1] ) continue;
            ans[k] = num[i];
            visited[i] = 1;
            dfs( result, ans, num, visited, k+1 );
            visited[i] = 0;
        }
    }
};