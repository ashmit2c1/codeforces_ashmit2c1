#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define forloop(x, y) for (int i = x; i < y; i++)
#define secondfor(x, y) for (int j = x; j < y; j++)
#define print(x) cout << x << "\n";
#define output(arr) for (int i = 0; i < arr.size(); i++) { cout << arr[i] << " "; }
#define asort(v) sort(v.begin(), v.end())
#define dsort(v) sort(v.begin(), v.end(), greater<int>())
#define intmax INT_MAX
#define intmin INT_MIN
#define lintmax LLONG_MAX
#define lintmin LLONG_MIN
#define mp(x, y) make_pair(x, y)

bool isSuperior(vector<vector<lint>>& mat, lint potential, lint current) {
    lint count = 0;
    secondfor(0, 5) {
        if (mat[potential][j] < mat[current][j]) {
            count++;
        }
    }
    if(count>2){
        return true;
    }else{
        return false;
    }
}
bool validateCandidate(vector<vector<lint>>& mat, lint candidate) {
    forloop(0, mat.size()) {
        if (i != candidate) {
            lint count = 0;
            secondfor(0, 5) {
                if (mat[i][j] < mat[candidate][j]) {
                    count++;
                }
            }
            if (count >= 3) {
                return false;
            }
        }
    }
    return true;
}
lint solvefunction(vector<vector<lint>>& mat) {
    lint candidate = 0;
    forloop(1, mat.size()) {
        if (isSuperior(mat, i, candidate)) {
            candidate = i;
        }
    }
    if (validateCandidate(mat, candidate)) {
        return candidate + 1;
    } else {
        return -1;
    }
}

void solution(int test) {
    while (test--) {
        lint n;
        cin >> n;
        vector<vector<lint>> mat(n, vector<lint>(5));
        forloop(0, n) {
            secondfor(0, 5) {
                cin >> mat[i][j];
            }
        }
        lint ans = solvefunction(mat);
        print(ans);
    }
}

int main() {
    int test;
    cin >> test;
    solution(test);
    return 0;
}