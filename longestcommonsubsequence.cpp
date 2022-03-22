// https://leetcode.com/problems/longest-common-subsequence/submissions/
// 3/19/21
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1001][1001]; // dp[i][j] = length of longest common subsequence of text1.substr(0, i) and text2.substr(0, j)
        dp[0][0] = (text1[0] == text2[0]);
        for (int i = 1; i < text2.length(); i++) {
            dp[0][i] = dp[0][i - 1] | (text1[0] == text2[i]);
        }
        for (int i = 1; i < text1.length(); i++) {
            dp[i][0] = dp[i - 1][0] | (text1[i] == text2[0]);
        }
        
        for (int i = 1; i < text1.length(); i++) {
            for (int j = 1; j < text2.length(); j++) {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                if (text1[i] == text2[j]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
        return dp[text1.length() - 1][text2.length() - 1];
    }
};