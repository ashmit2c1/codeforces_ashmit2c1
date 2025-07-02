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

lint solve(vector<lint>&arr){
    if(arr.size()==1){
        return 0;
    }
    lint first = arr[0];
    lint second = arr[arr.size()-1];
    lint maxdiff = second-first;
    forloop(1,arr.size()){
        lint diff = arr[i]-first;
        maxdiff=max(maxdiff,diff);
    }
    forloop(0,arr.size()-1){
        lint diff = second-arr[i];
        maxdiff=max(maxdiff,diff);
    }
    forloop(0,arr.size()-1){
        lint diff = arr[i]-arr[i+1];
        maxdiff=max(maxdiff,diff);
    }
    return maxdiff;
}
void solution(int test){
    while(test--){
        lint n;cin >> n;
        vector<lint>arr;
        forloop(0,n){lint x;cin >> x;arr.push_back(x);}
        lint ans=solve(arr);
        print(ans)

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}