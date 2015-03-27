class Solution {
public:
    int solve(int arr[], int low, int high){
        if(low == high){
            return arr[low];
        }
        
        int mid = (high + low) / 2;
        
        int sum = 0;
        int left_sum = INT_MIN;
        for(int i = mid; i >= low; --i){
            sum += arr[i];
            if(sum > left_sum) left_sum = sum;
        }
        
        sum = 0;
        int right_sum = INT_MIN;
        for(int i = mid + 1; i <= high; ++i){
            sum += arr[i];
            if(sum > right_sum) right_sum = sum;
        }

        int ans = max(left_sum, right_sum);
        ans = max(ans, left_sum + right_sum);

        int left_ans = solve(arr, low, mid);
        int right_ans = solve(arr, mid+1, high);
        ans = max(ans, max(left_ans, right_ans));
        return ans;
    }
    int maxSubArray(int A[], int n) {
        int ans = solve(A, 0, n - 1);
        return ans;
    }
};
