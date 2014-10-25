#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

const int CMAX = 4;
const int NMAX = 50;
const int LMAX = 20;
const int PMAX = 1000;
const int INF = 0x3F3F3F3F;

int min(int a, int b)
{
    return a > b ? b: a;
}

class AC_AUTO {
private:
    struct TNode {
        bool invalid;
        int fail;
        int next[CMAX];
    } T[NMAX*LMAX];
    int root;
    int size;
public:
    int id_map(char c)
    {
        if(c == 'A') return 0;
        if(c == 'T') return 1;
        if(c == 'C') return 2;
        return 3;
    }

    void init()
    {
        root = 0;
        size = 1;
        for(int i = 0; i < NMAX*LMAX; ++i){
            T[i].invalid = false;
            T[i].fail = -1;
            for(int j = 0; j < CMAX; ++j){
                T[i].next[j] = -1;
            }
        }
    }

    void insert(const string & str)
    {
        int cur = root;
        for(int i = 0; i < str.size(); ++i){
            int k = id_map(str[i]);
            if(T[cur].next[k] == -1){
                T[cur].next[k] = size++;
            }
            cur = T[cur].next[k];
        }
        T[cur].invalid = true;
    }

    void build_fail()
    {
        queue<int> Q;
        for(int i = 0; i < CMAX; ++i){
            if(T[root].next[i] != -1){
                T[T[root].next[i]].fail = root;
                Q.push(T[root].next[i]);
            }
        }
        while(!Q.empty()){
            int cur = Q.front();
            Q.pop();
            for(int i = 0; i < CMAX; ++i){
                if(T[cur].next[i] != -1){
                    int p = T[cur].fail;
                    while(p != -1){
                        if(T[p].next[i] != -1){
                            T[T[cur].next[i]].fail = T[p].next[i];
                            T[T[cur].next[i]].invalid |= T[T[p].next[i]].invalid;
                            break;
                        }
                        p = T[p].fail;
                    }
                    if(p == -1) T[T[cur].next[i]].fail = root;
                    Q.push(T[cur].next[i]);
                }
            }
        }
    }

    int query(const string& str)
    {
        int dp[PMAX][NMAX*LMAX];
        memset(dp, 0x3F, sizeof(int)*NMAX*LMAX*PMAX);
        
        int k = id_map(str[0]);
        if(T[root].next[k] == -1){
            dp[0][0] = 0;
        }
        for(int i = 0; i < CMAX; ++i){
            if(T[root].next[i] == -1 || T[T[root].next[i]].invalid) continue;
            dp[0][T[root].next[i]] = (i != k);
        }

        for(int i = 1; i < str.size(); ++i){
            int k = id_map(str[i]);
            for(int j = 0; j < size; ++j){
                if(dp[i-1][j] == INF) continue;
                for(int v = 0; v < CMAX; ++v){
                    if(T[j].next[v] != -1){
                        if(T[T[j].next[v]].invalid) continue;
                        dp[i][T[j].next[v]] = min(dp[i][T[j].next[v]], dp[i-1][j] + (v != k));
                    }else{
                        int p = T[j].fail;
                        while(p != -1){
                            if(T[p].next[v] != -1){
                                if(!T[T[p].next[v]].invalid){
                                    dp[i][T[p].next[v]] = min(dp[i][T[p].next[v]], dp[i-1][j] + (v != k));
                                }
                                break;
                            }
                            p = T[p].fail;
                        }
                        if(p == -1) dp[i][root] = min(dp[i][root], dp[i-1][j] + (v != k));
                    }
                }
            }
        }
        int ans = INF;
        for(int i = 0; i < size; ++i){
            ans = min(ans, dp[str.size()-1][i]);
        }
        return ans == INF ? -1 : ans;
    }
};

int main()
{
    int n;
    int num = 0;
    while(cin>>n && n != 0){
        ++num;
        string virus;
        AC_AUTO ac_trie;
        ac_trie.init();
        for(int i = 0; i < n; ++i){
            cin>>virus;
            ac_trie.insert(virus);
        }
        ac_trie.build_fail();
        cin>>virus;
        cout<< "Case " << num << ": " << ac_trie.query(virus) << endl;
    }
    return 0;
}