class Solution {
public:
    // RECURSIVE: timeout for big values
    /*
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        if (m < 1 || n < 1) return 0;
        return uniquePaths(m-1, n) + uniquePaths(m, n-1); 
    }
    */
    // DYNAMIC PROGRAMMING
    int uniquePaths(int m, int n) {
        vector<vector<int>> res(n, vector<int>(m, 1)); 
        //res[0][0] = 0;
        //res[1][0] = res[0][1] = 1;
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                res[i][j] = res[i-1][j] + res[i][j-1];
            } 
        }
        return res[n-1][m-1];//starts at 0 not at 1 
    }
    // THINKING: too big for big values
    /*
    int fact(int j) {
        return j == 1 ? 1 : j*fact(j-1);
    }    
    
    int uniquePaths(int m, int n) {
        return fact(m+n-2)/(fact(m-1)*fact(n-1));
    }
    */
};
