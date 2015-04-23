class Solution {
public:
    bool detect(const string& s, int i, int j, string &val, int &num){
        if(s[i] == '0' && j > i) return false;
        int ret = 0;
        int k = i;
        while(k <= j){
            val += s[k];
            ret = ret * 10 + s[k] - '0';
            ++k;
        }
        num = ret;
        return ret >= 0 && ret <= 255;
    }
    
    void solve(const string& src, int i, int dot, vector<string>& ans, string ip){
        if(i >= src.size() || dot >= 4){
            if(dot >= 4){
                if(ip.size() - 3 == src.size()){
                    ans.push_back(ip);
                }
            }
            return;
        }
        vector<int> visit(256, 0);
        
        for(int j = 0; j < 3; ++j){
            if(i + j >= src.size()) break;
            string tip = ip;
            string val;
            int num;
            if(detect(src, i, i + j, val, num) && !visit[num]){
                tip += val;
                if(dot < 3) tip += "."; 
                visit[num] = 1;
            }   
            solve(src, i+j+1, dot+1, ans, tip);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if(s.size() < 4 || s.size() > 12) return ans;
        solve(s, 0, 0, ans, string());
        return ans;
    }
};

