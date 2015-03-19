class Solution {
public:
    static void nextPermutation(vector<int> &num) {
        //next_permutation(num.begin(), num.end());
        if(num.size() < 2) return;
        int partion = -1;
        for(int i = num.size() - 1; i > 0; --i){
            if(num[i-1] < num[i]){
                partion = i - 1;
                break;
            }
        }
        int change = -1;
        if(partion != -1){
            for(int i = num.size() - 1; i > 0; --i){
                if(i != partion && num[i] > num[partion]){
                    change = i;
                    break;
                }
            }
        }
        if(change != -1){
            int c = num[partion];
            num[partion] = num[change];
            num[change] = c;
        }
        reverse(num.begin() + partion + 1, num.end());
    }
};