/* Fisher–Yates shuffle Algorithm 
 * To shuffle an array a of n elements (indices 0..n-1):
 *  for i from n - 1 downto 1 do
 *       j = random integer with 0 <= j <= i
 *       exchange a[j] and a[i]
 */

class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res(nums);
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            int j = rand() % (i + 1);
            swap(res[i], res[j]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */