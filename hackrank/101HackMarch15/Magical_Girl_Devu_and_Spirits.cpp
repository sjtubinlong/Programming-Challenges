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
        int n;
        cin >> n;
        int magic = 1;
        long long power = 0;
        int ans = -1;
        long long min_spirit = 0;
        for(int i = 0; i < n; ++i){
            long long spirit;
            cin >> spirit;
            if(spirit < min_spirit) min_spirit = spirit;

            if(spirit > 0) power += spirit;
            else{
                if(power + spirit < 0){
                    if(min_spirit < spirit){
                        if(magic){
                            --magic;
                            power = power + spirit - 2 * min_spirit;
                        }else{
                            if(ans == -1) ans = i;
                        }
                    }else{
                        if(magic){
                            --magic;
                            power -= spirit;
                        }else{
                            if(ans == -1) ans = i;
                        }
                    }
                }else{
                    power += spirit;
                }
            }
        }
        if(ans != -1) cout << ans+1 << endl;
        else cout << "She did it!" << endl;
    }
    return 0;
}


