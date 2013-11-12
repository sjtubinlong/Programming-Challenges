class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = prices.size();
        if( n <= 1 ) return 0;
        int min = prices[0];
        int profit = 0;
        for( int i = 0; i < n; ++i ){
            if( prices[i] < min ){
                min = prices[i];
            }
            if( prices[i]-min > profit ){
                profit = prices[i]-min;
            }
        }
        return profit;
    }
};