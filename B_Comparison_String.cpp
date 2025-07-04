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

lint solve(string s){
    lint maxlen=0;
    lint len=1;
    forloop(0,s.size()-1){
        if(s[i]==s[i+1]){
            len++;
        }else{
            maxlen=max(maxlen,len);
            len=1;
        }
    }
    maxlen=max(maxlen,len);
    return maxlen+1;
}
void solution(int test){
    while(test--){
        lint n;cin >> n;
        string s;cin >> s;
        lint ans=solve(s);
        print(ans)

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}