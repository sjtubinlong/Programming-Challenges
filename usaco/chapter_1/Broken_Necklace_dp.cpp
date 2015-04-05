/*
ID: binlong3
PROG: beads
LANG: C++
*/

# include <iostream>
# include <vector>
# include <fstream>
# include <string>
using namespace std;

int solve(string& beads){
    beads += beads;
    int n = beads.size();
    vector< vector<int> > left(2, vector<int>(n+1, 0));
    vector< vector<int> > right(2, vector<int>(n+1, 0));
    left[0][0] = left[1][0] = 0;
    for(int i = 1; i <= n; ++i){
        if(beads[i-1] == 'r'){
            left[0][i] = left[0][i-1] + 1;
            left[1][i] = 0;
        }else if(beads[i-1] == 'b'){
            left[1][i] = left[1][i-1] + 1;
            left[0][i] = 0;
        }else{
            left[0][i] = left[0][i-1] + 1;
            left[1][i] = left[1][i-1] + 1;
        }
    }
    right[0][n] = right[1][n] = 0;
    for(int i = n-1; i >= 0; --i){
        if(beads[i] == 'r'){
            right[0][i] = right[0][i+1] + 1;
            right[1][i] = 0;
        }else if(beads[i] == 'b'){
            right[1][i] = right[1][i+1] + 1;
            right[0][i] = 0;
        }else{
            right[0][i] = right[0][i+1] + 1;
            right[1][i] = right[1][i+1] + 1;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        int o1 = max(left[0][i], left[1][i]);
        int o2 = max(right[0][i], right[1][i]);
        if(o1 + o2 > ans) ans = o1 + o2;
    }
    return min(ans, n/2);
}


int main(){
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int N;
    string beads;
    fin >> N;
    fin >> beads;
    int ans = solve(beads);
    fout << ans << endl;
    return 0;
}
