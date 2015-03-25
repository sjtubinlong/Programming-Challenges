// DFS
#include <iostream>

using namespace std;

const int MAXN = 102;
const int MAXM = 102;

char land[MAXN][MAXM];
int N, M;

void dfs(int x, int y){
    land[x][y] = '.';
    for(int i = -1; i <= 1; ++i){
        for(int j = -1; j <= 1; ++j){
            int _x = x + i;
            int _y = y + j;
            if(_x < 0 || _x >= N) continue;
            if(_y < 0 || _y >= M) continue;
            if(land[_x][_y] != 'W') continue;
            dfs(_x, _y);
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; ++i){
        cin >> land[i];
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; ++j){
            if(land[i][j] == 'W'){
                dfs(i, j);
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
