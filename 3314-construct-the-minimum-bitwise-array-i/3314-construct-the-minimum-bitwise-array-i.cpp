class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
         vector<int> ans;
        for (int x : nums) {
            int res = -1;
            for (int i = 0; i < x; i++) {
                if ( (i | (i + 1)) == x ) {
                    res = i;
                    break;
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};