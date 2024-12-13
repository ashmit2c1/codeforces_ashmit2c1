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

lint mergeAndCount(vector<lint>& arr, int start, int mid, int end) {
    vector<int> temp(end - start + 1);
    int i = start, j = mid + 1, k = 0;
    lint inversions = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversions += (mid - i + 1); // Count inversions
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= end) {
        temp[k++] = arr[j++];
    }

    for (int idx = 0; idx < temp.size(); idx++) {
        arr[start + idx] = temp[idx];
    }

    return inversions;
}

lint countInversions(vector<lint>& arr, int start, int end) {
    if (start >= end) return 0;

    int mid = start + (end - start) / 2;
    lint left = countInversions(arr, start, mid);
    lint right = countInversions(arr, mid + 1, end);
    lint merged = mergeAndCount(arr, start, mid, end);

    return left + right + merged;
}
lint solveFunction(vector<lint>& arr1, vector<lint>& arr2) {
    map<lint, lint> mp;
    forloop(0, arr2.size()) {
        mp[arr2[i]] = i;
    }
    vector<lint> invertedArr(arr1.size());
    forloop(0, arr1.size()) {
        invertedArr[i] = mp[arr1[i]];
    }
    return countInversions(invertedArr,0,invertedArr.size()-1);
}
void solution(int test) {
    while (test--) {
        lint n;
        cin >> n;
        vector<lint> arr1(n), arr2(n);

        forloop(0, n) cin >> arr1[i];
        forloop(0, n) cin >> arr2[i];

        lint ans = solveFunction(arr1, arr2);
        print(ans);
    }
}
int main() {
    int test;
    cin >> test;
    solution(test);
}