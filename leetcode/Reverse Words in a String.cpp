class Solution {
public:
    void reverseWords(string &s) {
        string str;
        for( int i = s.size()-1; i >= 0 ; --i )
        {
            while( i >=0 && s[i]==' ' ) --i;
            if( i < 0 ) break;
            if( !str.empty() )str += ' ';
            string tmp;
            while( i >= 0 && s[i] != ' ' ) tmp += s[i--];
            reverse( tmp.begin(), tmp.end() );
            str += tmp;
        }
        s = str;
    }
};