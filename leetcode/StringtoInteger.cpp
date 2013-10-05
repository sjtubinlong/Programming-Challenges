class Solution {
public:
    int atoi(const char *str) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if( str==NULL ) return 0;
        const char* cur = str;
        while( *cur==' ') ++cur;
        if( *cur=='\0' ) return 0;
        int flag = 1;
        if( *cur=='-' ) {
            flag = -1;
            ++cur;
        }else if( *cur=='+' ){
            ++cur;
        }
        long long result = 0;
        while( *cur != '\0' ){
            if( *cur < '0' || *cur  > '9' ) break;
            result = result*10 + *cur - '0';
            ++cur;
        }
        result *= flag;
        if( result >= INT_MAX ) return INT_MAX;
        if( result <= INT_MIN ) return INT_MIN;
        return result;
    }
};