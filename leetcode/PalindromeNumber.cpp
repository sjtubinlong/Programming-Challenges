class Solution {
public:
    bool isPalindrome(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( x <0 ) return false;
        int exp = 1;
        while( x/exp >= 10 ){
            exp *= 10;
        }
        while( x!=0 ){
            int left = x/exp;
            int right = x%10;
            if( left != right ) return false;
            x = ( x % exp ) / 10;
            exp /= 100;
        }
        return true;
    }
};