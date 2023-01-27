class Solution {
public:
    bool isPalindrome(int x0) {
        if (x0 < 0) return false;
        long x = x0;
        long y = 0;
        vector<long> v;
        while (x > 0) {
            int digit = x % 10;
            v.push_back(digit);
            x = (x - digit)/10;
        }
        for (int i = 0; i < v.size(); i++) y += pow(10,v.size() - i - 1) * v[i];
        return x0 == y;
    }
};
