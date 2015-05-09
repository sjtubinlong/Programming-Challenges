/*
1. remove extra spaces in-place using method similar to partion in quicksort
2. reverse a word (if exist) while find a space or eos
3. add a sigle space while walk into next word

Actually, its a simple state machine

*/
void reverse(char* s, int i, int j){
    while(i < j){
        s[i] = s[i] + s[j];
        s[j] = s[i] - s[j];
        s[i] = s[i] - s[j];
        ++i;
        --j;
    }
}

void reverseWords(char *s) {
    if(s == NULL || s[0] == '\0') return;
    int i = 0, j = -1, k = -1;
    
    bool first_space = true;
    bool first_word = true;
    
    while(true){
        if(s[i] != ' ' && s[i] != '\0'){
            if(!first_word && k == -1) s[++j] = ' ';
            s[++j] = s[i];
            first_space = true;
            first_word = false;
            if(k == -1) k = j;
        }else if(first_space){
            if(k != -1){
                reverse(s, k, j);
                k = -1;
            }
            first_space = false;
        }
        if(s[i] == '\0') break;
        ++i;
    }
    s[++j] = '\0';
    reverse(s, 0, j-1);
}

