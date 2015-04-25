// DP, simple iteration
# include <iostream>
# include <vector>
using namespace std;

int g[11][101];
int ans[11][101];
int trace[11][101][2];

int solve(int n, int m){
    for(int i = 0; i < n; ++i){
        ans[i][m-1] = g[i][m-1];
    }
    for(int i = m-2; i >= 0; --i){
        for(int j = 0; j < n; ++j){
            ans[j][i] = min(ans[j][i], ans[j][i+1] + g[j][i]);
            trace[j][i][0] = j;
            trace[j][i][1] = i + 1;

            int line = (j - 1 + n) % n;
            if(ans[j][i] > ans[line][i+1] + g[j][i]){
                ans[j][i] = ans[line][i+1] + g[j][i];
                trace[j][i][0] = line;
                trace[j][i][1] = i + 1;
            }else if(ans[j][i] == ans[line][i+1] + g[j][i]){
                if(line < trace[j][i][0]){
                    trace[j][i][0] = line;
                    trace[j][i][1] = i + 1;
                }
            }
            line = (j + 1) % n;
            if(ans[j][i] > ans[line][i+1] + g[j][i]){
                ans[j][i] = ans[line][i+1] + g[j][i];
                trace[j][i][0] = line;
                trace[j][i][1] = i + 1;
            }else if(ans[j][i] == ans[line][i+1] + g[j][i]){
                if(line < trace[j][i][0]){
                    trace[j][i][0] = line;
                    trace[j][i][1] = i + 1;
                }
            }
        }
    }
    int ret = 0;
    for(int i = 1; i < n; ++i){
        if(ans[ret][0] > ans[i][0]){
            ret = i;
        }else if(ans[ret][0] == ans[i][0]){
            ret = min(i, ret);
        }
    }
    return ret;
}

int main(){
    int n, m;
    while(cin >> n >> m){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin >> g[i][j];
                trace[i][j][0] = -1;
                trace[i][j][1] = -1;
                ans[i][j] = 0x7FFFFFFF;
            }
        }
        int x = solve(n, m);
        int y = 0;
        int total = 0;
        while(x != - 1 && y != -1){
            total += g[x][y];
            int _x = trace[x][y][0], _y = trace[x][y][1];
            if(_x == -1 && _y == -1){
                cout << x + 1 << endl;
            }else{
                cout << x + 1 << " ";
            }
            x = _x, y = _y;
        }
        cout << total << endl;
    }
}
