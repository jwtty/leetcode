class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k >= n)
        {
        	int T_ik0 = 0, T_ik1 = INT_MIN;
        	for (int p: prices)
        	{
        		int T_ik0_old = T_ik0;
        		T_ik0 = max(T_ik0, T_ik1 + p);
        		T_ik1 = max(T_ik1, T_ik0_old - p);
        	}
        	return T_ik0;
        }

       vector<int> T_ik0(k + 1, 0);
       vector<int> T_ik1(k + 1, INT_MIN);
       for (int p: prices)
       {
       		for (int j = k; j > 0; --j)
       		{
       			T_ik0[j] = max(T_ik0[j], T_ik1[j] + p);
       			T_ik1[j] = max(T_ik1[j], T_ik0[j - 1] - p);
       		}
       }
       return T_ik0[k];
    }
};