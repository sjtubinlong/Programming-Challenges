class Solution {
public:
    int ladderLength(string start, string end,  unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<string> Q;
        Q.push(start);
        map<string, int> result;
        result[start] = 1;
        while(!Q.empty())
        {
            string cur = Q.front();
            Q.pop();
            if( cur==end )
            {
                break;
            }
            for( int i = 0; i != cur.size(); ++i )
            {
                for( int j = 0; j != 26; ++j )
                {
                    string tmp = cur;
                    tmp[i] = 'a'+ j;
                    if( tmp[i]==cur[i] )
                    {
                        continue;
                    }
                    unordered_set<string>::const_iterator it = dict.find(tmp);
                    if( it != dict.end() )
                    {
                        Q.push(tmp);
                        result[tmp] = result[cur]+1;
                        dict.erase(tmp);
                    }
                }
            }
        }
        return result[end];
    }
};