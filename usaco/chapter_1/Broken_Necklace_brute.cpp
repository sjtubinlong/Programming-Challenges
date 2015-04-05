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
    int n = beads.size();
    int ans = 0;
    for(int i = 0; i < n; ++i){
        int o1 = 0;
        int c = -1;
        int j = (i - 1 + n) % n;
        while(j != i && beads[j] == 'w'){
            ++o1;
            j = (j - 1 + n) % n;
        }
        if(j != i) c = beads[j];
        else{
            return n;
        }
        while(j != i){
            if(beads[j] != c && beads[j] != 'w') break;
            o1 += 1;
            j = (j - 1 + n) % n;
        }
        if(j == i) return n;
        int o2 = 0;
        c = -1;
        int k = i;
        while(k != j && beads[k] == 'w'){
            ++o2;
            k = (k + 1) % n;
        }
        if(k != j) c = beads[j];
        else{
            return n;
        }
        while(k != j){
            if(beads[k] != c && beads[k] != 'w') break;
            o2 += 1;
            k = (k + 1) % n;
        }
        if(k == j){
            if(beads[j] == c) o2 += 1;
        }
        if(o1 + o2 > ans) ans = o1 + o2;
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
