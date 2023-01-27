class Solution {
public:
    int climbStairs(int n) {
        if (n < 0) return 0;
        if (n <= 1) return 1;
        if (n <= 2) return 2;
        
        //starts at 3
        int res_n = 0;
        int res_n1 = 2;
        int res_n2 = 1;
        for (int i = 2; i < n; i++) {
            res_n = res_n1 + res_n2;
            res_n2 = res_n1;
            res_n1 = res_n;
        }
        return res_n;
    }
};
