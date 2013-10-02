class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        vector< vector<string> > ans;
        vector<string> result;
        f( s, result, ans );
        return ans;
    }
    
    void f( string s, vector<string>& result, vector< vector<string> >& ans ){
        int n = s.size();
        if( n==0 ){
            ans.push_back(result);
            return;
        }
        for( int i = 1; i <= n; ++i ){
            if( check(s, 0, i-1) ){
                result.push_back( s.substr(0, i) );
                f( s.substr( i, n-i), result, ans );
                result.pop_back();
            }
        }
    }
    bool check( string& s, int from, int to ){
        int i = from;
        int j = to;
        while( i<j ){
            if( s[i] != s[j] ){
                break;
            }
            ++i;
            --j;
        }
        if( i<j ) return false;
        return true;
    }
};