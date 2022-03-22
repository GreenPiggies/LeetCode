// https://leetcode.com/problems/combination-sum-iv/solution/
// 3/19/21
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unsigned int dp[1001] = {0}; // target[i] = number of possibilities that add up to i
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (num <= i) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};