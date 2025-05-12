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

vector<lint>solvefunction(vector<lint>&arr1,vector<lint>&arr2,vector<lint>&arr3,vector<lint>&arr4){
    lint i=0;lint j=0;lint k=0;lint m=0;
    lint mindiff=lintmax;
    vector<lint>ans(4,-1);
    while(i<arr1.size() && j<arr2.size() && k<arr3.size() && m<arr4.size()){
        lint currmin = min({arr1[i],arr2[j],arr3[k],arr4[m]});
        lint currmax = max({arr1[i],arr2[j],arr3[k],arr4[m]});
        lint diff = currmax-currmin;
        if(diff<mindiff){
            mindiff=diff;
            ans[0]=arr1[i];
            ans[1]=arr2[j];
            ans[2]=arr3[k];
            ans[3]=arr4[m];
        }
        if(arr1[i]==currmin){i++;}
        else if(arr2[j]==currmin){j++;}
        else if(arr3[k]==currmin){k++;}
        else{m++;}
    }
    return ans;
}
void solution(){
    lint n1;cin >> n1;
    vector<lint>arr1;
    forloop(0,n1){lint x;cin >> x;arr1.push_back(x);}
    lint n2;cin >> n2;
    vector<lint>arr2;
    forloop(0,n2){lint x;cin >> x;arr2.push_back(x);}
    lint n3;cin >> n3;
    vector<lint>arr3;
    forloop(0,n3){lint x;cin >> x;arr3.push_back(x);}
    lint n4;cin >> n4;
    vector<lint>arr4;
    forloop(0,n4){lint x;cin >> x;arr4.push_back(x);}
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    sort(arr3.begin(),arr3.end());
    sort(arr4.begin(),arr4.end());
    vector<lint>ans=solvefunction(arr1,arr2,arr3,arr4);
    forloop(0,ans.size()){cout << ans[i] << " ";}
    cout << "\n";

}
int main(){

    solution();
}