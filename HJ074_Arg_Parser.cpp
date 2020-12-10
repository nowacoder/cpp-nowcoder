#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    string cmd_line;
    while (getline(cin, cmd_line)) {
        vector<string> cmd;
        bool enclosed = false;
        string cmd_="";
        for (char c : cmd_line) {
            if (c==' ' and !enclosed and cmd_.length()>0) {
                cmd.push_back(cmd_);
                cmd_ = "";
            } else if (c=='"') enclosed = !enclosed;
            else cmd_ += c;
        }
        if (cmd_.length()>0) cmd.push_back(cmd_);
        cout << cmd.size() << endl;
        for (string cmd_ : cmd) cout << cmd_ << endl;
    }
    return 0;
}