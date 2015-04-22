class Solution {
public:
    bool isHappy(int n) {
        if(n == 1) return true;
        if(n == 0) return false;
        unordered_set<int> history;
        history.insert(n);
        while(true){
            int sum = 0;
            while(n){
                int p = n % 10;
                sum += p * p;
                n /= 10;
            }
            if(sum == 1) return true;
            if(history.find(sum) != history.end()) return false;
            history.insert(sum);
            n = sum;
        }
    }
};
