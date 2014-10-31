/*
Problem: HDOJ 1711
Author: 靖难
Tag: KMP, string match, DFA
Difficulty: 1 (from 1 to 5)
*/

# include <stdio.h>
# include <string.h>

const int NMAX = 1000000;
const int MMAX = 10000;

char Pattern[MMAX];
char Target[NMAX];
int Next[MMAX];

int kmp(int n, int m)
{
    Next[0] = -1;
    int p = -1;
    for(int i = 1; i < m; ++i){
        while(p != -1 && Pattern[p+1] != Pattern[i]){
            p = Next[p];
        }
        if(Pattern[p+1] == Pattern[i]){
            p = p + 1;
        }
        Next[i] = p;
    }
    int num = 0;
    p = -1;
    for(int i = 0; i < n; ++i){
        while(p != -1 && Pattern[p+1] != Target[i]){
            p = Next[p];
        }
        if(Pattern[p+1] == Target[i]){
            p = p + 1;
        }
        if(p == m-1) ++num;
    }
    return num;
}

int main()
{
    int T = 0, N = 0, M = 0;
    scanf("%d", &T);

    while(T--){
        scanf("%s", Pattern);
        scanf("%s", Target);
        printf("%d\n", kmp(strlen(Target), strlen(Pattern)));
    }
}
