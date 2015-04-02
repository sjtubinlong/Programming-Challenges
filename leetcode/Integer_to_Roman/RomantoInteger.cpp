// the Roman seven symbols:
// I(1), V(5), X(10), L(50), C(100), D(500), M(1000)
// the Roman rules:
// the numeral I can be placed before V and X to make 4 units (IV) and 9 units (IX) respectively
// X can be placed before L and C to make 40 (XL) and 90 (XC) respectively
// C can be placed before D and M to make 400 (CD) and 900 (CM) according to the same pattern

class Solution {
public:
    string intToRoman(int num) {
        string ans;
        int base[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string roma[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int i = 12;
        while(num){
            if(num >= base[i]){
                if(roma[i].size() == 1){
                    for(int j = 0; j < num / base[i]; ++j) ans += roma[i];
                    num %= base[i];
                }else{
                    ans += roma[i];
                    num -= base[i];
                }
            }
            --i;
        }
        return ans;
    }
};
