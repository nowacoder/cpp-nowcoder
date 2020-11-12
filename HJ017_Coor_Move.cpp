#include <string>
#include <iostream>
#include <sstream>

using namespace std;

struct Cmd {
    bool s=false;
    int x, y;
    Cmd(int x_, int y_): s(true), x(x_), y(y_) {};
    Cmd(){};
};

int ctoi(char c) {
    if (c>=48 and c<=57) return c-48;
    else return -1;
}

Cmd* par_cmd(char c, char a) {
    if (ctoi(a)<0) return new Cmd();
    else {
        int act = ctoi(a);
        if (c=='A') return new Cmd(act*-1, 0);
        else if (c=='D') return new Cmd(act, 0);
        else if (c=='W') return new Cmd(0, act);
        else if (c=='S') return new Cmd(0, act*-1);
        else return new Cmd();
    }
}

Cmd* par_cmd(char c, char a1, char a2) {
    if (ctoi(a1)<0 or ctoi(a2)<0) return new Cmd();
    else {
        int act = ctoi(a1)*10+ctoi(a2);
        if (c=='A') return new Cmd(act*-1, 0);
        else if (c=='D') return new Cmd(act, 0);
        else if (c=='W') return new Cmd(0, act);
        else if (c=='S') return new Cmd(0, act*-1);
        else return new Cmd();
    }
}


// A10;S20;W10;D30;X;A1A;B10A11;;A10;
// 10,-10

int main() {
    for(string line; getline(cin, line);) {
        stringstream ss(line);
        string cmd_str;
        Cmd *cmd;
        int pst_x=0, pst_y=0;
        while (ss.good()) {
            getline(ss, cmd_str, ';');
            if (cmd_str.length()==2) {
                cmd = par_cmd(cmd_str[0], cmd_str[1]);
                if (cmd->s) {pst_x+=cmd->x; pst_y+=cmd->y;}
            } else if (cmd_str.length()==3) {
                cmd = par_cmd(cmd_str[0], cmd_str[1], cmd_str[2]);
                if (cmd->s) {pst_x+=cmd->x; pst_y+=cmd->y;}
            }
        }
        cout << pst_x << ',' << pst_y << endl;
    }
    return 0;
}