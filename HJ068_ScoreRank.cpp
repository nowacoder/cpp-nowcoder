#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct ScoreCard {
    string name;
    int score;
    bool operator<(ScoreCard sc) {
        if (score < sc.score) return true;
        else return false;
    }
    bool operator>(ScoreCard sc) {
        if (score > sc.score) return true;
        else return false;
    }
    ScoreCard(string name_, int score_): name(name_), score(score_) {}
};

int main() {
    int n;
    int ad_flag;
    string name_;
    int score_;
    while (cin >> n) {
        cin >> ad_flag;
        vector<ScoreCard> scores;
        for (int i=0; i<n; i++) {
            cin >> name_ >> score_;
            ScoreCard sc(name_, score_);
            scores.push_back(sc);
            if (ad_flag) {
                for (int j=scores.size()-1; j>0; j--) {
                    if (scores[j]<scores[j-1]) {
                        ScoreCard tmp = scores[j-1];
                        scores[j-1] = scores[j];
                        scores[j] = tmp;
                    } else break;
                }
            } else {
                for (int j=scores.size()-1; j>0; j--) {
                    if (scores[j]>scores[j-1]) {
                        ScoreCard tmp = scores[j-1];
                        scores[j-1] = scores[j];
                        scores[j] = tmp;
                    } else break;
                }
            }
        }
        for (ScoreCard sc : scores) {
            cout << sc.name << ' ' << sc.score << endl;
        }
    }
    return 0;
}