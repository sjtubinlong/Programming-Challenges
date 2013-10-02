class Solution {
public:
    bool isPalindrome(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int from = 0;
        int to = s.size()-1;
        while( from < to ){
            if( !isAlpha(s[from]) ){
                ++from;
                continue;
            }
            if( !isAlpha( s[to] ) ){
                --to;
                continue;
            }
            if( f(s[from]) != f(s[to]) ){
                return false;
            }
            ++from;
            --to;
        }
        return true;
    }
    bool isAlpha( char c ){
        if( c >= 'a' && c <= 'z'){
            return true;
        }else if( c >= 'A' && c <= 'Z' ){
            return true;
        }else if( c >= '0' && c <= '9' ){
            return true;
        }
        return false;
    }
    char f( char c ){
        if( c >= 'a' && c <= 'z'){
            return 'A'+c-'a';
        }
        return c;
    }
};