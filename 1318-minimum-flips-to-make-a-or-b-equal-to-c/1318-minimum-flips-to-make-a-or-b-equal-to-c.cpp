class Solution {
public:
    int minFlips(int a, int b, int c) {
        int result = ((a|b) ^ c);

        int result1 = (a&b);
        int result2 = (result1 & result);

        return __builtin_popcount(result) + __builtin_popcount(result2);
    }
};