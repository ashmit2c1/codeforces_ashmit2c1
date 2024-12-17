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

lint solveFunction(vector<lint>& arr, lint k) {
    lint sum = 0;
    forloop(0, k) { sum += arr[i]; }
    lint minSum = sum;
    lint atIndex = 0;
    forloop(k, arr.size()) {
        lint valToRemove = arr[i - k];
        sum = sum + arr[i] - valToRemove;
        if (minSum > sum) {
            minSum = sum;
            atIndex = i - k + 1;
        }
    }
    return atIndex+1;
}

void solution() {
    lint n, k;
    cin >> n >> k;
    vector<lint> arr;
    forloop(0, n) { lint x; cin >> x; arr.push_back(x); }
    lint ans = solveFunction(arr, k);
    print(ans);
}

int main() {
    solution();
}