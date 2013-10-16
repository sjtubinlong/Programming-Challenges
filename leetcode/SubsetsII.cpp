class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector< vector<int> >result;
        vector<int> cur;
        result.push_back(cur);
        int n = S.size();
        if( n==0 ) return result;
        unordered_set<int> hash;
        set< vector<int> > rec;
        dfs( S, hash, result, cur, 0 ,rec );
        return result;
    }
    void dfs( vector<int>& S, unordered_set<int>& hash, 
                vector< vector<int> >&result, vector<int>& cur, int k, set< vector<int> >& rec ){
        if( k > S.size()  ) return;
        if( k > 0 ){
            if( rec.find(cur)!=rec.end() ){
                return;
            }
            rec.insert(cur);
            result.push_back(cur);
        }
        int n = S.size();
        for( int i = 0; i < n; ++i ){
            if( (k==0 || S[i]>=cur[k-1]) && hash.find(i)==hash.end() ){
                hash.insert(i);
                cur.push_back(S[i]);
                dfs( S, hash, result, cur, k+1,rec);
                hash.erase(i);
                cur.pop_back();
            }
        }
    }
};