
class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int, int>& b){
        return a.first < b.first;
    }
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        vector< pair<int, int> > data;
        for(int i = 0; i < numbers.size(); ++i){
            data.push_back(pair<int, int>(numbers[i], i+1));
        }
        sort(data.begin(), data.end(), Solution::cmp);
        int i = 0, j = data.size() - 1;
        while(i < j){
            if(data[i].first + data[j].first == target){
                if(data[i].second > data[j].second){
                    result.push_back(data[j].second);
                    result.push_back(data[i].second);
                }else{
                    result.push_back(data[i].second);
                    result.push_back(data[j].second);
                }
                break;
            }else if(data[i].first + data[j].first > target){
                --j;
            }else{
                ++i;
            }
        }
        return result;
    }
};