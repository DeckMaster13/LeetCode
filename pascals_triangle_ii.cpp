class Solution {
public:
    vector<int> getRow(int rowIndex) {
        auto numRows = rowIndex+1;
        
        vector<vector<int>> v;        
        vector<int> previousRow = {1};
        v.push_back(previousRow);
        
        if (numRows == 1) return v.back();
        
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
        return v.back();

    }
};
