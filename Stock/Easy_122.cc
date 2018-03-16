class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int T_ik0 = 0, T_ik1 = INT_MIN;
        for (int p: prices)
        {
        	int T_ik0_old = T_ik0;
        	T_ik0 = max(T_ik0, T_ik1 + p);
        	T_ik1 = max(T_ik1, T_ik0_old - p);
        }
        return T_ik0;
    }
};