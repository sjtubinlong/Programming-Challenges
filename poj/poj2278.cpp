/*
m (0 <= m <= 10), n (1 <= n <=2000000000)
l 0 to 10
mod 100000
*/
# include <iostream>
# include <cstring>
# include <string>

using namespace std;

typedef unsigned long long ull;

const int CMAX = 4;
const int NMAX = 10;
const int PMAX = 10;

class Matrix {
public:
    int n;
    ull d[NMAX*PMAX][NMAX*PMAX];
    
    Matrix(int _n): n(_n)
    {
        memset(d, 0, NMAX*PMAX*NMAX*PMAX*sizeof(ull));
    }

    Matrix operator+ (const Matrix& T) const
    {
        Matrix R(n);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                R.d[i][j] = d[i][j] + T.d[i][j];
            }
        }
        return R;
    }

    Matrix operator* (const Matrix& T) const
    {
        Matrix R(n);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                for(int k = 0; k < n; ++k){
                    R.d[i][j] += d[i][k] * T.d[k][j];
                }
                R.d[i][j] %= 100000;
            }
        }
        return R;
    }

    Matrix& operator= (const Matrix& T)
    {
        n = T.n;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                d[i][j] = T.d[i][j];
            }
        }
        return *this;
    }

    Matrix operator^ (ull n)
    {
        Matrix R = *this;
        Matrix T = *this;
        for(--n; n; n >>= 1){
            if(n & 1){
                R = R * T;
            }
            T = T * T;
        }
        return R;
    }
};

int ID(char c)
{
    if(c == 'A') return 0;
    if(c == 'T') return 1;
    if(c == 'C') return 2;
    if(c == 'G') return 3;
    return -1;
}

class AC_AUTO{
private:
    struct TNODE {
        bool invalid;
        int fail;
        int next[CMAX];
    }Trie[NMAX * PMAX];
    int root;
    int size;
public:
    void init()
    {
        root = 0;
        size = 1;
        for(int i = 0; i < PMAX*NMAX; ++i){
            Trie[i].invalid = false;
            Trie[i].fail = -1;
            for(int j = 0; j < CMAX; ++j){
                Trie[i].next[j] = -1;
            }
        }
    }
    void insert(const string& str)
    {
        int cur = root;
        for(int i = 0; i < str.size(); ++i){
            int k = ID(str[i]);
            if(Trie[cur].next[k] == -1){
                Trie[cur].next[k] = size++;
            }
            cur = Trie[cur].next[k];
        }
        Trie[cur].invalid = true;
    }

    void build_fail()
    {
        int head = 0, tail = 0;
        int Q[PMAX*NMAX];

        for(int i = 0; i < CMAX; ++i){
            if(Trie[root].next[i] != -1){
                Trie[Trie[root].next[i]].fail = root;
                Q[tail++] = Trie[root].next[i];
            }
        }

        while(head != tail){
            int cur = Q[head++];
            for(int i = 0; i < CMAX; ++i){
                if(Trie[cur].next[i] != -1){
                    int p = Trie[cur].fail;
                    while(p != -1){
                        if(Trie[p].next[i] != -1){
                            Trie[Trie[cur].next[i]].fail = Trie[p].next[i];
                            Trie[Trie[cur].next[i]].invalid |= Trie[Trie[p].next[i]].invalid;
                            break;
                        }
                        p = Trie[p].fail;
                    }
                    if(p == -1) Trie[Trie[cur].next[i]].fail = root;
                    Q[tail++] = Trie[cur].next[i];
                }
            }
        }
    }

    Matrix build_states() const
    {
        Matrix R(size);
        for(int i = 0; i < size; ++i){
            if(Trie[i].invalid) continue;
            for(int j = 0; j < CMAX; ++j){
                if(Trie[i].next[j] != -1){
                    if(Trie[Trie[i].next[j]].invalid) continue;
                    R.d[i][Trie[i].next[j]]++;
                }else{
                    int p = Trie[i].fail;
                    while(p != -1){
                        if(Trie[p].next[j] != -1){
                            if(!Trie[Trie[p].next[j]].invalid){
                                R.d[i][Trie[p].next[j]]++;
                            }
                            break;
                        }
                        p = Trie[p].fail;
                    }
                    if(p == -1) R.d[i][root]++;
                }
            }
        }
        return R;
    }
};

ull solve(Matrix & R, ull L)
{
    Matrix T = R^L;
    ull num = 0;
    for(int i = 0; i < R.n; ++i){
        num += T.d[0][i];
    }
    return num % 100000;
}

int main()
{
    int m, n;
    string virus;
    AC_AUTO ac_auto;
    cin>>m>>n;
    ac_auto.init();
    for(int i = 0; i < m; ++i){
        cin>>virus;
        ac_auto.insert(virus);
    }
    ac_auto.build_fail();
    Matrix R = ac_auto.build_states();
    cout<<solve(R, n)<<endl;
    return 0;
}