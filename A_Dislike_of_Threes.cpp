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

lint solve(lint n){
    lint ans=0;
    lint num=0;
    while(num!=n){
        ans++;
        if(ans%3!=0 && ans%10!=3){
            num++;
        }
    }
    return ans;
}
void solution(int test){
    while(test--){
        lint n;
        cin >> n;
        lint ans=solve(n);
        print(ans)
    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}