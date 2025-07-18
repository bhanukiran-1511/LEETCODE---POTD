class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size();  // Total number of elements, must be 3n
        int n = N / 3;        // n-size for each group

        // Arrays to store the minimum left sum and maximum right sum at each index
        vector<long long> leftmin(N, 0);
        vector<long long> rightmax(N, 0);

        // Max-heap to maintain the n smallest elements sum on the left
        priority_queue<int> maxheap;
        long long leftsum = 0;

        // Process the first 2n elements to find the smallest possible sum by picking n elements
        for (int i = 0; i < 2 * n; i++) {
            leftsum += nums[i];
            maxheap.push(nums[i]);
            // Keep only the n smallest elements in maxheap
            if (maxheap.size() > n) {
                leftsum -= maxheap.top(); // Remove largest to keep n elements
                maxheap.pop();
            }
            leftmin[i] = leftsum; // Store the sum after keeping n smallest so far
        }

        // Min-heap to maintain the n largest elements sum on the right
        priority_queue<int, vector<int>, greater<int>> minheap;
        long long rightsum = 0;

        // Process the last 2n elements in reverse to find the largest possible sum by picking n elements
        for (int i = N - 1; i >= n; i--) {
            rightsum += nums[i];
            minheap.push(nums[i]);
            // Keep only the n largest elements in minheap
            if (minheap.size() > n) {
                rightsum -= minheap.top(); // Remove smallest to keep n elements
                minheap.pop();
            }
            rightmax[i] = rightsum; // Store the sum after keeping n largest so far
        }

        // Find the minimum difference between leftmin and rightmax
        long long minans = LLONG_MAX;
        // Consider boundaries between left and right partitions
        for (int i = n - 1; i < 2 * n; i++) {
            minans = min(minans, leftmin[i] - rightmax[i + 1]);
        }

        return minans; // Return the smallest difference found
    }
};
