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

lint calculateFunction(lint type,lint leftIndex,lint rightIndex,vector<lint>&arr1,vector<lint>&arr2){
    if(type==1){
        if(leftIndex>0){return arr1[rightIndex]-arr1[leftIndex-1];}
        else{return arr1[rightIndex];}
    }
    if(type==2){
        if(leftIndex>0){return arr2[rightIndex]-arr2[leftIndex-1];}
        else{return arr2[rightIndex];}
    }
}

vector<lint>solveFunction(vector<lint>&prefix1,vector<lint>&prefix2,vector<pair<lint,pair<lint,lint>>>&queries){
    vector<lint>ans;
    forloop(0,queries.size()){
        lint type=queries[i].first;
        lint leftIndex=queries[i].second.first-1;
        lint rightIndex=queries[i].second.second-1;
        lint answer = calculateFunction(type,leftIndex,rightIndex,prefix1,prefix2);
        ans.push_back(answer);
    }
    return ans;
}
void solution(){
    lint n;cin >> n;
    vector<lint>arr1,arr2;
    forloop(0,n){lint x;cin >> x;arr1.push_back(x);arr2.push_back(x);}
    sort(arr2.begin(),arr2.end());
    forloop(1,n){
        arr1[i]+=arr1[i-1];arr2[i]+=arr2[i-1];
    }
    lint q;cin >> q;
    vector<pair<lint,pair<lint,lint>>>queries;
    forloop(0,q){
        lint type;lint left;lint right;
        cin >> type >> left >> right;
        queries.push_back({type,{left,right}});
    }
    vector<lint>ans=solveFunction(arr1,arr2,queries);
    forloop(0,ans.size()){print(ans[i])}
}
int main(){

    solution();
}