vector<string> addNewLettersToRes(const vector<string>& res, const vector<string>& newLetters) {
    vector<string> newRes;
    for (const auto& oldLetter : res) 
        for (const auto& newLetter : newLetters)
            newRes.push_back(oldLetter+newLetter);
    return newRes;
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, vector<string>> digitsToLetters {
            {'1', {""}},
            {'2', {"a", "b", "c"}},
            {'3', {"d", "e", "f"}},
            {'4', {"g", "h", "i"}},
            {'5', {"j", "k", "l"}},
            {'6', {"m", "n", "o"}},
            {'7', {"p", "q", "r", "s"}},
            {'8', {"t", "u", "v"}},
            {'9', {"w", "x", "y", "z"}}
        };
        
        if (digits.size() == 0) return vector<string>();
            
        vector<string> res = digitsToLetters.at(digits[0]);
        for (auto digit : digits.substr(1,digits.size())) {
            const auto& newLetters = digitsToLetters.at(digit);
            res = addNewLettersToRes(res, newLetters);
        }
        return res;
    }
};
