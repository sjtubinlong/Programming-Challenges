// DP, Typic Matrix Chain Problem
# include <iostream>
# include <vector>

using namespace std;

int solve(vector<int>& cut){
    int n = cut.size();
    vector< vector<int> > ans(n, vector<int>(n, 0x7FFFFFFF));
    for (int i = 0; i < n; ++i){
        ans[i][i] = 0;
        if(i+1 < n) ans[i][i+1] = 0;
    }
    for(int i = 2; i < n; ++i){
        for(int j = 0; j < n; ++j){
            for(int k = j + 1; k < j + i; ++k){
                if(j + i >= n) continue;
                int cost = ans[j][k] + ans[k][j+i] + cut[j+i] - cut[j];
                ans[j][j+i] = min(ans[j][j+i], cost);
            }
        }
    }
    return ans[0][n-1];
}

int main(){
    int len;
    while(cin >> len && len != 0){
        int n;
        cin >> n;
        vector<int> cut(n+2, 0);
        cut[0] = 0;
        cut[n+1] = len;
        for(int i = 1; i <= n; ++i){
            cin >> cut[i];
        }
        cout << "The minimum cutting is " << solve(cut) <<"."<< endl;
    }
    return 0;
}
