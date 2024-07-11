
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        int tp[s.size() + 1];
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            } else if(s[i] == ')'){
                tp[st.top()] = i;
                tp[i] = st.top();
                st.pop();
            }
        }
        int i = 0;
        string res;
        int rev = 0;
        while(i < s.size()){
            if(s[i] == '('){
                i = tp[i];
                rev = !rev;
            } else if(s[i] == ')'){
                i = tp[i];
                rev = !rev;
            } else {
                res += s[i];
                //i++;
            }
            
            if(rev)i--;
            else i++;
        }
        return res;
    }
};
class Solution {
public:
    int p[10001];
    string res;
    void left(string &s, int l, int r){
        int i = l;
        while(i <= r){
            if(s[i] == '(') {
                int j = p[i];
                right(s, i + 1, j - 1);
                i = j + 1;
            } else {
                res += s[i];
                i++;
            }
        }
    }
    void right(string& s, int l, int r){
        int j = r;
        while(j >= l){
            if(s[j] == ')'){
                //j = p[j];
                left(s, p[j] + 1, j - 1);
                j = p[j] - 1;
            } else {
                res += s[j];
                j--;
            }
        }
    }
    string reverseParentheses(string s) {
        stack<int>st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            } else if(s[i] == ')'){
                p[st.top()] = i;
                p[i] = st.top();
                st.pop();
            } 
        }
        left(s, 0, s.size() - 1);
        return res;
    }
};