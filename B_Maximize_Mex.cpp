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
lint solveFunction(vector<lint> &arr, lint x) {
    unordered_map<lint, lint> mp;
    unordered_map<lint, lint> mp2;
    for (lint num : arr) {
        mp[num]++;
    }
    lint mex = 0;
    while (true) {
        if (mp[mex] > 0) {
            mp[mex]--;
            lint freq = mp[mex];
            mp2[mex % x] += freq; 
            mex++;
        } else if (mp2[mex % x] > 0) {
            mp2[mex % x]--;
            mex++;
        } else {
            break;
        }
    }
    return mex;
}
void solution(int test) {
    while (test--) {
        lint n, x;
        cin >> n >> x;
        vector<lint> arr;
        arr.reserve(n);

        forloop(0, n) {
            lint val;
            cin >> val;
            arr.push_back(val);
        }

        lint ans = solveFunction(arr, x);
        print(ans);
    }
}

int main() {
    int test;
    cin >> test;
    solution(test);
    return 0;
}