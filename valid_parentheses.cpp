class Solution {
public:
    enum Symbol {
        None,
        Bracket,
        Parenthese,
        Accolade
    };
    template <char openSymbol, char closeSymbol, Symbol symbol>
    bool checkSymbol(int& openCounter, int& closeCounter, char c, std::stack<Symbol>& lastSymbols) {
        if (c == openSymbol) {
            openCounter++;
            lastSymbols.push(symbol);
        } else if (c == closeSymbol) {
            closeCounter++;
            if (lastSymbols.top() != symbol) return false;
            lastSymbols.pop();
        }
        return openCounter >= closeCounter;
    }
    
    bool isValid(string s) {
        int openBracket = 0, closeBracket = 0;
        int openParenthese = 0, closeParenthese = 0;
        int openAccolade = 0, closeAccolade = 0;
        
        std::stack<Symbol> lastSymbols;
        lastSymbols.push(None); 
        for (char c : s) {
            if (  !checkSymbol<'[', ']', Bracket>(openBracket, closeBracket, c, lastSymbols) 
               || !checkSymbol<'(', ')', Parenthese>(openParenthese, closeParenthese, c, lastSymbols)
               || !checkSymbol<'{', '}', Accolade>(openAccolade, closeAccolade, c, lastSymbols)) return false;
        }
        if (   openBracket > closeBracket 
            || openParenthese > closeParenthese
            || openAccolade > closeAccolade) return false;
        return true;
    }
};
