class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k == 1)
            return 1;
        if(k%2 == 0 || k%5 == 0)
            return -1;
        
        int remain = 0;
        for(int i = 1; i<=k; i++) {
            remain = (remain*10 + 1)%k; //remainder will never exceed k-1, hence avoiding integer overflow

            if(remain == 0)
                return i;
        }

        return -1;
    }
};