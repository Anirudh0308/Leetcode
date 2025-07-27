class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();  //row 
        int n = matrix[0].size(); //column

        int dir = 0;

        int top = 0;
        int down = m-1;

        int left = 0;
        int right = n-1;

        // dir = 0: left to right
        // dir = 1 : tor to down
        // dir = 2 : right to left
        // dir = 3 : down to top

        vector<int> result;

        while(top <= down && left <= right){
            if(dir == 0){
                // left to right -> row constant

                for(int i = left; i<= right; i++){
                    result.push_back(matrix[top][i]);
                }
                top++;
            }
            if(dir == 1){
                // top to down -> column constant
                for(int i = top; i<= down; i++){
                    result.push_back(matrix[i][right]);
                }
                right--;
            }
            if(dir == 2){

                for(int i = right; i>=left; i--){
                    result.push_back(matrix[down][i]);
                }
                down--;
            }

            if(dir == 3){

                for(int i = down; i>=top; i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
            dir++;
            if(dir == 4)
               dir =0;
        }
        return result;

    }
};