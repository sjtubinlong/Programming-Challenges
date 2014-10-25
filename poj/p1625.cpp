
# include <iostream>
# include <cstdio>
# include <cstring>

const int SMAX = 223;
const int CMAX = 50;
const int PMAX = 50;
const int NMAX = 10;
int ID_MAP[SMAX];

const int BASE = 10000;
const int DLEN = 100;

class BigInt {
public:
    int n;
    short d[DLEN];
    BigInt(): n(1)
    {
        memset(d, 0, sizeof(short)*DLEN);
    }

    BigInt(int q): n(1)
    {
        memset(d, 0, sizeof(short)*DLEN);
        d[0] = q;
    }

    BigInt operator+ (const BigInt& M) const
    {
        BigInt R;
        int i = 0, v = 0;
        while(i < n || i < M.n){
            R.d[i] = d[i] + M.d[i] + v;
            v = R.d[i] / BASE;
            R.d[i] %= BASE;
            ++i;
        }
        if(v > 0){
            R.d[i++] = v;
        }
        R.n = i;
        return R;
    }

    BigInt& operator+= (const BigInt& M)
    {
        int i = 0, v = 0;
        while(i < n || i < M.n){
            d[i] += M.d[i] + v;
            v = d[i] / BASE;
            d[i] %= BASE;
            ++i;
        }
        if(v > 0){
            d[i++] = v;
        }
        n = i;
        return *this;
    }

    void print() const
    {
        printf("%d", d[n-1]);
        for(int i = n-2; i >= 0; --i){
            printf("%04d", d[i]);
        }
        printf("\n");
    }
};

BigInt dp[PMAX*NMAX][PMAX];

class AC_AUTO {
private:
    struct TNode {
        bool invalid;
        int fail;
        int next[CMAX];
    } T[PMAX*NMAX];
    int root;
    int size;
    int lsize;
public:
    void init(int _lsize)
    {
        root = 0;
        size = 1;
        lsize = _lsize;
        for(int i = 0; i < PMAX*NMAX; ++i){
            T[i].invalid = false;
            T[i].fail = -1;
            for(int j = 0; j < lsize; ++j){
                T[i].next[j] = -1;
            }
        }
    }

    void insert(const unsigned char* str)
    {
        int cur = root;
        for(int i = 0; str[i] != '\0'; ++i){
            int k = ID_MAP[str[i]];
            if(T[cur].next[k] == -1){
                T[cur].next[k] = size++;
            }
            cur = T[cur].next[k];
        }
        T[cur].invalid = true;
    }

    void build_fail()
    {
        int head = 0, tail = 0;
        int Q[PMAX*NMAX];
        for(int i = 0; i < lsize; ++i){
            if(T[root].next[i] != -1){
                T[T[root].next[i]].fail = root;
                Q[tail++] = T[root].next[i];
            }
        }

        while(head != tail){
            int cur = Q[head++];
            for(int i = 0; i < lsize; ++i){
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
                    Q[tail++] = T[cur].next[i];
                }
            }
        }
    }

    void build_states(int len)
    {
        BigInt E(1);
        for(int j = 0; j < lsize; ++j){
            if(T[root].next[j] != -1){
                if(!T[T[root].next[j]].invalid){
                    dp[T[root].next[j]][1] = E;
                }
            }else{
                    dp[root][1] = dp[root][1] + E;
            }
        }
        for(int i = 2; i <= len; ++i){
            for(int j = 0; j < size; ++j){
                if(T[j].invalid) continue;
                for(int k = 0; k < lsize; ++k){
                    if(T[j].next[k] != -1){
                        if(!T[T[j].next[k]].invalid){
                            dp[T[j].next[k]][i] += dp[j][i-1];
                        }
                    }else{
                        int p = T[j].fail;
                        while(p != -1){
                            if(T[p].next[k] != -1){
                                if(!T[T[p].next[k]].invalid){
                                    dp[T[p].next[k]][i] += dp[j][i-1];
                                }
                                break;
                            }
                            p = T[p].fail;
                        }
                        if(p == -1) dp[root][i] += dp[j][i-1];
                    }
                }
            }
        }
    }

    void solve(int len)
    {
        BigInt R;
        for(int i = 0; i < size; ++i){
            if(T[i].invalid) continue;
            R += dp[i][len];
        }
        R.print();
    }

};

void init_id_map(const unsigned char* letters)
{
    for(int i = 0; i < SMAX; ++i){
        ID_MAP[i] = -1;
    }

    for(int i = 0; letters[i] != '\0'; ++i){
        ID_MAP[letters[i]] = i;
    }
}

int main()
{
    unsigned char letters[PMAX+1];
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    getchar();
    gets((char*)letters);
    init_id_map(letters);
    AC_AUTO ac_trie;
    ac_trie.init(n);
    for(int i = 0; i < p; ++i){
       gets((char*)letters);
       ac_trie.insert(letters);
    }
    ac_trie.build_fail();
    ac_trie.build_states(m);
    ac_trie.solve(m);
    return 0;
}
