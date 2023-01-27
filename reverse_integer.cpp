class Solution {
public:
    int reverse(int x) {
        bool negative = false;
        if (x < 0) {
            negative = true;
            if (x == INT_MIN) return 0;
            x = -x;
        }
        int y = 0;
        int old_y = 0;
        while (x > 0) {
            int digit = x%10;
            if (y > INT_MAX/10 || INT_MAX - y*10 < digit) {
                return 0;//OVERFLOW
            }
            y = y*10 + digit;
            old_y = y;
            x = x/10;
        }
        return negative ? -y : y;
    }
};
