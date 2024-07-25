class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1, j = b.length() - 1, carry = 0;
        string str = "";
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            carry = sum / 2;
            sum = sum % 2 + '0';
            str += sum;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
