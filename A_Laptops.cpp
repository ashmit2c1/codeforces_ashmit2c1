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


bool solveFunction(vector<pair<lint,lint>>&arr){
    forloop(0,arr.size()-1){
        lint quality1= arr[i].second;
        lint quality2=arr[i+1].second;
        bool condition = quality1 > quality2;
        if(condition==true){
            return true;
        }
    }
    return false;
}

void solution(){
    lint n;cin >> n;
    vector<pair<lint,lint>>arr;
    forloop(0,n){
        lint x;lint y;cin >> x >> y;
        arr.push_back({x,y});
    }
    sort(arr.begin(),arr.end());
    bool ans = solveFunction(arr);
    if(ans==true){print("Happy Alex")}
    else{print("Poor Alex")}

}
int main(){

    solution();
}