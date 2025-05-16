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

lint solvefunction2(vector<lint>&arr){
    lint cnt=0;
    forloop(0,arr.size()){
        secondfor(i+1,arr.size()){
            lint diff = arr[j]-arr[i];
            lint check = j-i;
            if(diff==check){cnt++;}
        }
    }
    return cnt;
}
lint solvefunction(vector<lint>&arr){
    lint cnt=0;
    unordered_map<int,int>mp;
    forloop(0,arr.size()){
        lint diff = arr[i]-i;
        mp[diff]++;
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        lint num = it->second;
        cnt+=(num)*(num-1)/2;
    }
    return cnt;
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