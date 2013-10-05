class Solution {
public:
    int maxArea(vector<int> &height) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = height.size();
        int result = 0;
        int i = 0, j = n-1;
        while( i<j ){
            int area = 0;
            if( height[i] < height[j] ){
                area = height[i]*(j-i);
                ++i;
            }else{
                area = height[j]*(j-i);
                --j;
            }
            if( area > result ) result = area;
        }
        return result;
    }
};