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
// using lower bound
lint helperfunction2(lint element, vector<lint>&arr){
    return lower_bound(arr.begin(), arr.end(), element) - arr.begin() + 1;
}
lint helperfunction(lint element, vector<lint>&arr) {
    lint start = 0;
    lint end = arr.size() - 1;
    lint ans = arr.size();
    while (start <= end) {
        lint mid = start + (end - start) / 2;
        if (arr[mid] >= element) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans + 1; 
}
vector<lint>solvefunction(vector<lint>&arr,vector<lint>&queries){
    vector<lint>ans;
    forloop(1,arr.size()){
        arr[i]+=arr[i-1];
    }
    forloop(0,queries.size()){
        lint element = queries[i];
        lint answer = helperfunction(element,arr);
        ans.push_back(answer);
    }
    return ans;
}
void solution(){
    lint n;cin >> n;
    vector<lint>arr;
    forloop(0,n){lint x;cin >> x;arr.push_back(x);}
    lint q;cin >> q;
    vector<lint>queries;
    forloop(0,q){lint x;cin >> x;queries.push_back(x);}
    vector<lint>ans=solvefunction(arr,queries);
    forloop(0,ans.size()){cout << ans[i] << "\n";}

}
int main(){

    solution();
}