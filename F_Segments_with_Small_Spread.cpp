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

lint solveFunction(deque<int>&Mn,deque<int>&Mx,vector<lint>&v,lint k){
    lint ans = 0;
    int l = 0;
    forloop(0, v.size()) {
        while (!Mn.empty() && v[Mn.back()] > v[i]) Mn.pop_back();
        while (!Mx.empty() && v[Mx.back()] < v[i]) Mx.pop_back();
        Mn.push_back(i), Mx.push_back(i);

        while (v[Mx.front()] - v[Mn.front()] > k) {
            l++;
            while (Mx.front() < l) Mx.pop_front();
            while (Mn.front() < l) Mn.pop_front();
        }
        ans += i - l + 1;
    }
    return ans;
}


void solution(){
    int n;
    lint k;
    vector<lint> v;
    deque<int> Mn, Mx;

    cin >> n >> k;
    v.resize(n);
    forloop(0, n) cin >> v[i];
    lint ans=solveFunction(Mn,Mx,v,k);
    print(ans)
}

int main(){
    solution();
}