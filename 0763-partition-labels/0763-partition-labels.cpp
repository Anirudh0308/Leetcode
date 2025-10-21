class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();

        vector<int> result;

        vector<int> mp(26, -1);
        for(int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            mp[idx] = i;
        }

        int i = 0;
        int start = 0;
        int end = 0;
        while(i < n) {
            end = max(end, mp[s[i]-'a']);
            if(i == end) {
                result.push_back(end-start+1);
                start = end+1;
            }
            i++;
        }

        return result;
    }
};