class Solution {
public:
    string convertToTitle(int columnNumber) {
        string str="";
        while(columnNumber){
            char ch=char(ceil((columnNumber-1)%26)+65);
            str=ch+str;
            columnNumber=(columnNumber-1)/26;
        }
        return str;
    }
};
