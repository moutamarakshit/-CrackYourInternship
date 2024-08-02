class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str="";
        sort(strs.begin(),strs.end());
        int n=strs.size();
        string start=strs[0],end=strs[n-1];
        for(int i=0;i<min(start.length(),end.length());i++){
            if(start[i]!=end[i])
            return str;
            str+=start[i];
        }
        return str;
    }
};
