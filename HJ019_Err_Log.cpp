#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

struct Log {
    string file;
    int lnum;
    int cnt = 1;
    Log(string file_, int lnum_): file(file_), lnum(lnum_) {};
    
    bool operator==(const Log &lg) {
        return (file==lg.file) and (lnum==lg.lnum);
    }
};

string getFileName(string file) {
    return file.substr(file.rfind('\\')+1);
}

int main() {
    string file_lnum, file, lnum_str;
    int lnum;
    vector<Log> log;
    while (cin >> file >> lnum) {
        Log tLog(getFileName(file), lnum);
        auto res = find(log.begin(), log.end(), tLog);
        if (res==log.end()) log.push_back(tLog);
        else res->cnt++;
        // if (log.size()>8) log.erase(log.begin());
    }

    int file_len;
    int log_start = log.size()>8?log.size()-8:0;
    for (int i=log_start; i<log.size(); i++) {
        Log tLog = log[i];
        file_len = tLog.file.size();
        if (file_len>16) file = tLog.file.substr(file_len-16,file_len);
        else file = tLog.file;
        cout << file << ' ' << tLog.lnum << ' ' << tLog.cnt << endl;
    } 
    
    return 0;
}