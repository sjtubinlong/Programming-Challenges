class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> result;
        string cur( digits.size(), '.');
        vector<string> map(12,"");
        map[2] = "abc";
        map[3] = "def";
        map[4] = "ghi";
        map[5] = "jkl";
        map[6] = "mno";
        map[7] = "pqrs";
        map[8] = "tuv";
        map[9] = "wxyz";
        dfs(0, map, digits, cur, result );
        return result;
    }
    void dfs( int k, vector<string>&map, string&src, string&cur, vector<string>&result )
    {
        if( k>=src.size() )
        {
            result.push_back(cur);
            return;
        }
        int digit = src[k]-'0';
        for( int i = 0; i < map[digit].size(); ++i )
        {
            cur[k] = map[digit][i];
            dfs( k+1, map, src, cur, result );
        }
    }
};