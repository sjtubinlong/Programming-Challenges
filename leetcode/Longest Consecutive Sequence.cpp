class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = num.size();
        if( n < 2) return n;
        unordered_set< int > keys;
        unordered_set< int > visited;
        for( int i = 0; i < n; ++i ) {
            keys.insert( num[i] );
        }
        int maxLen = 1;
        for( int i = 0; i < n; ++i ){
            if( visited.find(num[i])!=visited.end() ){
                continue;
            }
            visited.insert( num[i] );
            int low = num[i];
            int high = num[i];
            while(true){
                if( keys.find(--low )==keys.end() ){
                    ++low;
                    break;
                }
                visited.insert( low );
            }
            //High bound
            while(true){
                if( keys.find(++high )==keys.end() ){
                    --high;
                    break;
                }
                visited.insert( high );
            }
            int curLen = high - low + 1;
            if( curLen > maxLen ){
                maxLen = curLen;
            }
        }
        return maxLen;
    }
};