class Solution {
public:
    string addBinary(string a, string b) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int aLen = a.size();
        int bLen = b.size();
        int cLen = aLen>bLen?aLen:bLen;
        string result( cLen, '0' );
        reverse( a.begin(), a.end() );
        reverse( b.begin(), b.end() );
        for( int i = aLen+1; i <= cLen; ++i ){
            a += '0';
        }
        for( int i = bLen+1; i <= cLen; ++i ){
            b += '0';
        }
        int v = 0;
        for( int i = 0; i != cLen; ++i ){
            result[i] = '0' + a[i]-'0' + b[i] - '0' + v;
            v = (result[i]-'0')/2;
            result[i] = '0' + (result[i]-'0')%2;
        }
        if( v > 0 ){
            result += ( '0'+v );
            ++cLen;
        }
        reverse( result.begin(), result.end() );
        return result;
    }
};