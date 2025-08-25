class Solution {
public:
    int longestValidParentheses(string s) {
        int close = 0, open = 0, ans = 0; // counters for ')' , '(', and max length

        // Pass 1: Left to Right
        for(char ch : s){
            if(ch == '('){ 
                open++; // increment open for '('
            }
            else{
                close++; // increment close for ')'
            }
            if(open == close){
                // valid substring found
                ans = max(ans, 2 * open);
            }
            else if(close > open){
                // invalid state, reset counters
                close = 0;
                open = 0;
            }
        }

        // Reset counters for second pass
        open = 0, close = 0;

        // Pass 2: Right to Left
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '(') open++;
            else close++;
            
            if(open == close){
                // valid substring found
                ans = max(ans, 2 * open);
            } else if(open > close){
                // invalid state, reset counters
                close = 0;
                open = 0;
            }
        }

        return ans;
    }

};