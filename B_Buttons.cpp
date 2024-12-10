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


lint solveFunction2(lint n) {
    lint ans = n + 1;
    lint term1 = (n - 2) * (n - 1) / 2;
    lint term2 = n - 2; 
    lint term3 = (n * (n - 2) * (n - 1)) / 2; 
    lint term4 = 0;
    for (lint i = 2; i <= n - 1; i++) {
        term4 += (i - 1) * i; 
    }
    ans += term1 + term2 + term3 - term4;
    return ans;
}

lint solveFunction(lint n){
    lint ans=n+1;
    lint currentButton=n-1;
    while(currentButton!=1){
        lint wrongPresses=currentButton-1;
        lint correctPress=1;
        lint corrections = wrongPresses*(n-currentButton);
        ans+=wrongPresses+correctPress+corrections;
        currentButton--;
    }
    return ans; 
}

void solution(){
    lint n;cin >> n;
    lint ans=solveFunction(n);
    print(ans)

}
int main(){

    solution();
}