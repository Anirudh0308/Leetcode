class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        
        int currScore = 0;
        int maxScore  = 0;
        int l = 0, r = n-1;

        while(l <= r) {
            if(power >= tokens[l]) {
                currScore++;
                maxScore = max(maxScore, currScore); //keep updating it
                power -= tokens[l]; //choose smallest token
                l++;
                
            } else if(currScore >= 1) {
                currScore--;
                power += tokens[r]; //choose largest token
                r--;
                
            } else {
                //no way further to increase score
                return maxScore;
            }
        }
        return maxScore;
    }
};