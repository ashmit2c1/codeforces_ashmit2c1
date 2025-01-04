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
lint calculatebettter(vector<lint>&prefix,lint index){
    return prefix[index-1];
}

vector<lint>bettersolvefunction(vector<lint>&arr,vector<lint>&queries){
    unordered_map<lint,lint>mp;
    vector<lint>prefix(arr.size(),1);
    mp[arr[arr.size()-1]]++;
    for(int i=arr.size()-2;i>=0;i--){
        if(mp.find(arr[i])==mp.end()){
            prefix[i]=prefix[i+1]+1;
            mp[arr[i]]++;
        }
        else{
            prefix[i]=prefix[i+1];
        }
        
    }
    vector<lint>ans;
    forloop(0,queries.size()){
        lint index=queries[i];
        lint answer = calculatebettter(prefix,index);
        ans.push_back(answer);
    }
    return ans;

}
/*lint calculatebettter(vector<lint>&prefix,lint index){
    return prefix[index-1];
}

vector<lint>bettersolvefunction(vector<lint>&arr,vector<lint>&queries){
    unordered_map<lint,lint>mp;
    vector<lint>prefix(arr.size(),1);
    mp[arr[arr.size()-1]]++;
    for(int i=arr.size()-1;i>=0;i--){
        if(mp.find(arr[i])!=mp.end()){
            prefix[i]=0;
        }
        mp[arr[i]]++;
    }
    for(int i=prefix.size()-2;i>=0;i--){
        prefix[i]+=prefix[i+1];
    }
    vector<lint>ans;
    forloop(0,queries.size()){
        lint index=queries[i];
        lint answer = calculatebettter(prefix,index);
        ans.push_back(answer+1);
    }
    return ans;

}
// brute force way 
lint calculate(vector<lint>&arr,lint index){
    set<lint>st;
    forloop(index,arr.size()){
        st.insert(arr[i]);
    }
    return st.size();
}

vector<lint>solvefunction(vector<lint>&arr,vector<lint>&queries){
    vector<lint>ans;
    forloop(0,queries.size()){
        lint index=queries[i]-1;
        lint answer=calculate(arr,index);
        ans.push_back(answer);
    }
    return ans;
}
*/
void solution(){
    lint n;lint m;
    cin >> n >> m;
    vector<lint>arr;
    forloop(0,n){
        lint x;cin >> x;arr.push_back(x);
    }
    vector<lint>queries;
    forloop(0,m){
        lint x;cin >> x;queries.push_back(x);
    }
    vector<lint>ans=bettersolvefunction(arr,queries);
    forloop(0,ans.size()){
        print(ans[i])
    }
}
int main(){

    solution();
}