class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int curVal = nums[0];
        int maxVal = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            curVal = max(nums[i], curVal + nums[i]);
            maxVal = max(curVal, maxVal);
        }
        return maxVal;
    }
};
