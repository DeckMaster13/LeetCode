class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, left = 0, right = 0;
        map<char, int> posByChar;
        while (right < s.length()) {
            cout << "Left : " << s[left] << "," << left << endl;
            cout << "Right : " << s[right] << "," << right << endl;
            if (posByChar.find(s[right]) != posByChar.end() && posByChar[s[right]] >= left) {
                cout << "Found duplicate" << endl;
                left = posByChar[s[right]]+1;
            }

            
            posByChar[s[right]] = right;
            res = max(res, right-left+1);
            right++;
            
            cout << "Max : " << res << endl;
        }
        return res;
    }
};
