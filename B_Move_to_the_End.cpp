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
/*/ brute force approach
vector<lint> solvefunction(vector<lint>& arr) {
    int n = arr.size();
    vector<lint> ans;
    vector<lint> suffixsum(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        suffixsum[i] = suffixsum[i + 1] + arr[i];
    }
    for (int k = 1; k <= n; k++) {
        lint suf = suffixsum[n - (k - 1)];

        lint max_before_suffix = *max_element(arr.begin(), arr.begin() + (n - k + 1));
        ans.push_back(suf + max_before_suffix);
    }
    return ans;
}*/
// optimised approach 
vector<lint> solvefunction(vector<lint>& arr) {
    int n = arr.size();
    vector<lint> ans(n, 0);
    vector<lint> suffixsum(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        suffixsum[i] = suffixsum[i + 1] + arr[i];
    }
    vector<lint> prefmax(n, 0);
    prefmax[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        prefmax[i] = max(prefmax[i - 1], arr[i]);
    }
    for (int k = 1; k <= n; ++k) {
        ans[k - 1] = suffixsum[n - (k - 1)] + prefmax[n - k];
    }
    return ans;
}
void solution(int test){
    while(test--){
        lint n;
        cin >> n;
        vector<lint>arr;
        forloop(0,n){lint x;cin >> x;arr.push_back(x);}
        vector<lint>ans=solvefunction(arr);
        forloop(0,ans.size()){cout << ans[i] << " ";}
        cout << "\n";
    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}