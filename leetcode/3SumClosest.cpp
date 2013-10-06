class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort( num.begin(), num.end() );
        int n = num.size();
        int minD = abs(target - num[0]-num[1]-num[2]);
        int minSum = num[0]+num[1]+num[2];
        for( int i = 0; i < n; ++i ){
            int j = i+1;
            int k = n-1;
            while( j < k ){
                int sum = num[i]+num[j]+num[k];
                if( abs(target-sum) < minD ) {
                    minD = abs(target-sum);
                    minSum = sum;
                }
                if( sum==target ) return target;
                if( sum > target ) --k;
                if( sum < target ) ++j;
            }
        }
        return minSum;
    }
};