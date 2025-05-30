// class Solution {
// public:
//     vector<vector<int>> combinationSum3(int k, int n) {
        
//     }
// };


class Solution {
private:
    void generate(int i, vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& sub, int curr,int k) {
        if(curr == target) {
            if(sub.size()==k) res.push_back(sub);
            return;
        }
        if(curr > target || i == candidates.size()) {
            return;
        }

        for(int j = i; j < candidates.size(); ++j) {
            if(j > i && candidates[j] == candidates[j - 1]) continue;  
            sub.push_back(candidates[j]);
            generate(j + 1, candidates, target, res, sub, curr + candidates[j],k);
            sub.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums;
        for(int i=1;i<10;i++){
            nums.push_back(i);
        }
        vector<vector<int>> res;
        vector<int> sub;
        generate(0, nums, n, res, sub, 0,k);
        return res;
    }
};