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

bool binarySearch(vector<lint>&arr,lint element){
    lint start=0;
    lint end=arr.size()-1;
    while(start<=end){
        lint mid = start + (end-start)/2;
        if(element==arr[mid]){return true;}
        if(element>arr[mid]){start=mid+1;}
        else{end=mid-1;}
    }
    return false;
}
vector<bool>solveFunction(vector<lint>&arr,vector<lint>&queries){
    vector<bool>ansVec;
    forloop(0,queries.size()){
        lint element = queries[i];
        bool ans=binarySearch(arr,element);
        ansVec.push_back(ans);
    }
    return ansVec;
}

void solution(){
    lint n;lint q;
    cin >> n >> q;
    vector<lint>arr;
    forloop(0,n){
        lint x;cin>>x;arr.push_back(x);
    }
    vector<lint>queries;
    forloop(0,q){
        lint x;cin>>x;queries.push_back(x);
    }
    vector<bool>ans=solveFunction(arr,queries);
    forloop(0,ans.size()){
        if(ans[i]==true){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
}
int main(){

    solution();
}