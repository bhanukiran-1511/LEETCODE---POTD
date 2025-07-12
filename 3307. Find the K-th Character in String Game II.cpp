class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        // 1. Find minimal n = 2^m >= k (effective length after m ops)
        long long n = 1;
        int m = 0;
        while (n < k) {
            n <<= 1;
            ++m;
        }

        // 2. Backtrack from operation m down to 1
        int shift = 0;
        while (n > 1) {
            long long half = n >> 1;
            if (k > half) {
                k -= half;
                shift += operations[m - 1];
            }
            n = half;
            --m;
        }

        // 3. Map total shift to resulting character
        return char('a' + (shift % 26));
    }
};