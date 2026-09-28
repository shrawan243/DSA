class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
       int maxp=0;
       int min=INT_MAX;
       for(int i=0;i<prices.size();i++)
    {
        if(min>prices[i])
        {
            min=prices[i];
        }
      else if(prices[i]-min>maxp)
       {
        maxp=prices[i]-min;
       }

    }
    return maxp;
    }
};