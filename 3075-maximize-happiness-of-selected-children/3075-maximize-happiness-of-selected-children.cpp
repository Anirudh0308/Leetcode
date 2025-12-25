class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        long long res = 0;
        int count = 0;
        for (int i = happiness.size() - 1; i >= happiness.size() - k; --i) {
            if (happiness[i] - count > 0) {
                res += (long long)(happiness[i] - count);
            }
            count++;
        }
        return res;
    }
};