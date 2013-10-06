class Solution {
public:
    static vector<vector<int> > threeSum(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector< vector<int> > result;
        vector<int> cur( 3, 0 );
        int n = num.size();
        sort( num.begin(), num.end() );
        set< vector<int> > q;
        for( int i = 0; i < n-2; ++i ){
            int j = i+1;
            int k = n-1;
            while( j < k ){
               if( num[i] + num[j] + num[k]==0 ){
                    cur[0] = num[i];
                    cur[1] = num[j];
                    cur[2] = num[k];
                    if( q.find(cur) == q.end() ){
                        result.push_back(cur);
                        q.insert(cur);
                    }
                    ++j;
                }else if( num[i] + num[j] + num[k]<0 ){
                    ++j;
                }else{
                    --k;
                }
            }
        }
        return result;
    }
};
