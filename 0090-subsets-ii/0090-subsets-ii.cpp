class Solution {
public:
// Fraz

    void help(int i, vector<int>&nums,vector<int>&temp, vector<vector<int>>&ans,bool pre){
        if(i==nums.size()){
            ans.push_back(temp);
        }
        else{
            help(i+1,nums,temp,ans,false);
            if(i>0&&nums[i]==nums[i-1]&&(!pre))
                return;
            
            temp.push_back(nums[i]);
            help(i+1,nums,temp,ans,true);

            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int>temp;
        help(0,nums,temp,ans,false);
        return ans;
    }
};