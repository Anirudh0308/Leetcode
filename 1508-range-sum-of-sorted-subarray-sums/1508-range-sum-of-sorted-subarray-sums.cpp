class Solution {
public:

    typedef pair<int, int> P;
    int M = 1e9+7;

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<P, vector<P>, greater<P>> pq;
        
        //pair<sum, i> -> (subarray sum, till index i)
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        int result = 0;

        for (int i = 1; i <= right; i++) {
            auto p = pq.top();
            pq.pop();

            // If the current index is greater than or equal to left, add the
            // value to the answer.
            if (i >= left) {
                result = (result + p.first) % M;
            }

            // If index is less than the last index, increment it and add its
            // value
            if (p.second < n - 1) {
                p.second++;
                p.first += nums[p.second];
                pq.push(p);
            }
        }
        return result;
    }
};