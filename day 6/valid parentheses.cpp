class Solution {
public:
    bool isValid(string s) {
        /*map<char,char>mpp={{')','('},{'}','{'},{']','['}};
        stack<char>st;
        for(auto it:s){
            if(mpp.find(it)==mpp.end())
                st.push(it); // left
            else if(!st.empty() && st.top()==mpp[it])
            st.pop();
            else return false;
        }
        return st.empty();
    */
    stack<char>st;
    if(s.length()%2!=0) return false;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            st.push(s[i]);
        else {
        if(st.empty()) return false;
        if((s[i]==')' && st.top()=='(') ||(s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='['))
        st.pop();
        else
        return false; 
        }
    }
    return st.empty();
    }
};
