class Solution {
public:
    int strStr(string haystack, string needle) {
         int n=haystack.length();
         int m=needle.length();
         if(m>n) return -1;
        for(int i=0;i<n;i++){
            int j=0,k=i;
           for(j=0,k=i;j<m,k<n;j++,k++){
            if(needle[j]!=haystack[k])
                break;
           }
           if(j==m) return i;
        }
        return -1;
    }
};
