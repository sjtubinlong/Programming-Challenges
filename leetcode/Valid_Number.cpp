class Solution {
public:
    bool isNumber(const char *s) {
        if(NULL == s || s[0] == '\0') return false;
        int accept_digit = true;
        int accept_blank = true;
        int accept_dot = true;
        int accept_e = true;
        int accept_minus = true;
        int i = 0;
        while(s[i] == ' ') ++i;
        if(s[i] == '\0') return false;
        accept_blank = false;
        while(s[i] != '\0'){
            if(s[i] == ' '){
                if(accept_blank){
                    while(s[i] == ' ') ++i;
                    if(s[i] != '\0') return false;
                    continue;
                }else{
                    return false;
                }
            }else if(s[i] == 'e'){
                if(accept_e){
                    if(i == 0 || s[i+1] == '\0') return false;
                    if(s[i-1] < '0' || s[i-1] > '9'){
                        if(s[i-1] == '.' && i >= 2 && (s[i-2] < '0' || s[i-2] > '9')){
                            return false;
                        }
                        if(s[i-1] == ' ') return false;
                        if(s[i-1] == '+' || s[i-1] == '-') return false;
                    }
                    accept_e = false;
                    accept_blank = false;
                    accept_dot = false;
                    accept_minus = true;
                    accept_digit = true;
                }else{
                    return false;
                }
            }else if(s[i] == '+' || s[i] == '-'){
                if(accept_minus){
                    if(s[i+1] == '\0') return false;
                    if(accept_e){
                        accept_dot = true;
                    }else{
                        accept_dot = false;
                    }
                    accept_blank = false;
                    accept_minus = false;
                    accept_digit = true;
                }else{
                    return false;
                }
            }else if(s[i] == '.'){
                if(accept_dot){
                    if(s[i+1] == '\0' && !accept_blank) return false;
                    if(i == 0) accept_blank = false;
                    if(i == 0){
                        if(s[i+1] >= '0' && s[i+1] <= '9'){
                            accept_e = true;
                        }else{
                            return false;
                        }
                    }
                    else accept_blank = true;
                    accept_dot = false;
                    accept_minus = false;
                    accept_digit = true;
                }else{
                    return false;
                }
            }else if(s[i] >= '0' && s[i] <= '9'){
                if(accept_digit){
                    while(s[i] >= '0' && s[i] <= '9') ++i;
                    accept_blank = true;
                    accept_minus = false;
                    continue;
                }else{
                    return false;
                }
            }else return false;
            ++i;
        }
        return true;
    }
};