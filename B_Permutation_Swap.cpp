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

lint gcd(lint a,lint b){
    while(b!=0){
        lint rem = a%b;
        a=b;
        b=rem;
    }
    return a;
}
lint solvefunction(vector<lint>&arr){
    vector<lint>res;
    forloop(0,arr.size()){
        lint index=i+1;
        lint val = arr[i];
        lint diff = abs(arr[i]-index);
        if(diff!=0){res.push_back(diff);}
    }
    lint ans=res[0];
    forloop(1,res.size()){
        ans=gcd(ans,res[i]);
    }
    return ans;
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