class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> me;
        me.push_back(*(prices.end()-1));
        for (auto it=prices.rbegin()+1; it!=prices.rend();it++){
            me.push_back(max(*it,*(me.end()-1))); 
        }
        int ans=0;
        reverse(me.begin(),me.end());
        for (int i=0;i<prices.size();i++){
            ans=max(ans,me[i]-prices[i]);
        }
        return ans;
    }
};