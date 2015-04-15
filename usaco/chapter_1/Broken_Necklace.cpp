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
    int ans = 0;
    int i = 0;
    while(i < n) {
        while(beads[i] == 'w') ++i;
         int n1 = 0;
         int j = i - 1;
         while(j >= 0 && beads[j] == 'w'){
            ++n1;
            --j;
         }
         int k = j;
         while(k >= 0){
            if(beads[k] == beads[j] || beads[k] == 'w') ++n1;
            else break;
            --k;
         }

         int n2 = 0;
         j = i;
         while(j < n) {
            if(beads[j] == beads[i] || beads[j] == 'w') ++n2;
            else break;
            ++j;
         }
         if(n1 + n2 > ans) ans = n1 + n2;
         ++i;
    }
    return min(ans, n / 2);
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
