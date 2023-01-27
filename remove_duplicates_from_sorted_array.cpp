class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        auto ref = -100000000;
        size_t k = 0;
        for (auto num : nums) {
            if (num == ref) continue;
            ref = num;
            nums[k] = ref;
            k++;
        }
        return k;
    }
};

//Other option
/*
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};
*/
