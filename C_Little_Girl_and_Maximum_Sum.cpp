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


void makeChange(lint leftIndex,lint rightIndex,vector<lint>&temp){
    temp[leftIndex]++;
    if(rightIndex+1 < temp.size()){
        temp[rightIndex+1]--;
    }
}

lint solveFunction(vector<lint>&arr,vector<pair<lint,lint>>&queries){
    vector<lint>temp(arr.size(),0);
    forloop(0,queries.size()){
        lint leftIndex=queries[i].first-1;
        lint rightIndex=queries[i].second-1;
        makeChange(leftIndex,rightIndex,temp);
    }
    forloop(1,temp.size()){
        temp[i]+=temp[i-1];
    }
    asort(arr);
    asort(temp);
    lint sum=0;
    forloop(0,arr.size()){
        sum+=arr[i]*temp[i];
    }
    return sum;
}

void solution(){
    lint n;cin >> n;
    lint q;cin >> q;
    vector<lint>arr;
    forloop(0,n){lint x;cin >> x;arr.push_back(x);}
    vector<pair<lint,lint>>queries;
    forloop(0,q){
        lint x;lint y;
        cin >> x >> y;
        queries.push_back({x,y});
    }
    lint ans=solveFunction(arr,queries);
    print(ans)
}
int main(){

    solution();
}