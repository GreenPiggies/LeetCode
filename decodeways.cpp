class Solution {
public:
    int numDecodings(string s) {        
        if (s.length() == 1) return (s[0] != '0');
        int t1, t2;
        if (s[0] == '0') return 0;
        else t1 = 1;
        
        if (s[1] == '0') t2 = 0;
        else t2 = t1;
        if (s[0] == '1' || (s[0] == '2' && s[1] <= '6')) t2++;
        
                
        for (int i = 2; i < s.length(); i++) {
            int temp2 = t2;
            int temp1 = t1;
            if (s[i] == '0') t2 = 0;
            else t2 = temp2;
            
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                t2 += temp1;
            }
            t1 = temp2;
        }
        return t2;   
    }
};