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

int solve_without_mod(string& beads){
    beads += beads;
    int n = beads.size();
    int ans = 0;
    int i = 0;
    while(i < n) {
        while(i < n && beads[i] == 'w') ++i;
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

int solve_with_mod(const string& beads){
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
    // int ans = solve_without_mod(beads);
    int ans = solve_with_mod(beads);
    fout << ans << endl;
    return 0;
}
