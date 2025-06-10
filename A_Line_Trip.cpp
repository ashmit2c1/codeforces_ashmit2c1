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


lint solvefunction(vector<lint>&arr){
    lint dist = arr[arr.size()-1]-arr[arr.size()-2];
    dist+=dist;
    vector<lint>diff(arr.size());
    forloop(1,arr.size()){
        diff[i]=arr[i]-arr[i-1];
    }
    forloop(0,diff.size()){
        dist=max(dist,diff[i]);
    }
    return dist;
}

void solution(int test){
    while(test--){
        lint n;cin >> n;
        lint distance;cin >> distance;
        vector<lint>arr;
        arr.push_back(0);
        forloop(0,n){lint x;cin >> x;arr.push_back(x);}
        arr.push_back(distance);
        lint ans=solvefunction(arr);
        print(ans)

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}