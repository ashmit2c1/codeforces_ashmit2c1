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



lint solvefunction(vector<vector<lint>>&mat){
    vector<pair<lint,vector<lint>>>pairs;
    forloop(0,mat.size()){
        lint sum=0;
        secondfor(0,mat[i].size()){
            sum+=mat[i][j];
        }
        pairs.push_back({sum,mat[i]});
    }
    sort(pairs.rbegin(),pairs.rend());
    vector<lint>fin;
    forloop(0,pairs.size()){
        vector<lint>arr=pairs[i].second;
        secondfor(0,arr.size()){
            fin.push_back(arr[j]);
        }
    }
    lint tot=0;
    lint cumu=0;
    forloop(0,fin.size()){
        tot+=fin[i];
        cumu+=tot;
    }
    return cumu;
}
void solution(int test){
    while(test--){
        lint n;cin >> n;
        lint el;cin >> el;
        vector<vector<lint>>mat(n,vector<lint>(el));
        forloop(0,n){
            secondfor(0,el){
                cin >> mat[i][j];
            }
        }
        lint ans=solvefunction(mat);
        print(ans)
    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}