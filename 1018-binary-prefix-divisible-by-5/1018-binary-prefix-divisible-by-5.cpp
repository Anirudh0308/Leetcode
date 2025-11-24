class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> result(n);

        int remain = 0;

        for(int i = 0; i < n; i++) {
            remain = (remain*2 + nums[i]) % 5;

            result[i] = (remain == 0);
        }
        return result;

    }
};