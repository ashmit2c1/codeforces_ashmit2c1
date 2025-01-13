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

lint solvefunction(string s){
    set<char>prefSt;
    set<char>sufSt;
    vector<int>prefixdistinct(s.size());
    vector<int>suffixdistinct(s.size());
    forloop(0,s.size()){
        prefSt.insert(s[i]);
        prefixdistinct[i]=prefSt.size();
    }
    for(int i=s.size()-1;i>=0;i--){
        sufSt.insert(s[i]);
        suffixdistinct[i]=sufSt.size();
    }
    lint maxSum=0;
    forloop(0,s.size()-1){
        lint sum = prefixdistinct[i] + suffixdistinct[i+1];
        maxSum = max(maxSum,sum);
    }
    return maxSum;
}


void solution(int test){
    while(test--){
        lint n;cin >> n;
        string s;cin >> s;
        lint ans=solvefunction(s);
        print(ans)

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}