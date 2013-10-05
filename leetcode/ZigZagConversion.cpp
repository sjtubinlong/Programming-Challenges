class Solution {
public:
    string convert(string s, int nRows) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        int n = s.size();
        if( nRows <= 1 || n<=nRows ) return s;
        string result( s );
        int k = 0;
        for( int i = 0; i != nRows; ++i ){
            int j = i;
            int flag = 0;
            while( j < n ){
                result[k++] = s[j];
                if( i==0 || i==nRows-1 ) j += (2*nRows-2);
                else if( flag == 0 ){
                    flag = 1;
                    j += ( 2*nRows-2-2*i );
                }else if( flag==1 ){
                    flag = 0;
                    j += 2*i;
                }
            }
        }
        return result;
    }
};