// https://leetcode.com/problems/jump-game/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastGoodPos = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i + nums[i] >= lastGoodPos)
                lastGoodPos = i;
        }
        return lastGoodPos == 0;
    }
};