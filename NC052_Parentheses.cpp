#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return bool布尔型
     */
    bool isValid(string s) {
        if (s.length()%2) return false;
        stack<char> stk;
        char t;
        for (char c : s) {
            if (c=='(' or c=='[' or c=='{') stk.push(c);
            else {
                if (stk.empty()) return false; // case: "]]"
                t = stk.top();
                if ((t=='(' and c!=')') or (t=='[' and c!=']') or (t=='{' and c!='}')) return false;
                else stk.pop();
            }
        }
        if (stk.size()==0) return true;
        return false; // case "[["
    }
};

int main() {
    string parentheses = "([)]"; // "()[]{}";
    cout << Solution().isValid(parentheses) << endl;
    return 0;
}
