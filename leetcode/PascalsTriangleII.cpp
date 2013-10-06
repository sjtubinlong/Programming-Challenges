class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> ret;
        ret.push_back(1);
        for( int i = 1; i <= rowIndex; ++i ){
            vector<int> pre = ret;
            ret.clear();
            ret.push_back(1);
            for( int j = 1; j < i; ++j ){
                ret.push_back( pre[j-1]+pre[j] );
            }
            ret.push_back(1);
        }
        return ret;
    }
};