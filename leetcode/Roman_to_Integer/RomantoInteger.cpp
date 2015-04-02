class Solution {
public:
    int romanToInt(string s) {
        int base[26];
        base['I' - 'A'] = 1;
        base['V' - 'A'] = 5;
        base['X' - 'A'] = 10;
        base['L' - 'A'] = 50;
        base['C' - 'A'] = 100;
        base['D' - 'A'] = 500;
        base['M' - 'A'] = 1000;
        int n = s.size();
        int ans = 0;
        for(int i = n-1; i >= 0; --i){
            if(i+1 >= n || base[s[i] - 'A'] >= base[s[i+1] - 'A']){
                ans += base[s[i] - 'A'];
            }else{
                ans -= base[s[i] - 'A'];
            }
        }
        return ans;
    }
};
