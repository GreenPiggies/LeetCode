class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int m1 = rob2(nums, 0, nums.size() - 2);
        int m2 = rob2(nums, 1, nums.size() - 1);
        return max(m1, m2);
    }
    
    int rob2(vector<int>& nums, int start, int end) {
        int t1 = 0;
        int t2 = 0;
        for (int i = start; i <= end; i++) {
            int temp = t1;
            int current = nums[i];
            t1 = max(current + t2, t1);
            t2 = temp;
        }
        return t1;
    }
};