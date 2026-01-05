// Approach - 1 (using set)

// class Solution {
// public:
//     int repeatedNTimes(vector<int>& nums) {
//         unordered_set<int> st;
        
//         for (int &num : nums) {
//             if(st.count(num))
//                 return num;
            
//             st.insert(num);
//         }
        
//         return -1;
//     }
// };


// Approach -2


class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        for(int i=2; i< nums.size(); i++){
            if(nums[i] == nums[i-1] || nums[i-2])
                return nums[i];
        }
        return nums.back();
    }
};