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


vector<lint>solveFunction(vector<lint>&arr1,vector<lint>&arr2){
    vector<lint>ans;
    lint i=0;lint j=0;
    lint n=arr1.size();lint m=arr2.size();
    while(i<n && j<m){
        if(arr1[i] <= arr2[j]){
            ans.push_back(arr1[i++]);
        }
        else{
            ans.push_back(arr2[j++]);
        }
    }
    while(i<n){
        ans.push_back(arr1[i++]);
    }
    while(j<m){
        ans.push_back(arr2[j++]);
    }
    return ans;
}


void solution(){
    lint n;lint w;
    cin >> n >> w;
    vector<lint>arr1;
    vector<lint>arr2;
    forloop(0,n){lint x;cin >> x;arr1.push_back(x);}
    forloop(0,w){lint x;cin >> x;arr2.push_back(x);}
    vector<lint>ans=solveFunction(arr1,arr2);
    forloop(0,ans.size()){
        cout << ans[i] << " ";
    }
    cout << "\n";

}
int main(){

    solution();
}