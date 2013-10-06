class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort( num.begin(), num.end() );
        int n = num.size();
        vector< vector<int> > result;
        vector<int> cur(4,0);
        set< vector<int> > q;
        for( int i = 0; i < n-3; ++i ){
            for( int j = i+1; j < n-2; ++j ){
                int k = j+1;
                int m = n-1;
                while( k < m ){
                    int sum = num[i]+num[j]+num[k]+num[m];
                    if( sum==target ){
                        cur[0] = num[i];
                        cur[1] = num[j];
                        cur[2] = num[k];
                        cur[3] = num[m];
                        if( q.find(cur) == q.end() ){
                            result.push_back(cur);
                            q.insert(cur);
                        }
                        ++k;
                    }
                    if( sum < target ){
                        ++k;
                    }
                    if( sum > target ){
                        --m;
                    }
                }
            }
        }
        return result;
    }
};