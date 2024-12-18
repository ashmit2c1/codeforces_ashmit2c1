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


lint solveFunction(vector<lint>& arr, lint s) {
    lint n = arr.size();
    lint left = 0, sum = 0;
    lint minLength = n + 1;

    for (lint right = 0; right < n; right++) {
        sum += arr[right];

        while (sum >= s) {
            minLength = min(minLength, right - left + 1);
            sum -= arr[left];
            left++;
        }
    }

    return (minLength > n) ? -1 : minLength;
}

void solution() {
    lint n, s;
    cin >> n >> s;
    vector<lint> arr(n);
    forloop(0, n) {
        cin >> arr[i];
    }
    lint ans = solveFunction(arr, s);
    print(ans);
}

int main() {
    solution();
}