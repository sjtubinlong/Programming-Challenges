class Solution {
public:
    double pow(double x, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if( n==1 ) return x;
        if( x <= 0.00000001 && x >= -0.00000001 ) return x;
        if( x <= 1.0+0.00000001 && x >= 1.0-0.00000001 ) return x;
        if( x <= -1.0+0.00000001 && x >= -1.0-0.00000001 ){
            return n%2?x:1;    
        }
        bool negtive = false;
        if( n < 0){
            n = 0 - n;
            negtive = true;
        }
        double result = 1;
        double m = x;
        while( n ){
            if( n&1 ){
                result *= m;
            }
            m *= m;
            n >>= 1;
        }
        return !negtive?result:1/result;
    }
};