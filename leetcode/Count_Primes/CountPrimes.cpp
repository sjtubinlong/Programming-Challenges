class Solution {
public:

    int countPrimes(int n) {
        vector<bool> h(n, true);
        int ans = 0;
        int upper = sqrt(n);
        for(int i = 2; i < n; ++i){
            if(!h[i]) continue;
            if(h[i]) ++ans;
            if(i > upper) continue;
            for(int j = i * i; j < n; j += i){
            // (2 to i - 1) * i should be processed before 
                h[j] = false;
            }
        }
        return ans;
    }
};
