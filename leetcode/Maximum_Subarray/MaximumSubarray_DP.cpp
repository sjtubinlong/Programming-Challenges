// 最大字段和
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int ans = INT_MIN;
        int cur = 0;
        for(int i = 0; i < n; ++i){
            cur = max(A[i], A[i] + cur);
            if(cur > ans) ans = cur;
        }
        return ans;
    }
};
