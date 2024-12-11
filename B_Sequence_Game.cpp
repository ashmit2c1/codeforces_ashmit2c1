#include <bits/stdc++.h>
using namespace std;
#define lint long long
#define forloop(x, y) for (int i = x; i < y; i++)
#define print(x) cout << x << "\n";
vector<lint> solveFunction(vector<lint>& arr) {
    vector<lint> ans;
    ans.push_back(arr[0]);

    forloop(1, arr.size()) {
        if (arr[i] >= arr[i - 1]) {
            ans.push_back(arr[i]);
        } else {
            ans.push_back(1);
            ans.push_back(arr[i]);
        }
    }

    return ans;
}


void solution(int test) {
    while (test--) {
        lint n;
        cin >> n;
        vector<lint> arr;
        forloop(0, n) {
            lint x;
            cin >> x;
            arr.push_back(x);
        }
        vector<lint> ans = solveFunction(arr);
        print(ans.size());
        forloop(0, ans.size()) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int test;
    cin >> test;
    solution(test);
}