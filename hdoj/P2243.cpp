# include <iostream>
# include <cstdio>
# include <string>
# include <queue>

using namespace std;

typedef unsigned long long ull;

const int NMAX = 50;
const int CMAX = 26;
const int PMAX = 6;

class Matrix{
public:
    int n;
    ull d[NMAX][NMAX];
public:
    Matrix(int _n): n(_n)
    {
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                d[i][j] = 0;
            }
        }
    }

    Matrix operator+(const Matrix& _M) const
    {
        Matrix R(n);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                R.d[i][j] = d[i][j] + _M.d[i][j];
            }
        }
        return R;
    }

    Matrix& operator+=(const Matrix& _M)
    {
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                d[i][j] += _M.d[i][j];
            }
        }
        return *this;
    }

    Matrix operator*(const Matrix& _M) const
    {
        Matrix R(n);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                for(int k = 0; k < n; ++k){
                    R.d[i][j] += d[i][k] * _M.d[k][j];
                }
            }
        }
        return R;
    }

    Matrix& operator*=(const Matrix& _M)
    {
        Matrix R(n);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                for(int k = 0; k < n; ++k){
                   R.d[i][j] += d[i][k]*_M.d[k][j];                    
                }
            }
        }
        *this = R;
        return *this;
    }
    
    Matrix& operator=(const Matrix& _M)
    {
        n = _M.n;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                d[i][j] = _M.d[i][j];
            }
        }
        return *this;
    }

    Matrix operator^(ull k) const
    {
        Matrix A = *this;
        Matrix B = *this;
        for(--k; k; k >>= 1){
            if(k & 1){
                A *= B;
            }
            B *= B;
        }
        return A;
    }

    Matrix power_sum(ull k) const
    {
        Matrix R = *this;
        Matrix T = *this;
        int highest = 31;
        while( (k >> highest) == 0 ) --highest;
        for(int i = highest-1; i >= 0; --i){
            if(k & (1 << i)){
                //S(2n+1) = S(n) + T^n * S(n) + T^(2n+1)
                R = R + T * R + T * T * (*this);
                T = T * T * (*this);
            }else{
                //S(2n) = S(n) + T^n*S(n)
                R = R + R*T;
                T = T * T;
            }
        }
        return R;
    }
};

class AcAuto {
private:
    struct TNode {
        bool invalid;
        int fail;
        int next[CMAX];
    } Trie[NMAX];
    int size;
    int root;
public:
    void init()
    {
        root = 0;
        size = 1;
        for(int i = 0; i < NMAX; ++i){
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
            int k = str[i] - 'a';
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
        int Q[NMAX];
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

    Matrix build_states()
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
                        if(Trie[p].next[j] != -1 ){
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

ull solve(Matrix& R, ull L)
{
    Matrix T = R.power_sum(L);
    ull num = 0;
    for(int i = 0; i < T.n; ++i){
        num += T.d[0][i];
    }
    ull total = 0;
    T.n = 1;
    T.d[0][0] = 26;
    T = T.power_sum(L);
    total = T.d[0][0];
    return total - num;
}

int main(){
    ull N, L;
    AcAuto ac_auto;
    string word;
    while(cin>>N>>L){
        ac_auto.init();
        for(int i = 0; i < N; ++i){
            cin>>word;
            ac_auto.insert(word);
        }
        ac_auto.build_fail();
        Matrix R = ac_auto.build_states();
        //cout << solve(R, L) << endl;
        printf("%I64u\n", solve(R, L));
    }
    return 0;
}