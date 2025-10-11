class Solution {
public:
    string simplifyPath(string path) {
        string token = "";

        stringstream ss(path);
        stack<string> st;
        
        while(getline(ss, token, '/')) {

            if(token == "" || token == ".") continue;
            
            if (token != "..") 
                st.push(token);
            else if (!st.empty()) 
                st.pop();
        }

        string result = "";
        
         while(!st.empty()){ // add all the stack elements
            result="/"+st.top()+result;
            st.pop();
        }
        
        if(result.length()==0) // if no directory or file is present
            result="/"; // minimum root directory must be present in result
        
        return result;
    }
};