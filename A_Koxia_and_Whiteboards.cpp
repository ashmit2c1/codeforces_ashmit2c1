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


lint solvefunction(vector<lint>&arr1,vector<lint>&arr2){
    sort(arr1.begin(),arr1.end());
    forloop(0,arr2.size()){
        arr1[0]=arr2[i];
        sort(arr1.begin(),arr1.end());
    }
    lint sum=0;
    forloop(0,arr1.size()){
        sum+=arr1[i];
    }
    return sum;
}

void solution(int test){
    while(test--){
        lint n;lint m;cin >> n >> m;
        vector<lint>arr1;
        vector<lint>arr2;
        forloop(0,n){lint x;cin >> x;arr1.push_back(x);}
        forloop(0,m){lint x;cin >> x;arr2.push_back(x);}
        lint ans = solvefunction(arr1,arr2);
        print(ans)

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}