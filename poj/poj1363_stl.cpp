# include <iostream>
# include <stack>
using namespace std;

int main(){
    int n;
    while(cin >> n && n != 0){
        stack<int> rails;
        int i = 0, j = 1, train;
        while(i < n){
            cin >> train;
            if(train == 0) break;
            if(!rails.empty() && rails.top() == train){
                rails.pop();
            }else{
                while(j <= n && j != train){
                    rails.push(j++);
                }
                if(j <= n && j == train){
                    ++j;
                }
            }
            i = (i + 1) % n;
            if(i == 0){
                if(rails.empty()){
                    cout << "Yes" << endl;
                } else {
                    cout <<"No"<< endl;
                }
                j = 1;
                while(!rails.empty()) rails.pop();
            }
        }
        cout << endl;
    }
    return 0;
}
