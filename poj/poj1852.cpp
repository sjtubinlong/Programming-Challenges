# include <stdio.h>

const int LMAX = 1000000;

int t, n, len, dist[LMAX];

int max(int a, int b){
    return a >= b ? a : b;
}

int min(int a, int b){
    return a <= b ? a : b;
}

void solve(){
    // 寻找最短时间
    int minT = 0;
    for(int i = 0; i < n; ++i){
        int minL = min(dist[i], len - dist[i]);
        if(minL > minT){
            minT = minL;
        }
    }
    // 寻找最长时间
    int maxT = 0;
    for(int i = 0; i < n; ++i){
        int maxL = max(dist[i], len - dist[i]);
        if(maxL > maxT){
            maxT = maxL;
        }
    }
    printf("%d %d\n", minT, maxT);
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &len, &n);
        for(int i = 0; i < n; ++i){
            scanf("%d", &dist[i]);
        }
        solve();
    }
    return 0;
}
