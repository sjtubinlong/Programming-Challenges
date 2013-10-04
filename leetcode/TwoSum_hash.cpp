class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = numbers.size();
        vector<int> result;
        map<int, int> hash;
        for( int i = 0; i != n; ++i ){
            hash[ numbers[i] ] = i+1;
        }
        for( int i = 0; i != n; ++i ){
            if( numbers[i] >= target ) continue;
            if( hash.find( target - numbers[i]) != hash.end() ){
                result.push_back( i + 1 );
                result.push_back( hash[ target - numbers[i] ]);
                break;
            }
        }
        return result;
    }
};