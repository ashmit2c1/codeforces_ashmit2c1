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


lint solvefunction(lint n,lint k){
    lint ans=1;
    const lint MOD = (1e9)+7;
    forloop(0,k){
        ans=(ans*n)%MOD;
    }
    return ans;
}
void solution(int test){
    while(test--){
        lint n;lint k;
        cin >> n >> k;
        lint ans=solvefunction(n,k);
        print(ans)

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}