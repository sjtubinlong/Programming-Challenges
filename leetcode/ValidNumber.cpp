class Solution {
public:
    bool isNumber(const char *s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        //典型的确定性自动机问题
    	enum charType{
    		INVALID = 0,
    		DIGIT,
    		SIGNED,
    		DOT,
    		SPACE,
    		EXP,
    	};
    	if( NULL==s || s[0]=='\0' ) return false;
    	int stateTable[9][6] = {
    		{-1, 1, 3, 2, 0, -1},
    		{-1, 1, -1, 4, 8, 5},
    		{-1, 4, -1, -1, -1, -1},
    		{-1, 1, -1, 2, -1, -1},
    		{-1, 4, -1, -1, 8, 5},
    		{-1, 7, 6, -1,-1,-1},
    		{-1, 7, -1, -1, -1, -1 },
    		{-1, 7, -1, -1, 8, -1},
    		{-1, -1, -1, -1, 8, -1}
    	};
    	int state = 0;
    	for( int i = 0; s[i] != '\0'; ++i ){
    		charType ct = INVALID;
    		if( s[i] >= '0' && s[i] <= '9' )
    			ct = DIGIT;
    		if( s[i] == '+' || s[i] == '-' )
    			ct = SIGNED;
    		if( s[i] == '.' )
    			ct = DOT;
    		if( s[i] == 'E' || s[i]=='e' )
    			ct = EXP;
    		if( s[i]==' ' )
    			ct = SPACE;
    		state = stateTable[state][ct];
    		if( state == -1 ) return false;
    	}
    	if( state==1 || state==4 || state==7 || state==8 ) return true;
    	return false;
    }
};