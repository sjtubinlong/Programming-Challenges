class Solution {
public:
    void reverse(int nums[], int low, int high){
        int i = low, j = high;
        while(i < j){
            nums[i] = nums[i] + nums[j];
            nums[j] = nums[i] - nums[j];
            nums[i] = nums[i] - nums[j];
            ++i;
            --j;
        }
    }
    
    void rotate(int nums[], int n, int k) {
        if(n == 1 || k == 0) return;
        k = k % n;
        if(k == 0) return;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
};
