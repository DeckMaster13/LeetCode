class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int m = 0;
        int M = nums.size()-1;
        
        while (m <= M) {
            int mid = m + (M - m)/2;
            if (target > nums[mid]) {
                m = mid + 1;
            } else {
                M = mid - 1;
            }
        }
        return m;
    }
};
