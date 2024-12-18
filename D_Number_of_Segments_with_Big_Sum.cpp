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
lint solveFunction(vector<lint>& arr, lint target) {
    lint left = 0, right = 0, cnt = 0, sum = 0;
    while (right < arr.size()) {
        sum += arr[right];
        while (sum >= target) {
            cnt += (arr.size() - right);
            sum -= arr[left];
            left++;
        }
        right++;
    }
    return cnt;
}

void solution() {
    lint n, target;
    cin >> n >> target;
    vector<lint> arr;
    forloop(0, n) {
        lint x;
        cin >> x;
        arr.push_back(x);
    }
    lint ans = solveFunction(arr, target);
    print(ans);
}

int main() {
    solution();
}