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


bool canCut(vector<double> &arr, lint k, double mid) {
    double pieces = 0;
    forloop(0, arr.size()) {
        pieces += floor(arr[i] / mid);
    }
    if(pieces>=k){return true;}else{return false;}
}

double solveFunction(vector<double> &arr, lint k) {
    double start=0;
    double end = 1e10;
    double ans = -1;
    while(start<end){
        double mid = start + (end-start)/2;
        if(canCut(arr,k,mid)==true){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}

void solution() {
    lint n, k;
    cin >> n >> k;
    vector<double> arr(n);
    forloop(0, n) cin >> arr[i];
    double ans=solveFunction(arr,k);
    cout << setprecision(5) << ans << "\n";
}

int main() {
    solution();
    
}