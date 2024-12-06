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


lint solveFunction(vector<string>&arr,lint x){
    lint cnt=0;
    forloop(0,arr.size()){
        lint sz=arr[i].size();
        x-=sz;
        if(x>=0){cnt++;}
        else{break;}
    }
    return cnt;
}

void solution(int test){
    while(test--){
        lint n;lint x;
        cin >> n >> x;
        vector<string>arr;
        forloop(0,n){
            string s;cin >> s;arr.push_back(s);
        }
        lint ans=solveFunction(arr,x);
        print(ans)


    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}