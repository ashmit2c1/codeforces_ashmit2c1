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

lint solvefunction(lint n, lint x) {
    lint cnt = 0;
    forloop(1, n + 1) {
        if (x % i == 0 && x / i <= n) {
            cnt++;
        }
    }
    return cnt;
}
void solution(){
    lint n;cin >> n;
    lint x;cin >> x;
    lint ans=solvefunction(n,x);
    print(ans)

}
int main(){

    solution();
}