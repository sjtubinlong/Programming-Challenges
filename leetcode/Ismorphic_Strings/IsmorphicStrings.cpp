class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        int n = s.size();
        int flag = 1;
        vector<int> h1(256, 0), h2(256, 0);
        for(int i = 0; i < n; ++i){
            char c1 = s[i], c2 = t[i];
            if(h1[c1] != h2[c2]) return false;
            if(h1[c1] == 0){
                h1[c1] = flag;
                h2[c2] = flag;
                ++flag;
            }
        }
        return true;
    }
};
