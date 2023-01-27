class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto it1 = nums.begin();
        auto it2 = nums.begin()+1;
        auto pos1 = 0;
        auto pos2 = 1;
        cout << "pos1 : " << pos1 << "/pos2 :" << pos2 << endl;
        while (*it1 + *it2 != target) {
            cout << "found : " << *it1 << " & " << *it2 << endl;
            pos2++;
            it2++;
            if (it2 == nums.end()) {
                it1++;
                pos1++;
                it2 = it1 + 1;
                pos2 = pos1 + 1;
            }
        }
        return vector<int>{pos1,pos2};
    }
};
