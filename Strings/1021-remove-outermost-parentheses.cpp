// TC: O(N)
// SC: O(N)

class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string res;
        for (int i=0; i<s.size(); i++) {
            if(s[i] == '(' && count++ > 0) {
                res.push_back(s[i]);
            }

            if(s[i] == ')' && count-- > 1) {
                res.push_back(s[i]);
            }
        }

        return res;
    }
};
