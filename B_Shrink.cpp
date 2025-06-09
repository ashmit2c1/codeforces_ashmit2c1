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
vector<lint>solvefunction(lint n){
    vector<lint>ans;
    forloop(1,n+1){
        lint element = i;
        if(i%2==1){
            ans.push_back(i);
        }
    }
    for(lint i=n;i>=1;i--){
        if(i%2==0){
            ans.push_back(i);
        }
    }
    return ans;
}
void solution(int test){
    while(test--){
        lint n;cin >> n;
        vector<lint>ans=solvefunction(n);
        forloop(0,ans.size()){cout << ans[i] << " ";}cout << "\n";
    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}