class Solution {
public:
    // long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    int K;
    int n;
    unordered_map<string, int> mp;
    
    long long solve(vector<int>& nums1, vector<int>& nums2, int sum, int min_el, int i, int count) {
        if(count == K) {
            return sum * min_el;
        }
         if(i >= n) {
            return 0;
        }
        
        string key = to_string(sum) + "_" + to_string(min_el) + "_" + to_string(i) + "_" + to_string(count);
        if(mp.find(key) != mp.end())
            return mp[key];
        
        int min_now = min(min_el, nums2[i]);
        
        long take_i = solve(nums1 , nums2 , sum + nums1[i] , min_now, i+1 , count+1);
        
        long not_take_i = solve(nums1 , nums2 , sum, min_el, i+1 , count);
        
        return mp[key] = max(take_i, not_take_i);
    }
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        K = k;
        n = nums1.size();
        mp.clear();
        
        return solve(nums1 , nums2 , 0 , INT_MAX , 0 , 0);
    
    }
};