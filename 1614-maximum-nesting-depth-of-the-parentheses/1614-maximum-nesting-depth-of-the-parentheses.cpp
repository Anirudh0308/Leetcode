class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;

        int result = 0;

        for(char &ch : s){
            if(ch =='('){
                st.push(ch);
            }else if(ch ==')'){
                st.pop();
            }
            result = max(result, (int)st.size());
        }
        return result;
    }
};