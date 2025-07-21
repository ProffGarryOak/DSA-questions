class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> me(n);

        
        me[n - 1] = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            me[i] = max(prices[i], me[i + 1]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, me[i] - prices[i]);
        }

        return ans;
    }
};