class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector< vector<int> > result;
        vector<int> ans;
        dfs( result, ans, n, k, 1);
        return result;
    }
    void dfs( vector< vector<int> > &result, vector<int>&ans ,int n,  int k, int choose ){
        if( ans.size() >= k ){
            result.push_back(ans);
            return;
        }
        for( int i = choose; i <= n; ++i ){
            if( ans.size()==0 || i > ans[ ans.size()-1 ] ){
                ans.push_back(i);
                dfs( result, ans, n, k, choose+1 );
                ans.pop_back();
            }
        }
    }
};