class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
       vector<vector<int> > result;
       if(num.size() < 4) return result;
       sort(num.begin(), num.end());
       unordered_map<int, vector<pair<int, int> > > occur;
       int i = 0;
       while(i < num.size() - 1){
           int j = i + 1;
           while(j < num.size()){
               occur[num[i] + num[j]].push_back(pair<int, int>(i, j));
               ++j;
           }
           ++i;
       }
       i = 0;
       while(i < num.size() - 1){
           int j = i + 1;
           while(j < num.size()){
               int sum = target - num[i] - num[j];
               if(occur.find(sum) != occur.end()){
                   for(int k = 0; k < occur[sum].size(); ++k){
                        int x = occur[sum][k].first;
                        int y = occur[sum][k].second;
                        if(x <= j) continue;
                        result.push_back({num[i], num[j], num[x], num[y]});
                   }
                }
                ++j;
           }
           ++i;
       }
       sort(result.begin(), result.end());
       result.erase(unique(result.begin(), result.end()), result.end());
       return result;
    }
};
