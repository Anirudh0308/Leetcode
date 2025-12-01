class Solution {
public:

    typedef long long ll;

    bool possible(vector<int>& batteries, ll time, int n) {
        ll target = n * time;

        for (int b : batteries) {
            target -= min((ll)b, time);
            if (target <= 0) return true;
        }
        return false;
    }    

    long long maxRunTime(int n, vector<int>& batteries) {
        ll l = *min_element(begin(batteries), end(batteries));
        
        long long sum_total_minutes = 0;
        
        for(auto &mints : batteries){
            sum_total_minutes += mints;
        }
        
        ll r = sum_total_minutes/n;
        
        ll result = 0;
        
        while(l <= r) {
            
            ll mid_time = l + (r-l)/2;
            
            if(possible(batteries, mid_time, n)) {
                result = mid_time;
                l = mid_time+1;
            } else {
                r = mid_time-1;
            }
        }
        
        return result;
    }
};