class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> cur_ans;
        vector< vector<int> > result;
        set< vector<int> > visited;
        sort( num.begin(), num.end() );
        dfs( target, 0, visited,cur_ans, result, num );
        return result;
    }
    void dfs( int target,  int choose, set< vector<int> > &visited, vector<int>& cur_ans, vector< vector<int> >&result, vector<int> &num ){
        if( target==0 ){
            if( visited.find(cur_ans)!=visited.end() ) return;
            visited.insert(cur_ans);
            result.push_back(cur_ans);
            return;
        }
        if( target < 0 ){
            return;
        }
        for( int i = choose; i < num.size(); ++i ){
            if( target-num[i] >= 0 ){
                cur_ans.push_back(num[i]);
                dfs( target-num[i], i+1, visited, cur_ans, result, num );
                cur_ans.pop_back();
            }
        }
    }
};