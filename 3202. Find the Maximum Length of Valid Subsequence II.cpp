class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        // Initialize a 2D DP table where:
        // dp[a][b] = length of the longest valid subsequence ending in a pair of remainders (a, b)
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int ans = 0; // To track the maximum length found

        // Iterate through each number in the input array
        for (int num : nums) {
            int curr = num % k; // Get the remainder of the current number modulo k

            // Try to extend all possible subsequences that end with some previous remainder (prev)
            for (int prev = 0; prev < k; ++prev) {
                // Update dp[prev][curr] based on dp[curr][prev]
                // Why? Because if there was a valid subsequence ending with (curr, prev),
                // and we now add 'num' (with remainder 'curr'), we create a new pair (prev, curr)
                dp[prev][curr] = dp[curr][prev] + 1;

                // Update the global maximum length
                ans = max(ans, dp[prev][curr]);
            }
        }

        // Return the maximum length found
        return ans;
    }
};
