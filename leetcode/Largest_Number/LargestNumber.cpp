class Solution {
public:
    static bool cmp(const string& a, const string& b){
        return a + b > b + a;
    }
    
    static string toString(int num){
        string ret;
        while(num){
            ret += num % 10 + '0';
            num /= 10;
        }
        int i = 0, j = ret.size() - 1;
        while(i < j){
            ret[i] = ret[i] + ret[j];
            ret[j] = ret[i] - ret[j];
            ret[i] = ret[i] - ret[j];
            ++i;
            --j;
        }
        return ret.size() ? ret : "0";
    }
    
    string largestNumber(vector<int> &num) {
        string ans;
        vector<string> snum;
        for(int i = 0; i < num.size(); ++i){
            snum.push_back(toString(num[i]));
        }
        sort(snum.begin(), snum.end(), Solution::cmp);
        bool zero = true;
        for(int i = 0; i < snum.size(); ++i){
            ans += snum[i];
            if(snum[i] != "0") zero = false;
        }
        return zero ? "0" : ans;
    }
};
