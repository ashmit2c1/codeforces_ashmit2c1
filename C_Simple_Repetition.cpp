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
    if(n <= 1) return false;
    if(n == 2) return true;
    for(lint i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
bool solvefunction(lint n, lint k){
    if(k == 1){
        return checkfunction(n);
    }

    if(k > 1 && n > 1){
        return false;
    }
    if(k > 1 && n == 1){
        string s = "";
        forloop(0, k){
            s += to_string(n);
        }
        lint num = stoll(s);
        return checkfunction(num);
    }
}
void solution(int test){
    while(test--){
        lint n;cin >> n;
        lint k;cin >> k;
        bool ans=solvefunction(n,k);  
        if(ans==true){print("YES")}else{print("NO")}
    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}