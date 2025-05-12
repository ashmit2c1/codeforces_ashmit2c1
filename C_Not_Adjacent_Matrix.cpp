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
vector<vector<lint>> solvefunction(lint n) {
    vector<vector<lint>> ans(n, vector<lint>(n));
    lint odd = 1, even = 2;
    forloop(0, n) {
        secondfor(0, n) {
            if (odd <= n * n) {
                ans[i][j] = odd;
                odd += 2;
            } else {
                ans[i][j] = even;
                even += 2;
            }
        }
    }
    return ans;
}
void solution(int test){
    while(test--){
        lint n;cin >> n;
        if(n==2){
            cout << -1 << "\n";
        }else{
            vector<vector<lint>>ans=solvefunction(n);
            forloop(0,ans.size()){
                secondfor(0,ans[i].size()){
                    cout << ans[i][j] << " ";
                }
                cout << "\n";
            }
        }
    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}