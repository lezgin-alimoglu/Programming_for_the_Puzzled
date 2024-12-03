#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> Case1 = {"F", "F", "B", "B", "B", "F", "B", "B", "B", "F", "F", "B", "F"};
vector<string> Case2 = {"F", "F", "B", "F", "B", "F", "B", "B", "B", "F", "F", "F", "F"};

// There is a short way also. The term in Case[0] is never smaller than the other term. So just print according to the first case.
// However, the long way is also good, if we need to add other term.

void pleaseConform(const vector<string>& Case) {
    int start = 0, forward = 0, backward = 0;
    vector<vector<int>> intervals;

    for (int i = 1; i <= Case.size(); i++) {
        if (i == Case.size() || Case[i] != Case[start]) {
            intervals.push_back({start, i - 1, (Case[start] == "F" ? 0 : 1)});
            if (Case[start] == "F") {
                forward++;
            } else {
                backward++;
            }
            start = i;
        }
    }

    string flip = (forward < backward) ? "F" : "B";

    for (const auto& interval : intervals) {
        if ((flip == "F" && interval[2] == 0) || (flip == "B" && interval[2] == 1)) {
            if (interval[0] == interval[1]) {
                cout << "Person in position " << interval[0] 
                    << ", flip your cap!" << endl;
            } else {
                cout << "People in positions " << interval[0] 
                    << " through " << interval[1] 
                    << ", flip your caps!" << endl;
            }
        }
    }

}

int main() {
    cout << "Case 1:" << endl;
    pleaseConform(Case1);

    cout << "\nCase 2:" << endl;
    pleaseConform(Case2);

    return 0;
}
