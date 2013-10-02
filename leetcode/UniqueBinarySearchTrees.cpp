class Solution {
public:
    int numTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ret = 1;
        for( int i = 1; i <= n; ++i ){
            ret  = ret*2*(2*(i-1)+1)/(i-1+2);
        }
        return ret;
    }
};