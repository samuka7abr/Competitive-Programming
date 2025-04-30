class Solution {
    public:
        int hammingWeight(int n) {
            int uns = __builtin_popcount(n);
            return uns;
        }
    };


