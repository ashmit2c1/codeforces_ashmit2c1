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


vector<lint>solveFunction(vector<lint>&arr,vector<pair<lint,lint>>&queries){
    vector<lint>ans;
    forloop(0,queries.size()){
        lint left=queries[i].first;
        lint right=queries[i].second;
        lint leftIdx=lower_bound(arr.begin(),arr.end(),left)-arr.begin();
        lint rightIdx=upper_bound(arr.begin(),arr.end(),right)-arr.begin();
        lint num=rightIdx-leftIdx;
        ans.push_back(num);
    }
    return ans;
}

void solution(){
    lint n;cin >> n;
    vector<lint>arr;
    forloop(0,n){lint x;cin >>x;arr.push_back(x);}
    vector<pair<lint,lint>>queries;
    lint q;cin >> q;
    sort(arr.begin(),arr.end());
    forloop(0,q){
        lint x;lint y;cin >> x;cin>>y;
        queries.push_back({x,y});
    }
    vector<lint>ans=solveFunction(arr,queries);
    output(ans)

}
int main(){

    solution();
}