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
void unionfunction(lint a,lint b,vector<lint>&setsize,vector<lint>&parent){
    lint parentu=findparent(a,parent);
    lint parentv=findparent(b,parent);
    if(parentu!=parentv){
        if(setsize[parentv]<setsize[parentu]){
            swap(parentu,parentv);
        }
        parent[parentv]=parent[parentu];
        setsize[parentu]+=setsize[parentv];
    }

}
vector<bool>solvefunction(lint n,vector<pair<string,pair<lint,lint>>>&queries){
    vector<bool>ans;
    vector<lint>parent(n,0);
    vector<lint>setsize(n,0);
    forloop(0,n){
        parent[i]=i;
        setsize[i]=1;
    }
    forloop(0,queries.size()){
        string s=queries[i].first;
        lint u=queries[i].second.first-1;
        lint v=queries[i].second.second-1;
        if(s=="union"){
            unionfunction(u,v,setsize,parent);
        }
        if(s=="get"){
        if(findparent(u,parent)!=findparent(v,parent)){
            ans.push_back(false);
        }else{
            ans.push_back(true);
        }}
    }
    return ans;
}

void solution(){
    lint n;lint q;
    cin >> n >> q;
    vector<pair<string,pair<lint,lint>>>queries;
    forloop(0,q){
        string s;lint a;lint b;
        cin >> s >> a >> b;
        queries.push_back({s,{a,b}});
    }
    vector<bool>ans=solvefunction(n,queries);
    forloop(0,ans.size()){
        if(ans[i]==true){
            print("YES")
        }else{
            print("NO")
        }
    }


}
int main(){

    solution();
}