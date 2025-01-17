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
bool cyclefunction(lint node,lint parent,vector<bool>&visited,vector<lint>adj[],vector<lint>&ans){
    visited[node]=true;
    ans.push_back(node);
    lint n=adj[node].size();
    forloop(0,n){
        lint neighbor=adj[node][i];
        if(neighbor==parent){
            continue;
        }
        if(visited[neighbor]==true){
            return true;
        }else{
            if(cyclefunction(neighbor,node,visited,adj,ans)==true){
                return true;
            }
        }
    }
    return false;
}
bool checkforcycle(lint n,vector<lint>adj[],vector<lint>&ans){
    vector<bool>visited(n,false);
    forloop(0,n){
        if(visited[i]==false){
            if(cyclefunction(i,-1,visited,adj,ans)==true){
                return true;
            }
        }
    }
    return false;
}
string solvefunction(lint n,vector<lint>adj[]){
    vector<lint>inDegree(n,0);;
    forloop(0,n){
        int sz=adj[i].size();
        secondfor(0,sz){
            lint node=adj[i][j];
            inDegree[node]++;
        }
    }
    vector<lint>ans;
    bool isCycle=checkforcycle(n,adj,ans);
    if(isCycle==true && ans.size()==n){
        return "ring topology";
    }
    if(isCycle==true && ans.size()!=n){
        return "unknown topology";
    }
    forloop(0,n){
        if(inDegree[i]==n-1){
            return "star topology";
        }
    }
    lint odd=0;
    forloop(0,inDegree.size()){
        if(inDegree[i]==1){
            odd++;
        }
    }
    if(odd==2){
        return "bus topology";
    }
    return "unknown topology";

}
void solution(){
    lint n;lint m;
    cin >>  n >> m;
    vector<lint>adj[n];
    forloop(0,m){
        lint u;lint v;cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    string ans=solvefunction(n,adj);
    print(ans)
}
int main(){

    solution();
}