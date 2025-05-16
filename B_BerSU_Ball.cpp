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

lint solvefunction(vector<lint>&boys,vector<lint>&girls){
    lint cnt=0;
    lint i=0;
    lint j=0;
    sort(girls.begin(),girls.end());
    sort(boys.begin(),boys.end());
    while(i<boys.size() && j<girls.size()){
        lint current_boy = boys[i];
        lint current_girl = girls[j];
        lint diff = abs(current_boy-current_girl);
        if(diff<=1){i++;j++;cnt++;}
        else if(current_girl>current_boy){i++;}
        else{j++;}
    }
    return cnt;
}
void solution(){
    lint n;cin >> n;
    vector<lint>boys;
    forloop(0,n){lint x;cin >> x;boys.push_back(x);}
    lint m;cin >> m;
    vector<lint>girls;
    forloop(0,m){lint x;cin >> x;girls.push_back(x);}
    lint ans=solvefunction(boys,girls);
    print(ans)

}
int main(){

    solution();
}