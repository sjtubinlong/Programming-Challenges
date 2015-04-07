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
    int n1 = 0, n2 = 0;
    char pre = 0;
    for(int i = 0; i < n; i++){
        if(beads[i] == 'w'){
            n1++;
            n2++;
        }else if(beads[i] == pre){
            ++n1;
            n2 = 0;
        }else{
            if(n1 + n2 > ans) ans = n1 + n2;
            n2 = n1 + 1;
            n1 = 0;
            pre = beads[i];
        }
    }
    if(n1 + n2 > ans) ans = n1 + n2;
    return ans;
}


int main(){
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int N;
    string beads;
    cin >> N;
    cin >> beads;
    int ans = solve(beads);
    cout << ans << endl;
    return 0;
}
