class Solution {
public:
    int romanToInt(string s) {
        map<char, int> symbolToValue = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        if (s.size() == 0) return 0;
        if (s.size() == 1) return symbolToValue[s[0]];
        
        int res = 0;
        auto letter0 = s.begin();
        auto letter1 = letter0 + 1;
        while (letter0 != s.end()) {
            const auto& value0 = symbolToValue[*letter0];
            if (letter1 == s.end()) {
                res += value0;
                return res;
            }
            const auto& value1 = symbolToValue[*letter1];
            if (value0 >= value1) {
                res += value0;
                letter0++;
                letter1++;
            }
            else {
                res += value1 - value0;
                letter0 += 2;
                letter1 += 2;
            }
        }
        return res;
    }
};
