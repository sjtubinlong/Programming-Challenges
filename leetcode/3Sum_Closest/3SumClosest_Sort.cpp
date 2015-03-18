class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int ans = num[0] + num[1] + num[2];
        int diff = abs(target - ans);
        for(int i = 0; i < num.size() - 2; ++i){
            int j = i + 1;
            int k = num.size() - 1;
            while(j < k){
                int sum = num[i] + num[j] + num[k];
                int cur = abs(sum - target);
                if(cur < diff){
                    ans = sum;
                    diff = cur;
                }
                if(sum == target){
                    break;
                }else if(sum < target){
                    ++j;
                }else{
                    --k;
                }
            }
        }
        return ans;
    }
};