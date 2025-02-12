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

bool solvefunction(vector<lint>&arr1,vector<lint>&arr2){
    sort(arr2.begin(),arr2.end());
    arr1[0]=min(arr1[0],arr2[0]-arr1[0]);
    forloop(1,arr1.size()){
        lint element = arr1[i];
        lint previous = arr1[i-1];
        auto candidate = lower_bound(arr2.begin(),arr2.end(),element+previous);
        if(element>previous){
            if(candidate!=arr2.end()){
                arr1[i]=min(arr1[i],*candidate-arr1[i]);
            }
        }else if(element<previous){
            if(candidate!=arr2.end()){
                arr1[i]=*candidate-arr1[i];
            }else{
                return false;
            }
        }
    }
    return true;
}

void solution(int test) {
    while (test--) {
        lint n, m;
        cin >> n >> m;
        vector<lint> arr1, arr2;
        forloop(0, n) {
            lint x;
            cin >> x;
            arr1.push_back(x);
        }
        forloop(0, m) {
            lint x;
            cin >> x;
            arr2.push_back(x);
        }
        bool ans = solvefunction(arr1, arr2);
        if (ans == true) {
            print("YES");
        } else {
            print("NO");
        }
    }
}

int main() {
    int test;
    cin >> test;
    solution(test);
    return 0;
}