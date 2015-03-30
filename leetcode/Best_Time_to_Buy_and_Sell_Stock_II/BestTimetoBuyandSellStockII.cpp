class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = prices.size();
        if( n <= 1 ) return 0;
        int profit = 0;
        for( int i = 1; i < n; ++i ){
            if( prices[i]-prices[i-1] >0 ){
                profit += (prices[i]-prices[i-1]);
            }
        }
        return profit;
    }

};