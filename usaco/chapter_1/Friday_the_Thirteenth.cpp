/*
ID: binlong3
PROG: friday
LANG: C++
*/

# include <iostream>
# include <fstream>
# include <string>
using namespace std;

int is_leap_year(int year){
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        return 1;
    }
    return 0;
}

int main(){
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    int N;
    fin >> N;
    int days[2][12] = {
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };
    int ans[7] = {0, 0, 0, 0, 0, 0, 0};
    int d = 0;
    for(int i = 0; i < N; ++i){
        int year = 1900 + i;
        int leap = is_leap_year(year);
        for(int j = 0; j < 12; ++j){
            int count = 13;
            for(int k = 0; k < j; ++k){
                count += days[leap][k];
            }
            ans[(d+count) % 7]++;
        }
        d += (leap ? 366 : 365);
    }
    int i = 6;
    for(i = 6; i < 12; ++i){
        fout << ans[i%7] << " ";
    }
    fout << ans[i%7] << endl;
    return 0;
}
