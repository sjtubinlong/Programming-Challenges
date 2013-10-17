class Solution {
public:
    int sqrt(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( x < 2 ) return x;
        int from = 1, to = x/2;
        int cur = 1;
        while( from <= to ){
            cur = from + (to-from)/2;
            if( x/cur > cur ){
                from = cur+1;
            }else if( x/cur < cur ){
                to = cur-1;
            }else { return cur; }
        }
        return from-1;
    }
};