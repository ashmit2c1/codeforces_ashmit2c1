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

lint solvefunction(vector<lint>&arr){
    if(is_sorted(arr.begin(),arr.end())==false){
        return 0;
    }
    lint ops=0;
    lint mindiff=lintmax;
    forloop(1,arr.size()){
        lint diff = arr[i]-arr[i-1];
        if(diff==0){
            return 1;
        }
        mindiff=min(mindiff,diff);
    }
    ops =1+  (mindiff/2);
    return ops;
}
void solution(int test){
    while(test--){
        lint n;cin >> n;
        vector<lint>arr;
        forloop(0,n){lint x; cin >> x;arr.push_back(x);}
        lint ans=solvefunction(arr);
        print(ans)

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}