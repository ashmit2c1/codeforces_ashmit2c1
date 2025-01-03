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


// BRUTE FORCE APPROACH 

lint calculate(lint leftindex,lint rightindex,string s){
    lint cnt=0;
    forloop(leftindex,rightindex){
        if(s[i]==s[i+1]){cnt++;}
    }
    return cnt;
}
vector<lint>solvefunction(vector<pair<lint,lint>>&arr,string s){
    vector<lint>ans;
    forloop(0,arr.size()){
        lint leftIndex = arr[i].first-1;
        lint rightIndex = arr[i].second-1;
        lint answer = calculate(leftIndex,rightIndex,s);
        ans.push_back(answer);
    }
    return ans;
}
// OPTIMISED APPROACH 
lint bettercalculate(vector<lint>&prefix,lint leftindex,lint rightindex){
    if(leftindex==0){
        return prefix[rightindex];
    }
    else{
        return prefix[rightindex]-prefix[leftindex];
    }
}
vector<lint>betterfunction(vector<pair<lint,lint>>&arr,string s){
    vector<lint>ans;
    vector<lint>prefix(s.size(),0);
    forloop(1,prefix.size()){
        if(s[i]==s[i-1]){
            prefix[i]=prefix[i-1]+1;
        }
        else{
            prefix[i]=prefix[i-1];
        }
    }
    forloop(0,arr.size()){
        lint leftIndex=arr[i].first-1;
        lint rightIndex=arr[i].second-1;
        lint answer = bettercalculate(prefix,leftIndex,rightIndex);
        ans.push_back(answer);
    }
    return ans;
}

void solution(){
    string s;cin >> s;
    lint n;cin >> n;
    vector<pair<lint,lint>>arr;
    forloop(0,n){
        lint x;lint y;cin >> x >> y;
        arr.push_back({x,y});
    }
    vector<lint>ans=betterfunction(arr,s);
    forloop(0,ans.size()){
        cout << ans[i] << "\n";
    }

}
int main(){

    solution();
}