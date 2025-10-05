class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> count(24, 0);
        //count[i] = how many numbers have ith bit set

        int result = 0;

        for(int i = 0; i < 24; i++) { //O(24)

            for(int &num : candidates) { //O(n)
                if((num & (1 << i)) != 0) {
                    count[i]++;
                }
            }

            result = max(result, count[i]);

        }

        return result;
    }
};