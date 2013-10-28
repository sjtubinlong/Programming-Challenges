class Solution {
public:
    string getPermutation(int n, int k) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int fact[10] = {1, 1, 2, 6,24,120,720,5040, 5040*8, 5040*8*9 };
        vector<bool> hash(10, false);
        string result;
        --k;
        for(int i = n; i >= 1; --i){
            int num = k/fact[i-1];
            k = k%fact[i-1];
            ++num;
            for( int j = 1; j <= n; ++j ){
                if( !hash[j] ) --num;
                if( num==0 ){
                    result += j+'0';
                    hash[j] = true;
                    break;
                }
            }
        }
        return result;
    }
};