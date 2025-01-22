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

lint findparent(lint element,vector<lint>&parent){
    if(parent[element]==element){
        return element;
    }else{
        lint leader_element = findparent(parent[element],parent);
        parent[element]=leader_element;
        return leader_element;
    }
}
void unionfunction(lint u,lint v,vector<lint>&parent,vector<lint>&setsize){
    lint parentu=findparent(u,parent);
    lint parentv=findparent(v,parent);
    if(parentu!=parentv){
        if(setsize[parentv]<setsize[parentu]){
            swap(parentu,parentv);
        }
        parent[parentv]=parentu;
        setsize[parentu]+=setsize[parentv];
    }

}
vector<pair<lint,lint>> solvefunction(lint n,vector<pair<lint,lint>>&mocha,vector<pair<lint,lint>>&diana){
    vector<lint>parentmocha(n);
    vector<lint>parentdiana(n);
    vector<lint>setsizemocha(n);
    vector<lint>setsizediana(n);
    forloop(0,n){
        parentmocha[i]=i;
        parentdiana[i]=i;
        setsizediana[i]=1;
        setsizemocha[i]=1;
    }
    forloop(0,mocha.size()){
        lint u=mocha[i].first;
        lint v=mocha[i].second;
        unionfunction(u,v,parentmocha,setsizemocha);
    }
    forloop(0,diana.size()){
        lint u = diana[i].first;
        lint v = diana[i].second;
        unionfunction(u,v,parentdiana,setsizediana);
    }
    vector<pair<lint,lint>>ans;
    forloop(0,n){
        secondfor(i+1,n){
            if((findparent(i,parentmocha)!=findparent(j,parentmocha)) && (findparent(i,parentdiana)!=findparent(j,parentdiana))){
                unionfunction(i,j,parentmocha,setsizemocha);
                unionfunction(i,j,parentdiana,setsizediana);
                ans.push_back({i,j});
            }
        }
    }
    return ans;
}
void solution(){
    lint n;cin >> n;
    vector<pair<lint,lint>>mocha;
    vector<pair<lint,lint>>diana;
    lint m;lint w;
    cin >> m >> w;
    forloop(0,m){
        lint u;lint v;
        cin >> u >> v;
        mocha.push_back({u-1,v-1});
    }
    forloop(0,w){
        lint u;lint v;
        cin >> u >> v;
        diana.push_back({u-1,v-1});
    }
    vector<pair<lint,lint>> ans=solvefunction(n,mocha,diana);
    print(ans.size())
    forloop(0,ans.size()){
        cout << ans[i].first+1 << " " << ans[i].second+1 << "\n";
    }
}
int main(){

    solution();
}