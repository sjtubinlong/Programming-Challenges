//DFS
# include <iostream>

using namespace std;

const int MAXN = 21;

int n;
int ans = 0;
int vis[MAXN];
int network[MAXN][MAXN];

int cal(){
    int total = 0;
    for(int i = 0; i < n; ++i){
        if(!vis[i]) continue;
        for(int j = 0; j < n; ++j){
            if(vis[j]) continue;
            total += network[i][j];
        }
    }
    return total;
}

void dfs(int k){
    if(k >= n){
        int sum = cal();
        if(sum > ans) ans = sum;
        return;
    }
    vis[k] = 1;
    dfs(k+1);
    vis[k] = 0;
    dfs(k+1);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        vis[i] = 0;
        for(int j = 0; j < n; ++j){
            cin >> network[i][j];
        }
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}
