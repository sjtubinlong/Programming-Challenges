#include <iostream>
#include <string>

using namespace std;

// states of the DFA
enum STATE {
    REJECT = 0,
    Q0 = 1,
    Q1,
    Q2,
    Q3,
    Q4,
    Q5,
    Q6,
    Q7,
    Q8,
    Q9
};

// symbols of the DFA
enum SYMBOL {
    BADSYMBOL = 0,
    DIGIT = 1,
    SIGNED,
    DOT,
    EXPON,
    SPACE
};

const int STATE_NUM = 11;
const int SYMBOL_NUM = 6;

SYMBOL symbol_check(char input){
    if(input >= '0' && input <= '9'){
        return DIGIT;
    }
    if(input == '+' || input == '-'){
        return SIGNED;
    }
    if(input == '.'){
        return DOT;
    }
    if(input == 'e' || input == 'E'){
        return EXPON;
    }
    if(input == ' '){
        return SPACE;
    }
    return BADSYMBOL;
}

// Transition Function of the DFA
STATE transit(STATE cur_state, char input){
    SYMBOL cur_symbol = symbol_check(input);
    if(cur_symbol == BADSYMBOL) return REJECT;
    STATE state_map[11][6] = {
        {REJECT, REJECT, REJECT, REJECT, REJECT, REJECT},
        {REJECT, Q2, Q1, Q3, REJECT, Q0},
        {REJECT, Q2, REJECT, Q3, REJECT, REJECT},
        {REJECT, Q2, REJECT, Q4, Q6, Q9},
        {REJECT, Q5, REJECT, REJECT, REJECT, REJECT},
        {REJECT, Q5, REJECT, REJECT, Q6, Q9},
        {REJECT, Q5, REJECT, REJECT, Q6, Q9},
        {REJECT, Q8, Q7, REJECT, REJECT, REJECT},
        {REJECT, Q8, REJECT, REJECT, REJECT, REJECT},
        {REJECT, Q8, REJECT, REJECT, REJECT, Q9},
        {REJECT, REJECT, REJECT, REJECT, REJECT, Q9}
    };
    return state_map[cur_state][cur_symbol];
}

bool validate(const string& str){
    STATE cur_state = Q0;
    for(int i = 0; i < str.size(); ++i){
        cur_state = transit(cur_state, str[i]);
        if(cur_state == REJECT) break;
    }
    if(cur_state == Q2 || cur_state == Q4 || cur_state == Q5 || cur_state == Q8 || cur_state == Q9){
        return true;
    }
    return false;
}

int main(){
    string str;
    while(cin >> str){
        cout << (validate(str) ? "Accept" : "Reject") <<endl;
    }
    return 0;
}
