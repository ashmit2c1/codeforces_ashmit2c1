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


void solveFunction(vector<lint>&arr){
    map<lint,lint>mp;
    forloop(0,arr.size()){mp[arr[i]]++;}
    if(mp.size()==1){
        cout << -1 << "\n";
        return;
    }
    lint smallestElement = mp.begin()->first;
    lint smallestElementFreq = mp.begin()->second;
    cout << smallestElementFreq << " " << arr.size()-smallestElementFreq;
    cout << "\n";
    mp.erase(smallestElement);
    forloop(0,smallestElementFreq){
        cout << smallestElement << " ";
    }
    cout << "\n";
    for(auto it=mp.begin();it!=mp.end();it++){
        lint freq = it->second;
        lint element = it->first;
        forloop(0,freq){
            cout << element << " ";
        }
    }
    cout << "\n";
}

void solution(int test){
    while(test--){
        lint n;cin >> n;
        vector<lint>arr;
        forloop(0,n){
            lint x;cin >> x;arr.push_back(x);
        }
        solveFunction(arr);

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}