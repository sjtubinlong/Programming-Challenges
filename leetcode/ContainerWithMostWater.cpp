class Solution {
public:
    int maxArea(vector<int> &height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = height.size();
        int result = 0;
        for( int i = 0; i < n; ++i ){
            if( height[i]==0 ) continue;
            for( int j = n-1; j >= i+1; --j ){
                if( j < i+result/height[i] ) break;
                int area = min( height[i], height[j] )*(j-i);
                if( area > result ){
                    result = area;
                }
            }
        }
        return result;
    }
};