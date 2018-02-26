class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(M.empty())
            return 0;
        int n = M.size();
        vector<int> prev(n, 0);
        for (int i = 0; i < n; ++i)
        {
            prev[i] = i;
        }
        int groups = n;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if(M[i][j])
                {
                    int pre1 = find(prev, i);
                    int pre2 = find(prev, j);
                    if(pre1 != pre2)
                        prev[pre1] = prev[pre2], groups--;
                }
            }
        }
        return groups;
    }
    
    int find(vector<int>& prev, int x)
    {
        int i = x;
        while(prev[i] != i)
            i = prev[i];
        int j = x, k;
        while(prev[j] != j)
        {
            k = prev[j];
            prev[j] = i;
            j = k;
        }
        return i;
    }
};