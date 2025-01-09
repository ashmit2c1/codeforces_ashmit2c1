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


lint solvefunction(lint n) {
    lint ans=0;lint add=8;
    forloop(1,(n/2)+1){
        ans+=add*i;
        add+=8;
    }
    return ans;
}

void solution(int test){
    while(test--){
        lint n;cin >> n;
        lint ans=solvefunction(n);
        print(ans)

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}