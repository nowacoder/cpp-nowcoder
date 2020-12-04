#include <array>
#include <vector>
#include <iostream>

using namespace std;

bool check_loop(vector<array<int,2>> path, int xc, int yc) {
    for (array<int, 2> node : path) {
        if (node[0]==xc and node[1]==yc) return true;
    }
    return false;
}

vector<array<int,2>> traverse(vector<vector<int>> maze, int xc, int yc, vector<array<int,2>> path) {
    path.push_back({xc, yc});
    maze[xc][yc] = 1;
    if (xc==maze.size()-1 and yc==maze[0].size()-1) return path;
    vector<vector<array<int, 2>>> rst;
    vector<array<int, 2>> tmp;
    if (xc-1>=0 and maze[xc-1][yc]==0 and not check_loop(path, xc-1, yc)) {
        tmp = traverse(maze, xc-1, yc, path);
        if (tmp.size()>0) rst.push_back(tmp);
    } 
    if (xc+1<maze.size() and maze[xc+1][yc]==0 and not check_loop(path, xc+1, yc)) {
        tmp = traverse(maze, xc+1, yc, path);
        if (tmp.size()>0) rst.push_back(tmp);
    } 
    if (yc-1>=0 and maze[xc][yc-1]==0 and not check_loop(path, xc, yc-1)) {
        tmp = traverse(maze, xc, yc-1, path);
        if (tmp.size()>0) rst.push_back(tmp);
    } 
    if (yc+1<maze[0].size() and maze[xc][yc+1]==0 and not check_loop(path, xc, yc+1)) {
        tmp = traverse(maze, xc, yc+1, path);
        if (tmp.size()>0) rst.push_back(tmp);
    }
    
    vector<array<int, 2>> tmp2;
    if (rst.size()==0) return tmp2;
    else {
        tmp2 = rst[0];
        for (int i=1; i<rst.size(); i++) {
            if (rst[i].size()<tmp2.size()) tmp2 = rst[i];
        }
        return tmp2;
    }
}

int main() {
    int n, m, tmp;
    while (cin >> n >> m) {
        vector<vector<int>> maze(n);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> tmp;
                maze[i].push_back(tmp);
            }
        }
        vector<array<int,2>> path;
        path = traverse(maze, 0, 0, path);
        for (array<int, 2> node : path) {
            cout << '(' << node[0] << ',' << node[1] << ')' << endl;
        }
    }
    
    return 0;
}