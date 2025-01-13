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


lint solvefunction(lint n,lint m){
    if(m%n!=0){
        return -1;
    }
    if(m==n){
        return 0;
    }
    lint ans=0;
    lint quo = m/n;
    while(quo%3==0){
        quo/=3;ans++;
    }
    while(quo%2==0){
        quo/=2;ans++;
    }
    if(quo!=1){
        return -1;
    }
    else{
        return ans;
    }
    
}

void solution(){
    lint n;lint m;cin >> n >> m;
    lint ans=solvefunction(n,m);
    print(ans)

}
int main(){

    solution();
}