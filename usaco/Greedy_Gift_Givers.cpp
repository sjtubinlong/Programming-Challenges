/*
ID: binlong3
PROG: gift1
LANG: C++
*/

# include <iostream>
# include <fstream>
# include <string>
# include <vector>
# include <map>
using namespace std;

int main(){
    string comet;
    string group;
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int N;
    fin >> N;
    map<string, int> users;
    vector<string> names;
    string name;
    for(int i = 0; i < N; ++i){
        fin >> name;
        users[name] = 0;
        names.push_back(name);
    }
    for(int i = 0; i < N; ++i){
        fin >> name;
        int total, num;
        fin >> total >> num;
        if(num == 0)
            users[name] += total;
        else{
            users[name] -= total;
            users[name] += total % num;
            for(int j = 0; j < num; ++j){
                fin >> name;
                users[name] += total / num;
            }
        }
    }
    for(int i = 0; i < N; ++i){
        fout << names[i] << " " << users[names[i]] << endl;
    }
    return 0;
}
