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



vector<vector<lint>>countSubarrays(vector<lint>&arr){
    vector<vector<lint>>subArrays;
    forloop(0,arr.size()){
        vector<lint>subarr;
        secondfor(i,arr.size()){
            subarr.push_back(arr[j]);
        }
        subArrays.push_back(subarr);
    }
    return subArrays;
}

lint bruteForce(vector<lint>&arr,lint k){
    vector<vector<lint>>subarrays=countSubarrays(arr);
    lint cnt=0;
    forloop(0,subarrays.size()){
        vector<lint>array=subarrays[i];
        unordered_map<lint,lint>mp;
        secondfor(0,array.size()){
            mp[array[j]]++;
            if(mp.size()<=k){cnt++;}
        }
    }
    return cnt;
}


lint solveFunction(vector<lint>&arr,lint k){
    lint left=0;lint right=0;
    lint cnt=0;unordered_map<lint,lint>mp;
    while(right < arr.size()){
        mp[arr[right]]++;
        while(mp.size()>k){
            mp[arr[left]]--;
            if(mp[arr[left]]==0){
                mp.erase(arr[left]);
            }
            left++;
        }
        cnt+=(right-left+1);
        right++;
    }
    return cnt;
}

void solution(){
    lint n;cin >> n;
    lint k;cin >> k;
    vector<lint>arr;
    forloop(0,n){lint x;cin >> x;arr.push_back(x);}
    lint ans=bruteForce(arr,k);
    print(ans)
}
int main(){

    solution();
}