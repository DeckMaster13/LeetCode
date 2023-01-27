class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[j] == nums[i]) return true;
            }
        }
        return false;
        */
        std::unordered_set<int> s;
        for (auto num : nums) {
            if (s.count(num)) return true;
            else s.insert(num);
        }
        return s.size() != nums.size();
    }
};
