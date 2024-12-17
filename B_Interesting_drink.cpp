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

vector<lint>solveFunction(vector<lint>&prices,vector<lint>&coins){
    sort(prices.begin(),prices.end());
    vector<lint>ans;
    forloop(0,coins.size()){
        lint currentCoins=coins[i];
        lint shops = upper_bound(prices.begin(), prices.end(), currentCoins) - prices.begin();
        ans.push_back(shops);
    }
    return ans;
}

void solution(){
    lint n;cin >> n;
    vector<lint>prices;
    forloop(0,n){lint x;cin >> x;prices.push_back(x);}
    lint q;cin >> q;
    vector<lint>coins;
    forloop(0,q){lint x;cin >> x;coins.push_back(x);}
    vector<lint>ans=solveFunction(prices,coins);
    forloop(0,ans.size()){print(ans[i])}

}
int main(){

    solution();
}