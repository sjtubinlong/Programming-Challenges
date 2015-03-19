class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ans;
        if(num.size() < 4) return ans;
        sort(num.begin(), num.end());
        int i = 0;
        while(i < num.size() - 3){
            int j = i + 1;
            while(j < num.size() - 2){
                int p = j + 1;
                int q = num.size() - 1;
                while(p < q){
                    int sum = num[i] + num[j] + num[p] + num[q];
                    if(sum == target){
                        ans.push_back({num[i], num[j], num[p], num[q]});
                        ++p;
                        --q;
                        while(p < q && num[p] == num[p - 1]) ++p;
                        while(p < q && num[q] == num[q + 1]) --q;
                    }else if(sum < target){
                        ++p;
                        while(p < q && num[p] == num[p - 1]) ++p;
                    }else{
                        --q;
                        while(p < q && num[q] == num[q + 1]) --q;
                    }
                }
                ++j;
                while(j < num.size() - 2 && num[j] == num[j - 1]) ++j;
            }
            ++i;
            while(i < num.size() - 3 && num[i] == num[i - 1]) ++i;
        }
        return ans;
    }
};