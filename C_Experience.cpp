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
void setpoints(lint player,lint points,vector<lint>&exp){
    exp[player]+=points;
}
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
        if(setsize[parentv]<setsize[parentv]){
            swap(parentu,parentv);
        }
        parent[parentv]=parentu;
        setsize[parentu]+=setsize[parentv];
    }
}
lint findpoints(lint player,vector<lint>&exp){
    return exp[player];
}
void setallteampoints(lint player,lint points,vector<lint>&parent,vector<lint>&exp){
    lint leader = findparent(player,parent);
    if(leader!=player){
        exp[leader]+=points;
    }
    forloop(0,parent.size()){
        if((i!=leader) && findparent(i,parent)==leader){
            exp[i]+=points;
        }
    }
}
vector<lint>solvefunction(lint n,vector<pair<string,pair<lint,lint>>>&queries){
    vector<lint>parent(n);
    vector<lint>setsize(n);
    vector<lint>exp(n);
    forloop(0,n){
        parent[i]=i;
        setsize[i]=1;
    }
    vector<lint>ans;
    forloop(0,queries.size()){
        string command = queries[i].first;
        if(command=="add"){
            lint player = queries[i].second.first;
            lint points = queries[i].second.second;
            setpoints(player,points,exp);
            setallteampoints(player,points,parent,exp);
        }
        if(command=="join"){
            lint player1=queries[i].second.first;
            lint player2=queries[i].second.second;
            if(findparent(player1,parent)!=findparent(player2,parent)){
                unionfunction(player1,player2,parent,setsize);
            }
        }
        if(command=="get"){
            lint player=queries[i].second.first;
            lint answer = findpoints(player,exp);
            ans.push_back(answer);
        }
    }
    return ans;
}

void solution(){
    lint n;cin >> n;
    lint q;cin >> q;
    vector<pair<string,pair<lint,lint>>>queries;
    forloop(0,q){
        string s;cin >> s;
        if(s=="add"){
            lint player;lint exp;
            cin >> player >> exp;
            queries.push_back({s,{player-1,exp}});
        }
        if(s=="join"){
            lint player1;lint player2;
            cin >> player1 >> player2;
            queries.push_back({s,{player1-1,player2-1}});
        }
        if(s=="get"){
            lint a;cin >> a;
            queries.push_back({s,{a-1,-1}});
        }
    }
    vector<lint>ans=solvefunction(n,queries);
    forloop(0,ans.size()){print(ans[i]);}

}
int main(){

    solution();
}