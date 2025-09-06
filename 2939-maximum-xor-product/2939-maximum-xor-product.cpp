class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n){
        int result = 0;
        
        for(int x = 0; x < pow(2, n); x++) {
            long long p = (a^x) * (b^x);
            result = max<long long>(result, p);
        }
        
        return result;
    }
};