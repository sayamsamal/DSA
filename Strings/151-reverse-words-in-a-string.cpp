// TC: O(N)
// SC: O(1) : in-place

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end()); // first reverse the whole array

        int i = 0;        // iter
        int n = s.size(); // length
        int l = 0, r = 0; // two pointers

        while (i < n) {
            while (s[i] == ' ') i++; // iterate to the first non-whitespace character

            while (i < n && s[i] != ' ') { // read the first word in reverse
                s[r++] = s[i++];           // store it in-place in s
            }

            if (l < r) {
                reverse(s.begin() + l, s.begin() + r); // reverse the word back into correct order
                if (r == n) break;
                s[r++] = ' '; // if r != n, add a space after the word
                l = r;
            }
        }

        if (r > 0 && s[r - 1] == ' ') r--;     // if we added a space after the last word we delete it
        s.resize(r); // then resize the array to final (without leading or trailing spaces)

        return s;
    }
};
