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


lint solveFunction(vector<lint>&arr,lint s){
    lint right=0;
    lint left=0;
    lint sum=0;
    lint maxLen=0;
    while(right<arr.size()){
        sum+=arr[right];
        while(sum>s){
            sum-=arr[left];
            left++;
        }
        if(sum<=s){
            maxLen=max(maxLen,right-left+1);
        }
        right++;
    }
    return maxLen;
}
void solution(){
    lint n;lint s;cin >> n >> s;
    vector<lint>arr;
    forloop(0,n){lint x;cin >> x;arr.push_back(x);}
    lint ans=solveFunction(arr,s);
    print(ans)

}
int main(){

    solution();
}