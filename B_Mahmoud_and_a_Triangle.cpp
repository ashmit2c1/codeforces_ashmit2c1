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


bool solvefunction(vector<lint>& arr) {
    sort(arr.begin(), arr.end());
    forloop(1, arr.size() - 1) {
        bool case1 = arr[i-1] + arr[i] > arr[i+1];
        bool case2 = arr[i] + arr[i+1] > arr[i-1];
        bool case3 = arr[i-1] + arr[i+1] > arr[i];
        if (case1 && case2 && case3) {
            return true;
        }
    }
    return false;
}


void solution(){
    lint n;cin >> n;
    vector<lint>arr;
    forloop(0,n){lint x;cin >> x;arr.push_back(x);}
    bool ans=solvefunction(arr);
    if(ans==true){print("YES")}else{print("NO")}

}
int main(){

    solution();
}