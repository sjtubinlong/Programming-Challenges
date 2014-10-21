# include <iostream>
# include <cstdio>
# include <string>
# include <queue>

using namespace std;

const int NMAX = 50;
const int CMAX = 26;
const int PMAX = 6;

typedef unsigned long long ull;
class Matrix{
public:
    int n;
    unsigned long long d[NMAX][NMAX];
public:
    Matrix(int _n): n(_n){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                d[i][j] = 0;
            }
        }
    }

    Matrix operator+(const Matrix& _M)const{
        Matrix R(n);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                R.d[i][j] = d[i][j] + _M.d[i][j];
            }
        }
        return R;
    }

    Matrix& operator+=(const Matrix& _M){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                d[i][j] += _M.d[i][j];
            }
        }
        return *this;
    }

    Matrix operator*(const Matrix& _M) const{
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

    Matrix& operator*=(const Matrix& _M){
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
    
    Matrix& operator=(const Matrix& _M){
        n = _M.n;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                d[i][j] = _M.d[i][j];
            }
        }
        return *this;
    }

    Matrix operator^(unsigned long long k) const{
        if(k == 1){
            return *this;
        }
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

    Matrix power_sum(unsigned long long k) const{
        if(k == 1) return *this;
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
                R = R + R*T;
                T = T * T;
            }
        } 
        return R;
    }
    
    void print() const{
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf(" %llu", d[i][j]);
            }
            printf("\n");
        }
    }
};

struct Node {
    int exists;
    int fail;
    int next[CMAX];
    Node(): exists(0), fail(-1){
        for(int i = 0; i < CMAX; ++i){
            next[i] = -1;
        }
    }
};

Node Trie[NMAX];
int root = 0;
int size = 1;

void insert(const char* str) {
    int cur = root;
    for(int i = 0; str[i] != '\0'; ++i){
        int k = str[i] - 'a';
        if(Trie[cur].next[k] == -1){
            Trie[cur].next[k] = size++;
        }
        cur = Trie[cur].next[k];
    }
    Trie[cur].exists = 1;
}

int Q[NMAX];
int head = 0;
int tail = 0;

void build_fail(){
    head = tail = 0;
    Trie[root].exists = 0;
    for(int i = 0; i < CMAX; ++i){
        if(Trie[root].next[i] != -1){
            Trie[Trie[root].next[i]].fail = root;
            Q[tail++] = Trie[root].next[i];
        }
    }
    while(head != tail){
        int cur = Q[head++];
        Trie[cur].exists |= Trie[Trie[cur].fail].exists;
        for(int i = 0; i < CMAX; ++i){
            if(Trie[cur].next[i] != -1){
                int p = Trie[cur].fail;
                while(p != -1){
                    if(Trie[p].next[i] != -1){
                        Trie[Trie[cur].next[i]].fail = Trie[p].next[i];
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

void init_matrix(Matrix& M){
    for(int i = 0; i < size; ++i){
        if(Trie[i].exists) continue;
        for(int j = 0; j < CMAX; ++j){
            int cur = Trie[i].next[j];
            if(cur != -1){
                if(!Trie[cur].exists){
                    M.d[i][cur]++;
                }
            }else{
                int p = Trie[i].fail;
                while( p != -1 ){
                    if( Trie[p].next[j] != -1){
                        if(!Trie[Trie[p].next[j]].exists)
                            M.d[i][Trie[p].next[j]]++;
                        break;
                    }
                    p = Trie[p].fail;
                }
                if(p == -1) M.d[i][root]++;
            }
        }
    }
}

ull solve(ull L, Matrix& M){
    Matrix R = M.power_sum(L);
    //R.print();
    ull num = 0;
    for(ull i = 0; i < R.n; ++i){
        num += R.d[0][i];
    }
    R.n = 1;
    R.d[0][0] = 26;
    Matrix T = R.power_sum(L);
    ull total = 0;
    for(ull i = 0; i < T.n; ++i){
        total += T.d[0][i];
    }
    return total - num;
}

void reset_trie(){
    for(int i = 0; i < NMAX; ++i){
        Trie[i].exists = 0;
        Trie[i].fail = -1;
        for(int j = 0; j < CMAX; ++j){
            Trie[i].next[j] = -1;
        }
    }
}


int main(){
    ull N, L;
    char word[PMAX];
    while(cin>>N>>L){
        reset_trie();
        root = 0;
        size = 1;
        for(int i = 0; i < N; ++i){
            scanf("%s", word);
            insert(word);
        }
        build_fail();
        Matrix M(size);
        init_matrix(M);
        //cout << solve(L, M) << endl;
        printf("%I64u\n", solve(L, M));
    }
    return 0;
}