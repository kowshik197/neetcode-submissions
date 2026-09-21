class Solution {
public:
    int maxProfit(vector<int>& prices) {
      
        int size=prices.size();
        int maxProfitSoFar=0;
        int minPriceSoFar=prices[0];

        for(int i=1;i<size;i++){

         minPriceSoFar = min(minPriceSoFar, prices[i]);
         maxProfitSoFar = max(maxProfitSoFar, prices[i] - minPriceSoFar);


        }
return maxProfitSoFar;
        
    }
};