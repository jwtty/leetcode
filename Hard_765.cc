// Cyclic Swapping
// instead of i = row[i], we need i = ptn[pos[ptn[row[i]]]]

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int res = 0, n = row.size();
        
        vector<int> ptn(n, 0);
        vector<int> pos(n, 0);
        
        for (int i = 0; i < n; ++i)
        {
            ptn[i] = (i % 2 == 0 ? i + 1 : i - 1);
            pos[row[i]] = i;
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = ptn[pos[ptn[row[i]]]]; i != j; j = ptn[pos[ptn[row[i]]]])
            {
                //cout << i << " " << row[i] << " " << ptn[row[i]] << " " << pos[ptn[row[i]]] << " " << j << endl;
                swap(row[i], row[j]);
                swap(pos[row[i]], pos[row[j]]);
                ++res;
            }
        }
        
        return res;
    }
};