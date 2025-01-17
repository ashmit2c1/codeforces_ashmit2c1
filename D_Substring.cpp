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


void dfsfunction(lint node,vector<lint>adj[],vector<bool>&visited,vector<lint>&ans){
    visited[node]=true;
    ans.push_back(node);
    lint n=adj[node].size();
    forloop(0,n){
        lint neighbor=adj[node][i];
        if(visited[neighbor]==false){
            dfsfunction(neighbor,adj,visited,ans);
        }
    }
}
lint solvefunction(lint n,vector<lint>adj[],string s){
    vector<bool>visited(n,false);
    vector<lint>ans;
    forloop(0,n){
        if(visited[i]==false){
            dfsfunction(i,adj,visited,ans);
        }
    }
    string answerstring="";
    forloop(0,ans.size()){
        answerstring+=s[ans[i]];
    }
    lint cnt=1;
    unordered_map<char,lint>mp;
    forloop(0,ans.size()){
        char character=answerstring[i];
        mp[character]++;
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        lint freq = it->second;
        cnt=max(cnt,freq);
    }
    if(cnt==1){
        return -1;
    }else{
        return cnt;
    }
}
void solution(){
    lint n;lint m;cin >> n >> m;
    string s;cin >> s;
    vector<lint>adj[n];
    forloop(0,m){
        lint u;lint v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
    }
    lint ans=solvefunction(n,adj,s);
    print(ans)
}
int main(){

    solution();
}