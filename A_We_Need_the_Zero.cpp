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
    lint n=arr.size();
    if(n&1){
        lint current = arr[0];
        forloop(1,arr.size()){
            current=current^arr[i];
        }
        return current;
    }else{
        lint current=arr[0];
        forloop(1,arr.size()){
            current=current^arr[i];
        }
        if(current==0){
            return 0;
        }else{
            return -1;
        }
    }
}
void solution(int test){
    while(test--){
        lint n;cin >> n;
        vector<lint>arr;
        forloop(0,n){lint x;cin >> x;arr.push_back(x);}
        lint ans=solvefunction(arr);
        print(ans)
    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}