// https://leetcode.com/problems/word-break/
// 3/19/21
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool dp[301] = {0}; // dp[i] is true if it is possible to construct s.substr(0, i) using words in wordDict
        // init
        dp[0] = 1; 
        for (int i = 1; i <= s.length(); i++) {
            for (string word : wordDict) {
                int length = word.length();
                if (length <= i && dp[i - length] != 0 && s.substr(i - length, length) == word) {
                    dp[i] = 1;
                } 
            }
        }
        return dp[s.length()];
        
    }
};