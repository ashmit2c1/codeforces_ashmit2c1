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

pair<lint,lint>solvefunction2(vector<lint>&arr,lint p){
    lint sum=0;
    forloop(0,arr.size()){
        sum+=arr[i];
    }
    lint cycles = p/sum;
    p=p%sum;
    if(p==0){
        return {1,cycles*arr.size()};
    }
    lint minlen=lintmax;
    lint index=-1;
    for(lint start=0;start<arr.size();start++){
        lint current=0;
        lint cnt=0;
        lint currindex = start ;
        while(current<p){
            current+=arr[currindex];
            cnt++;
            currindex = (currindex + 1)%arr.size();
        }
        if(cnt<minlen){
            minlen=cnt;
            index=start;
        }
    }
    return {index+1,cycles*arr.size()+minlen};
}
void solution(){
    lint n;lint p;
    cin >> n >> p;
    vector<lint>arr;
    forloop(0,n){
        lint x;cin >> x;arr.push_back(x);
    }
    pair<lint,lint> ans=solvefunction2(arr,p);
    cout << ans.first << " " << ans.second << "\n";
}
int main(){

    solution();
}