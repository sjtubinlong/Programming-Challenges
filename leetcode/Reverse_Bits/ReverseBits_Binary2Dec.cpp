class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> v;
        uint32_t ret = 0;
        while(n){
            v.push_back(n % 2);
            n = n / 2;
        }
        for(int i = v.size(); i < 32; ++i) v.push_back(0);
        uint32_t e = 1;
        for(int i = v.size() - 1; i >= 0; --i){
            ret += v[i] * e;
            e = e * 2;
        }
        return ret;
    }
};