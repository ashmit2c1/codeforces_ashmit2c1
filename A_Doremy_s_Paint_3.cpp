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


bool solvefunction(vector<lint>&arr){
    if(arr.size()==2){
        return true;
    }
    unordered_map<lint,lint>mp;
    forloop(0,arr.size()){
        mp[arr[i]]++;
    }
    if(mp.size()>2){
        return false;
    }
    if(arr.size()&1){
        if(mp.size()==1){
            return true;
        }
        vector<lint>freq;
        for(auto it=mp.begin();it!=mp.end();it++){
            freq.push_back(it->second);
        }
        lint diff = abs(freq[0]-freq[1]);
        if(diff==1){
            return true;
        }else{
            return false;
        }
    }else{
        if(mp.size()==1){
            return true;
        }
        vector<lint>freq;
        for(auto it=mp.begin();it!=mp.end();it++){
            freq.push_back(it->second);
        }
        lint diff = abs(freq[0]-freq[1]);
        if(diff==0){
            return true;
        }else{
            return false;
        }
    }
}
void solution(int test){
    while(test--){
        lint n;cin >> n;
        vector<lint>arr;
        forloop(0,n){lint x;cin >> x;arr.push_back(x);}
        bool ans=solvefunction(arr);
        if(ans==true){print("Yes")}else{print("No")}

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}