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

int solve(const string& beads){
    int n = beads.size();
    int ans = 0;
    int i = 0;
    while(i < n) {
        while(beads[i] == 'w' && i < n) ++i;
        if(i == n){
            if(ans == 0) ans = n;
            break;
        }
        int n1 = 0;
        int j = (i - 1 + n) % n;
        while(j != i && beads[j] == 'w'){
           ++n1;
           j = (j - 1 + n) % n;
        }
        int k = j;
        while(k != i){
           if(beads[k] == beads[j] || beads[k] == 'w') ++n1;
           else break;
           k = (k - 1 + n) % n;
        }
        k = (k + 1) % n;

        int n2 = 0;
        j = i;
        while(j != k) {
           if(beads[j] == beads[i] || beads[j] == 'w') ++n2;
           else break;
           j = (j + 1) % n;
        }
        if(n1 + n2 > ans) ans = n1 + n2;
        ++i;
    }
    return ans;
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
