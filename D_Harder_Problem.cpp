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
vector<lint>solveFunction(vector<lint>&arr){
    lint n=arr.size();set<lint>st;
    forloop(1,n+1){
        st.insert(i);
    }
    vector<lint>ans;
    forloop(0,arr.size()){
        if(st.find(arr[i])!=st.end()){
            ans.push_back(arr[i]);
            st.erase(arr[i]);
        }
        else{
            ans.push_back(*st.begin());
            st.erase(*st.begin());
        }
    }
    return ans;
}
/*vector<lint> solveFunction(vector<lint>& arr) {
    lint n = arr.size();
    vector<lint> freq(n + 1, 0);
    vector<lint> b(n);
    lint max_freq = 0;
    lint next_new = 1;
    for (lint i = 0; i < n; i++) {
        lint req = arr[i];
        if (i == 0) {
            b[i] = req;
            freq[req] = 1;
            max_freq = 1;
        } else {
            if (freq[req] < max_freq) {
                b[i] = req;
                freq[req]++;
                if (freq[req] > max_freq) {
                    max_freq = freq[req];
                }
            } else {
                while (next_new <= n && (freq[next_new] != 0 || next_new == req)) {
                    next_new++;
                }
                if (next_new <= n && freq[next_new] < max_freq) {
                    b[i] = next_new;
                    freq[next_new]++;
                } else {
                    b[i] = req;
                    freq[req]++;
                    if (freq[req] > max_freq) {
                        max_freq = freq[req];
                    }
                }
            }
        }
    }
    return b;
}*/

void solution(int test){
    while(test--){
        lint n;cin >> n;
        vector<lint>arr;
        forloop(0,n){
            lint x;cin >> x;arr.push_back(x);
        }
        vector<lint>ans=solveFunction(arr);
        forloop(0,ans.size()){
            cout << ans[i] << " ";
        }
        cout << "\n";

    }
}
int main(){
    int test;
    cin >> test;
    solution(test);
}