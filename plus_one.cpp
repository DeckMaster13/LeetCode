class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool propagating = true;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (!propagating) return digits;
            if (digits[i] == 9) {
                digits[i] = 0;
                propagating = true;
                if (i == 0) {
                    digits.insert(digits.begin(), 1);
                }
            } else {
                digits[i] = digits[i]+1;
                propagating = false;
            }
        }
        return digits;
    }
};
