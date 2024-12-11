#include <bits/stdc++.h>
using namespace std;
#define lint long long
#define forloop(x, y) for (int i = x; i < y; i++)
#define secondfor(x, y) for (int j = x; j < y; j++)
#define print(x) cout << x << "\n";
#define output(arr) for (int i = 0; i < arr.size(); i++) { cout << arr[i] << " "; } cout << "\n";
#define asort(v) sort(v.begin(), v.end())
#define dsort(v) sort(v.begin(), v.end(), greater<int>())
#define intmax INT_MAX
#define intmin INT_MIN
#define lintmax LLONG_MAX
#define lintmin LLONG_MIN
#define mp(x, y) make_pair(x, y)

void changeFunction2(lint leftIndex, lint rightIndex, lint change, vector<lint>& arr) {
    leftIndex--;
    rightIndex--;
    arr[leftIndex] += change;
    if (rightIndex + 1 < arr.size()) {
        arr[rightIndex + 1] -= change; 
    }
}
void solveSolveFunction2(lint left, lint right, vector<lint>& arr, vector<pair<lint, pair<lint, lint>>>& ops) {
    forloop(left - 1, right) {
        lint leftIndex = ops[i].first;
        lint rightIndex = ops[i].second.first;
        lint change = ops[i].second.second;
        changeFunction2(leftIndex, rightIndex, change, arr);
    }
}
void solveFunction2(vector<lint>& arr, vector<pair<lint, pair<lint, lint>>>& ops, vector<pair<lint, lint>>& queries) {
    forloop(0, queries.size()) {
        lint left = queries[i].first;
        lint right = queries[i].second;
        solveSolveFunction2(left, right, arr, ops);
    }
}
void solution() {
    lint n, m, k;
    cin >> n >> m >> k;
    vector<lint> arr(n, 0);
    forloop(0, n) {
        cin >> arr[i];
    }
    vector<pair<lint, pair<lint, lint>>> ops(m);
    forloop(0, m) {
        lint l, r, d;
        cin >> l >> r >> d;
        ops[i] = {l, {r, d}};
    }
    vector<pair<lint, lint>> queries(k);
    forloop(0, k) {
        lint x, y;
        cin >> x >> y;
        queries[i] = {x, y};
    }
    vector<lint>temp(arr.size(),0);
    solveFunction2(temp, ops, queries);
    forloop(1,temp.size()){
        temp[i]+=temp[i-1];
    }
    forloop(0,arr.size()){
        arr[i]+=temp[i];
    }
    output(arr)

}

int main() {
    solution();
    return 0;
}
// BRUTE FORCE SOLUTION 
void changeFunction(lint leftIndex, lint rightIndex, lint change, vector<lint>& arr) {
    leftIndex--;rightIndex--;
    forloop(leftIndex, rightIndex + 1) {
        arr[i] += change;
    }
}
void solveSolveFunction(lint left, lint right, vector<lint>& arr, vector<pair<lint, pair<lint, lint>>>& ops) {
    forloop(left - 1, right) {
        lint leftIndex = ops[i].first;
        lint rightIndex = ops[i].second.first;
        lint change = ops[i].second.second;
        changeFunction(leftIndex, rightIndex, change, arr);
    }
}
void solveFunction(vector<lint>& arr, vector<pair<lint, pair<lint, lint>>>& ops, vector<pair<lint, lint>>& queries) {
    forloop(0, queries.size()) {
        lint left = queries[i].first;
        lint right = queries[i].second;
        solveSolveFunction(left, right, arr, ops);
    }
}


