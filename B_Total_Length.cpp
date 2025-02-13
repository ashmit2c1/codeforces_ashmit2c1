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


vector<vector<lint>>findsubarrays(vector<lint>&arr){
    vector<vector<lint>>subarrays;
    forloop(0,arr.size()){
        secondfor(i,arr.size()){
            vector<lint>subarray;
            for(lint k=i;k<=j;k++){
                subarray.push_back(arr[k]);
            }
            subarrays.push_back(subarray);
        }
    }
    return subarrays;
}
lint findcnt(vector<vector<lint>>&arr,lint target){
    lint cumu=0;
    forloop(0,arr.size()){
        vector<lint>check=arr[i];
        lint sum=0;
        secondfor(0,check.size()){
            sum+=check[j];
        }
        if(sum<=target){cumu+=check.size();}
    }
    return cumu;
}
lint solvefunction(vector<lint>&arr,lint sum){
    vector<vector<lint>>subarrays=findsubarrays(arr);
    lint cnt=findcnt(subarrays,sum);
    return cnt;

}
// second method 
lint findsum(lint n){
    return (n*(n+1)/2);
}
lint solvefunction2(vector<lint>& arr, lint target) {
    lint left = 0, right = 0;
    lint sum = 0, res = 0;
    while (right < arr.size()) {
        sum += arr[right]; 
        while (sum > target) {  
            sum -= arr[left];
            left++;
        }
        lint len = right-left+1;
        res+=findsum(len);
        right++;
    }
    return res;
}

void solution(){
    lint n;cin >> n;
    lint s;cin >> s;
    vector<lint>arr;
    forloop(0,n){lint x;cin >> x;arr.push_back(x);}
    lint ans=solvefunction2(arr,s);
    print(ans)

}
int main(){

    solution();
}