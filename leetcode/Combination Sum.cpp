class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> cur_ans;
        vector< vector<int> > result;
        sort( candidates.begin(), candidates.end() );
        dfs( target, 0, cur_ans, result, candidates );
        return result;
    }
    
    void dfs( int cur, int choose, vector<int>&cur_ans, vector< vector<int> >& result, vector<int> &candidates){
        if( cur==0 ) {
            result.push_back( cur_ans );
            return;
        }
        if( cur < 0 ) return;
        if( cur - candidates[choose] >= 0 ) {
            cur_ans.push_back( candidates[choose] );
            dfs( cur - candidates[choose], choose, cur_ans, result, candidates );
            cur_ans.pop_back();
        }
        for( int i = choose+1; i < candidates.size(); ++i ){
            cur_ans.push_back( candidates[i] );
            dfs( cur-candidates[i], i, cur_ans, result, candidates );
            cur_ans.pop_back();
        }
    }
};