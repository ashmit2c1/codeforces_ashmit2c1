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

lint solve(lint n,lint k,vector<lint>&arr){
    asort(arr);
    lint cnt=0;
    lint maxcnt=0;

    forloop(0,arr.size()-1){
        lint p1 = arr[i];
        lint p2 = arr[i+1];
        lint diff = p2-p1;
        if(diff<=k){
            cnt++;
        }else{
            maxcnt = max(maxcnt,cnt);
            cnt=0;
        }
    }
    maxcnt = max(maxcnt,cnt);
    maxcnt++;
    return arr.size()-maxcnt;
}
void solution(int test){
    while(test--){
        lint n;cin >> n;
        lint k;cin >> k;
        vector<lint>arr;
        forloop(0,n){lint x;cin >> x;arr.push_back(x);}
        lint ans=solve(n,k,arr);
        print(ans)

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}