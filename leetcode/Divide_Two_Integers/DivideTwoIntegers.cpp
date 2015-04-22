class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        if(dividend == 0) return 0;
        if(divisor == 1) return dividend;
        if(divisor == -1) return -dividend;
        if(divisor == dividend) return 1;
        if(divisor == INT_MIN) return 0;
        
        int sig = (dividend >= 0) ^ (divisor >= 0);
        
        long divisor_l = divisor;
        long dividend_l = dividend;
        if(divisor_l < 0) divisor_l = -divisor_l;
        if(dividend_l < 0) dividend_l = -dividend_l;
        
        int ans = 0;
        while(divisor_l <= dividend_l){
            int p = 1;
            long t_divisor = divisor_l;
            while(dividend_l>>1 >= t_divisor){
                p <<= 1;
                t_divisor <<= 1;
            }
            ans += p;
            dividend_l -= t_divisor;
        }
        return sig == 0 ? ans : -ans;
    }
};
