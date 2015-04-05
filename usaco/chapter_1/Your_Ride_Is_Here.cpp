/*
ID: binlong3
PROG: ride
LANG: C++
*/

# include <iostream>
# include <fstream>
# include <string>
using namespace std;

int main(){
    string comet;
    string group;
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    fin >> comet;
    fin >> group;
    int r1 = 1;
    for(int i = 0; i < comet.size(); ++i){
        r1 *= (comet[i] - 'A' + 1) % 47;
        r1 %= 47;
    }
    int r2 = 1;
    for(int i = 0; i < group.size(); ++i){
        r2 *= (group[i] - 'A' + 1) % 47;
        r2 %= 47;
    }
    if(r1 == r2) fout << "GO" << endl;
    else fout << "STAY" << endl;
    return 0;
}
