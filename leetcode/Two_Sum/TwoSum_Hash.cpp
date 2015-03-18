class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> occur;
        vector<int> result;
        for(int i = 0; i < numbers.size(); ++i){
            if(occur.find(target - numbers[i]) != occur.end()){
                result.push_back(occur[target - numbers[i]] + 1);
                result.push_back(i + 1);
                break;
            }
            occur[numbers[i]] = i;
        }
        return result;
    }
};