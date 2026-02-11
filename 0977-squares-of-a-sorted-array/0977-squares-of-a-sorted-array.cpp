class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int left =0;
        int right = n - 1;
        int index = n - 1;

        while(left <= right){
            int leftsqr = nums[left] * nums[left];
            int rightsqr = nums[right] * nums[right];

            if(leftsqr < rightsqr){
                result[index] = rightsqr;
                right --;
            }else{
                result[index] = leftsqr;
                left ++;
            }
            index --;
        }
        return result;
    }
};