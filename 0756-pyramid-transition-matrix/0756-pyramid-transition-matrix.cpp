

class Solution {
public:
    // Map to quickly find allowed tops: "AB" -> ['C', 'D']
    unordered_map<string, vector<char>> allowedPatterns;
    // Memoization to store rows that cannot reach the top
    unordered_set<string> memo;

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // 1. Preprocess allowed patterns into a Hash Map for O(1) access
        for (const string& s : allowed) {
            allowedPatterns[s.substr(0, 2)].push_back(s[2]);
        }
        
        return solve(bottom);
    }

private:
    // Layer 1: Vertical Recursion - Moves up levels
    bool solve(string row) {
        // Base Case: If only 1 block remains, we reached the top
        if (row.length() == 1) return true;
        
        // Check if we have already determined this row leads to a dead end
        if (memo.count(row)) return false;

        // Start building the next row (Horizontal Recursion)
        if (buildNextRow(row, "", 0)) {
            return true;
        }

        // If no path works, mark this row as failed
        memo.insert(row);
        return false;
    }

    // Layer 2: Horizontal Recursion - Builds the row above the current one
    bool buildNextRow(const string& currentRow, string nextRow, int idx) {
        // If the next row is fully built, move up to the next level (Vertical Recursion)
        if (idx == currentRow.length() - 1) {
            return solve(nextRow);
        }

        // Get the base pair from the current row (e.g., "AB")
        string key = currentRow.substr(idx, 2);

        // If no patterns exist for this pair, this path is invalid
        if (allowedPatterns.find(key) == allowedPatterns.end()) {
            return false;
        }

        // Try every allowed character for this specific position
        for (char val : allowedPatterns[key]) {
            // Add block, recurse, then backtrack (implicit since we pass by value or push/pop)
            nextRow.push_back(val);
            if (buildNextRow(currentRow, nextRow, idx + 1)) {
                return true;
            }
            nextRow.pop_back(); // Backtrack
        }

        return false;
    }
};