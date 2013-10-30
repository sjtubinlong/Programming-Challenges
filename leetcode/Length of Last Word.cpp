class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = 0;
        while( *s != '\0' ){
            while( *s == ' ' ){
                ++s;
                if( *s=='\0' ) return len;
            }
            len = 0;
            while( *s != ' ' ){
                ++s;
                ++len;
                if( *s == '\0' )break;
            }
        }
        return len;
    }
};