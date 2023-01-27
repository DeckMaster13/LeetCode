class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        if (numRows == 0) return v;
        
        vector<int> previousRow = {1};
        v.push_back(previousRow);
        if (numRows == 1) return v;
        
        for (int i = 2; i <= numRows; i++) {
            vector<int> row;
            row.push_back(1);
            for (int index = 0; index < previousRow.size() - 1; index++) {
                row.push_back(previousRow[index] + previousRow[index+1]);
            }
            row.push_back(1);
            v.push_back(row);
            previousRow = v.back();
        }
        return v;
    }
};
