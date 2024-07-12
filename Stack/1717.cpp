class Solution {
public:
    int res = 0;
    string s;
    
    void calc(string ss, int x, int y){
        int j = -1;
        for(int i = 0; i < s.size(); i++){
            if(j != -1 and string() + s[j] + s[i] == ss){
                j--;
                res += ss == "ab" ? x : y;
            } else {
                s[++j] = s[i];
            }
        }
        s.resize(j + 1);
    }
    int maximumGain(string s, int x, int y) {
        this->s = s;
        if(x < y){
            calc("ba", x, y);
            calc("ab", x, y);
        } else {
            calc("ab", x, y);
            calc("ba", x, y);
        }
        return res;
    }
};