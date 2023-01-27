class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int size = 0;
        int i = s.size()-1;
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        while ( i >= 0 && s[i] != ' ') {
            size += 1;
            i--;
        }
        return size;
    }
};
