#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    stack<int> s;

    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    while (s.size() > 1) {
        int i = s.top();
        s.pop();

        int j = s.top();
        s.pop();

        if (mat[i][j] == 1)
            s.push(j);
        else
            s.push(i);
    }

    int celeb = s.top();

    bool isCelebrity = true;

    for (int i = 0; i < n; i++) {
        if (i == celeb) continue;

        if (mat[celeb][i] == 1 || mat[i][celeb] == 0) {
            isCelebrity = false;
            break;
        }
    }

    cout << (isCelebrity ? celeb : -1) << endl;

    return 0;
}