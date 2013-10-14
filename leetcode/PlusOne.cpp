class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = digits.size();
        if( n==0 ) return digits;
        digits[n-1] = digits[n-1]+1;
        int v = digits[n-1]/10;
        digits[n-1] %= 10;
        for( int i = n-2; i >= 0; --i )
        {
            digits[i] += v;
            v = digits[i]/10;
            digits[i] %= 10;
        }
        if( v==0 ) return digits;
        digits.push_back(0);
        for( int i = 1; i < n+1; ++i )
        {
            digits[i] = digits[i-1];
        }
        digits[0] = v;
        return digits;
    }
};