#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define forloop(x,y) for(int i=x;i<y;i++)
#define secondfor(x,y) for(int j=x;j<y;j++)
#define print(x) cout << x << "\n";
#define output(arr) for(int i=0;i<arr.size();i++){cout<<arr[i]<<" ";}
#define asort(v) sort(v.begin(), v.end())
#define dsort(v) sort(v.begin(), v.end(), greater<int>())
#define intmax INT_MAX
#define intmin INT_MIN
#define lintmax LLONG_MAX
#define lintmin LLONG_MIN
#define mp(x,y) make_pair(x,y)

pair<lint, lint> solveFunction(vector<vector<char>>& matrix) {
    lint n = matrix.size();
    lint m = matrix[0].size();
    lint firstX = -1, secondX = -1, firstY = -1, secondY = -1;
    forloop(0, n) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '#') {
                if (firstX == -1) firstX = i; 
                secondX = i; 
                break;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        forloop(0, n) {
            if (matrix[i][j] == '#') {
                if (firstY == -1) firstY = j;
                secondY = j; 
                break;
            }
        }
    }
    lint x = (firstX + secondX) / 2 + 1;
    lint y = (firstY + secondY) / 2 + 1;
    return {x, y};
}

void solution(int test) {
    while (test--) {
        lint n, m;
        cin >> n >> m;
        vector<vector<char>> matrix(n, vector<char>(m));
        forloop(0, n) {
            secondfor(0, m) {
                cin >> matrix[i][j];
            }
        }
        pair<lint, lint> ans = solveFunction(matrix);
        cout << ans.first << " " << ans.second << "\n";
    }
}

int main() {
    int test;
    cin >> test;
    solution(test);
}