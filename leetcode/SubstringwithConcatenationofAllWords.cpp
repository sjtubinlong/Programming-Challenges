class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = S.size();
        int m = L.size();
        int wordLen = L[0].size();
        vector<int> result;
        unordered_map< string, int > dict;
        unordered_map< string, int > curr;
        for( int i = 0; i < m; ++i ){
            ++dict[ L[i] ];
        }
        for( int i = 0; i <= n-m*wordLen; i++ ){
            curr.clear();
            bool found = true;
            for( int j = 0; j < m; ++j ){
                string str = S.substr( i+j*wordLen, wordLen );
                if( dict.find(str)==dict.end() ){
                    found = false;
                    break;
                }
                ++curr[str];
                if( curr[str] > dict[str] ){
                    found = false;
                    break;
                }
            }
            if( found ){
                result.push_back(i);
            }
        }
        return result;
        
    }
};