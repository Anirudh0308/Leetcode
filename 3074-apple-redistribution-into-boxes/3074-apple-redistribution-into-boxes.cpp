class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.rbegin(), capacity.rend());
        int used = 0, sum = 0;
        for (int c : capacity) {
            sum += c;
            used++;
            if (sum >= totalApples) break;
        }
        return used;
    }
};