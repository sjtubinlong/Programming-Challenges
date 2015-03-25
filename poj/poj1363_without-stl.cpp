# include <iostream>
using namespace std;

const int MAXN = 1001;

int main(){
    int rails[MAXN], top = -1;
    int n;
    while(cin >> n && n != 0){
        int i = 0, j = 1, train;
        while(i < n){
            cin >> train;
            if(train == 0) break;
            if(top >= 0 && rails[top] == train){
                --top;
            }else{
                while(j <= n && j != train){
                    rails[++top] = j++;
                }
                if(j <= n && j == train){
                    ++j;
                }
            }
            i = (i + 1) % n;
            if(i == 0){
                if(top == -1){
                    cout << "Yes" << endl;
                } else {
                    cout <<"No"<< endl;
                }
                j = 1;
                top = -1;
            }
        }
        cout << endl;
    }
    return 0;
}
