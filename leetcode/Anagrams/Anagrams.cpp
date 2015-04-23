class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        unordered_map< string, vector<int> > hash;
        for(int i = 0; i < strs.size(); ++i){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            hash[tmp].push_back(i);
        }
        vector<string> ret;
        for(auto it = hash.begin(); it != hash.end(); ++it){
            if(it->second.size() <= 1) continue;
            for(int i = 0; i < it->second.size(); ++i){
                ret.push_back(strs[it->second[i]]);
            }
        }
        return ret;
    }
};
