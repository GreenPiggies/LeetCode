// https://leetcode.com/problems/house-robber/
// 3/19/21
class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[nums.size()]; // dp[i] = amount of money you can get from houses 0 to i
        if (nums.size() == 1) return nums[0];
        // assuming size >= 2 now
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            // choose to or not to rob house i here
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};