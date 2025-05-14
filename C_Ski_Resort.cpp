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

lint sumfunction(lint n){
    return (n*(n+1))/2;
}
lint solvefunction(lint n, lint days, lint temp, vector<lint> arr) {
    vector<lint> temparr;
    lint cnt = 0;
    forloop(0, arr.size()) {
        lint temperature = arr[i];
        if (temperature <= temp) {
            cnt++;
        } else {
            if (cnt > 0) temparr.push_back(cnt);
            cnt = 0;
        }
    }
    if (cnt != 0) {
        temparr.push_back(cnt);
    }
    lint answer = 0;
    forloop(0, temparr.size()) {
        lint num = temparr[i];
        if (num >= days) {
            lint len = num - days + 1;
            lint ans = sumfunction(len);
            answer += ans;
        }
    }
    return answer;
}
void solution(int test){
    while(test--){
        lint days;lint k;lint temp;
        cin >> days >> k >> temp;
        vector<lint>temps;
        forloop(0,days){lint x;cin >> x;temps.push_back(x);}
        lint ans=solvefunction(days,k,temp,temps);
        print(ans)
    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}