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

pair<lint,lint>solvefunction(lint n,lint m,lint l,lint r ){
    if(r>=m){
        return {0,m};
    }else{
        lint diff = m-r;
        return {-diff,r};
    }
}
void solution(int test){
    while(test--){
        lint n;lint m;lint l;lint r;
        cin >> n >> m >> l >>r ;
        pair<lint,lint>ans=solvefunction(n,m,l,r);
        cout << ans.first << " " << ans.second << "\n";

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}