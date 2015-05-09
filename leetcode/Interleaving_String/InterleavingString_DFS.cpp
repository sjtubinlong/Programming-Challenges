class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();
        if(l1 == 0) return s2 == s3;
        if(l2 == 0) return s1 == s3;
        if(l1 + l2 != l3) return false;
        vector< vector<bool> > ans(l1+1, vector<bool>(l2+1, false));
        ans[0][0] = true;
        for(int i = 1; i <= l1; ++i){
            ans[i][0] = ans[i-1][0] && (s1[i-1] == s3[i-1]);
        }
        for(int i = 1; i <= l2; ++i){
            ans[0][i] = ans[0][i-1] && (s2[i-1] == s3[i-1]);
        }
        for(int i = 1; i <= l1; ++i){
            for(int j = 1; j <= l2; ++j){
                ans[i][j] = ans[i-1][j] && (s1[i-1] == s3[i+j-1]);
                ans[i][j] =  ans[i][j] || (ans[i][j-1] && (s2[j-1] == s3[i+j-1]));
            }
        }
        return ans[l1][l2];
    }
};

