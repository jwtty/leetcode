class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result(2, 0);
        int diff = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            diff ^= nums[i];
        }
        // Get the last bit set
        diff &= -diff;
        // The two numbers must fall into two groups
        for (int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] & diff)
                result[0] ^= nums[i];
            else
                result[1] ^= nums[i];
        }
        return result;
    }
};