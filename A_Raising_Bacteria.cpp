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


lint findPower(lint n){
    lint power=1;
    while(power<=n){
        power=power<<1;
    }
    return power>>1;
}

lint solveFunction(lint n){
    lint ans=1;
    while(n>1){
        if(n%2!=0){
            n=n-1;ans++;
        }
        else{
            n=n/2;
        }
    }
    return ans;
}

void solution(){
    lint n;cin >> n;
    lint ans=findPower(n);
    print(ans)

}
int main(){

    solution();
}