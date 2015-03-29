class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector< vector<int> > result;
        if( numRows<=0 ) return result;
        vector<int> cur;
        cur.push_back(1);
        result.push_back(cur);
        for( int i = 2; i <= numRows; ++i ){
            vector<int> pre = cur;
            cur.clear();
            cur.push_back(1);
            for( int j = 1; j < i-1; ++j ){
                cur.push_back( pre[j-1]+pre[j] );
            }
            cur.push_back(1);
            result.push_back(cur);
        }
        return result;
    }
};
