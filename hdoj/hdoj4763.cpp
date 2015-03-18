# include <stdio.h>
# include <string.h>
# include <vector>

using std::vector;

const int LMAX = 1000010;

char song[LMAX];
int next[LMAX];

void build_next(int m)
{
    next[0] = -1;
    int p = -1;
    for(int i = 1; i < m; ++i){
        while(p != -1 && song[p+1] != song[i]){
            p = next[p];
        }
        if(song[p+1] == song[i]){
            p = p + 1;
        }
        next[i] = p;
        printf("next[%d] = %d\n", i, next[i]);
    }
}

int solve(int m)
{
    vector<int> occur;
    vector<int> tail;
    int i = 0;
    while(i < m){
        if(next[i] == 0){
            int num = 1;
            while(i + 1 < m && next[i + 1] == next[i]){
                ++num;
                ++i;
            }
            occur.push_back(num);
            tail.push_back(i);
        }
        ++i;
    }
    if(occur.size() < 2 || tail[tail.size()-1] != m-1) return 0;
    int max = 0;
    for(int i = 0; i < occur.size()-1; ++i){
        if(occur[i] > max) max = occur[i];
    }
    if(max < occur[occur.size()-1]) return 0;
    return occur[occur.size()-1];
}

int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%s", song);
        build_next(strlen(song));
        printf("%d\n", solve(strlen(song)));
    }
    return 0;
}