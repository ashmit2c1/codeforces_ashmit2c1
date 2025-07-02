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
double solve(vector<lint>& arr) {
    lint sum = 0;
    for (lint i = 0; i < arr.size(); ++i) {
        sum += arr[i];
    }
    lint maxe = *max_element(arr.begin(), arr.end());
    sum -= maxe;

    double average1 = static_cast<double>(sum) / (arr.size() - 1);
    double average2 = static_cast<double>(maxe);

    return average1 + average2;
}

void solution(int test){
    while(test--){
        lint n;cin >> n;
        vector<lint>arr;
        forloop(0,n){lint x;cin >> x;arr.push_back(x);}
    cout << fixed << setprecision(9) << solve(arr) << endl;

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}