class Solution {
public:
    
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];
        
        bool seek = true;
        string firstString = strs.back();
        if (firstString.empty()) return "";
        int i = 0;
        strs.pop_back();
        
        string res;
        while (seek) {
            for (const auto& str : strs) {
                if (i > str.size() || str[i] != firstString[i]) {
                    seek = false;
                    break;
                }
            }
            if (seek) {
                res += firstString[i];
                i++;
                if (i >= firstString.size()) return res;
            }
        }
        return res;
    }
    
};
