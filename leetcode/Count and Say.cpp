class Solution {
public:
    string countAndSay(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        string pre("1");
        string cur("1");
        for( int i = 1; i < n; ++i ){
            pre = cur;
            cur.clear();
            int len = pre.size();
            int num = 0;
            int j = 0;
            while( j < len ){
                do{
                    ++num;
                    ++j;
                }while( pre[j]==pre[j-1] );
                cur += num + '0';
                cur += pre[j-1];
                num = 0;
            }
        }
        return cur;
    }
};