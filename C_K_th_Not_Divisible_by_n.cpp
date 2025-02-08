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

lint solvefunction(lint n,lint k){
    lint start=1;
    lint end = 1e10;
    lint ans=-1;
    while(start<=end){
        lint mid = start + (end-start)/2;
        lint notdiv = mid -(mid/n);
        if(notdiv>=k){
            ans=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return ans;
}
void solution(int test){
    while(test--){
        lint n;lint k;
        cin >> n >> k;
        lint ans=solvefunction(n,k);
        print(ans)

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}