//integer ends with 0
//may cause overflow
class Solution {
public:
    int reverse(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( x==0 ) return x;
        int flag = x>0?1:-1;
        x *= flag;
        int result = 0;
        while( x>0 ){
            result = result*10 + x%10;
            x = x/10;
        }
        return result*flag;
    }
};