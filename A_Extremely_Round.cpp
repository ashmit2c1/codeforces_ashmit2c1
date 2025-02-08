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

bool checkfunction(lint n){
    lint cnt=0;
    while(n>0){
        lint rem = n%10;
        if(rem!=0){
            cnt++;
        }
        n=n/10;
    }
    if(cnt==1){
        return true;
    }else{
        return false;
    }
}
lint solvefunction(lint n){
    lint cnt=0;
    forloop(1,n+1){
        bool check = checkfunction(i);
        if(check==true){
            cnt++;
        }
    }
    return cnt;
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