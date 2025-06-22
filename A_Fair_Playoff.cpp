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

bool solve(vector<lint>&arr){
    lint a=arr[0];
    lint b=arr[1];
    lint first = max(a,b);
    lint c = arr[2];
    lint d = arr[3];
    lint second = max(c,d);
    sort(arr.begin(),arr.end());
    if((first==arr[2] && second==arr[3]) || (first==arr[3] && second==arr[2])){
        return true;
    }
    return false;
}
void solution(int test){
    while(test--){
        lint n=4;
        vector<lint>arr;
        forloop(0,n){
            lint x;cin >> x;arr.push_back(x);
        }
        bool ans=solve(arr);
        if(ans==true){print("YES")}else{print("NO")}
    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}