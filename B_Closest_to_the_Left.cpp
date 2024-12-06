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

vector<lint>solveFunction(vector<lint>&arr,vector<lint>&queries){
    vector<lint>ans;
    forloop(0,queries.size()){
        lint element=queries[i];
        lint idx=upper_bound(arr.begin(),arr.end(),element)-arr.begin();
        ans.push_back(idx);
    }
    return ans;
}

void solution(){
    lint n;lint q;
    cin >> n >> q;
    vector<lint>arr;vector<lint>queries;
    forloop(0,n){lint x;cin >> x;arr.push_back(x);}
    forloop(0,q){lint x;cin >> x;queries.push_back(x);}
    vector<lint>ans=solveFunction(arr,queries);
    forloop(0,ans.size()){print(ans[i])}
}
int main(){

    solution();
}