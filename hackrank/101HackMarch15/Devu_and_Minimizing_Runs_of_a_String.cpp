#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        int n = str.size();
        vector<int> runs;
        int i = 0;
        while(i < n){
            int j = i + 1;
            while(j < n && str[j] == str[i]) ++j;
            runs.push_back(j-i);
            i = j;
        }
        int m = runs.size();
        if(m < 3){
            cout << m << endl;
            continue;
        }
        for(i = 1; i < m - 1; ++i){
            if(runs[i] == 1) break;
        }
        if(i < m - 1){
            cout << max(2 , m - 2) << endl;;
            continue;
        }
        if(runs[0] == 1 || runs[m-1] == 1){
            cout << m - 1 << endl;
            continue;
        }
        cout << m << endl;
    }
    return 0;
}

