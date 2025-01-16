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
lint solvefunction(vector<lint>&arr,lint k){
    if(k>=arr.size() || arr.size()==1){return 1;}
    map<lint,lint>mp;
    forloop(0,arr.size()){mp[arr[i]]++;}
    vector<lint>newarr;
    for(auto it=mp.begin();it!=mp.end();it++){
        lint freq=it->second;
        newarr.push_back(freq);
    }
    if(k==0){
        return newarr.size();
    }
    sort(newarr.begin(),newarr.end());
    forloop(0,newarr.size()){
        lint frequency = newarr[i];
        if(k>0){
            if(k>=newarr[i]){
                k-=newarr[i];
                newarr[i]=0;
            }
        }
    }lint cnt=0;
    forloop(0,newarr.size()){
        if(newarr[i]>0){cnt++;}
    }
    return cnt;
}

void solution(int test){
    while(test--){
        lint n;lint k;
        cin >> n >> k;
        vector<lint>arr;
        forloop(0,n){lint x;cin >> x;arr.push_back(x);}
        lint ans=solvefunction(arr,k);
        print(ans)

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}