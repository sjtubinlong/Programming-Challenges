class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = numbers.size();
        vector<int> result;
        for( int i = 0; i != n; ++i ){
            if( numbers[i] >= target ){
                continue;
            }
            for( int j = i+1; j != n; ++j ){
                if( numbers[i] + numbers[j] == target ){
                    result.push_back( i + 1 );
                    result.push_back( j + 1 );
                }
            }
        }
        return result;
    }
};