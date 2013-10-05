class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        if( !s || !p ) return false;
        if( p[0] == '\0' ) {
            return s[0]=='\0';
        }
        if( p[1] == '*' ) {
            while( ( s[0] != '\0' && p[0] == '.' ) || s[0] == p[0] ) {
                if ( isMatch( s, p + 2 ) )
                    return true;
                s += 1;
            }
            return isMatch(s, p + 2);
        }else if( ( s[0] != '\0' && p[0] == '.' ) || s[0] == p[0] ) {
            return isMatch(s + 1, p + 1);
        }
        return false;
    }
};