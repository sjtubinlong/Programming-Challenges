class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;
        if(num.size() < 3) return ans;
        sort(num.begin(), num.end());
        int i = 0;
        while(i < num.size() - 2){
            int j = i + 1;
            int k = num.size() - 1;
            while(j < k){
                if(num[j] + num[k] == 0 - num[i]){
                    ans.push_back({num[i], num[j], num[k]});
                    ++j;
                    --k;
                    while(j < k && num[j] == num[j - 1]) ++j;
                    while(k > j && num[k] == num[k + 1]) --k;
                }else if(num[j] + num[k] > 0 - num[i]){
                    --k;
                    while(k > j && num[k] == num[k + 1]) --k;
                }else{
                    ++j;
                    while(j < k && num[j] == num[j - 1]) ++j;
                }
            }
            ++i;
            while(i < num.size() - 2 && num[i] == num[i - 1]) ++i;
        }
        return ans;
    }
};