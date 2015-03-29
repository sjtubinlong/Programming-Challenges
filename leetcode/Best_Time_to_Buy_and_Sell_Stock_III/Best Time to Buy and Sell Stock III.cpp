class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = prices.size();
        if( n <= 1 ) return 0;
        vector<int> profit( n, 0 );
        int min = 0, maxProfit = 0;
        for( int i = 0; i < n; ++i ){
            if( prices[i] < prices[min] ){
                min = i;
            }
            if( prices[i]-prices[min] > maxProfit ){
                maxProfit = prices[i]-prices[min];
            }
            profit[i] = maxProfit;
        }
        int max = n-1;
        maxProfit = 0;
        int totalMax = 0;
        for( int i = n-1; i >= 0; --i ){
            if( prices[i] > prices[max] ){
                max = i;
            }
            if( prices[max]-prices[i] > maxProfit ){
                maxProfit = prices[max]-prices[i];
            }
            if( profit[i] + maxProfit > totalMax ){
                totalMax = profit[i] + maxProfit;
            }
        }
        return totalMax;
    }
};