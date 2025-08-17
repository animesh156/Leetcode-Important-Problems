class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts) return 1.0;

        vector<double> dp(n + maxPts + 1, 0.0);

        for (int score = k; score <= n; score++) {
            dp[score] = 1.0;
        }

        double windowSum = 0.0;
        for (int score = k; score < k + maxPts; score++) {
            windowSum += dp[score];
        }

        for (int score = k - 1; score >= 0; score--) {
            dp[score] = windowSum / maxPts;
            windowSum += dp[score] - dp[score + maxPts];
        }

        return dp[0];
    }
};
