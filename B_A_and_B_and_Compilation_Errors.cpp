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

vector<lint>solvefunction(vector<lint>&arr1,vector<lint>&arr2,vector<lint>&arr3){
    lint sum1=0;
    forloop(0,arr1.size()){sum1+=arr1[i];}
    lint sum2=0;
    forloop(0,arr2.size()){sum2+=arr2[i];}
    lint sum3=0;
    forloop(0,arr3.size()){sum3+=arr3[i];}
    vector<lint>ans;
    lint first = sum1-sum2;
    lint second = sum2-sum3;
    ans.push_back(first);
    ans.push_back(second);
    return ans;

}
void solution(){
    lint n;cin >> n;
    vector<lint>arr1,arr2,arr3;
    forloop(0,n){lint x;cin >> x;arr1.push_back(x);}
    forloop(0,n-1){lint x;cin >> x;arr2.push_back(x);}
    forloop(0,n-2){lint x;cin >> x;arr3.push_back(x);}
    vector<lint>ans=solvefunction(arr1,arr2,arr3);
    forloop(0,ans.size()){print(ans[i])}


}
int main(){

    solution();
}