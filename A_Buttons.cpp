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
string solveFunction(lint a, lint b, lint c) {
    if(c&1){
        if(b>a){
            return "Second";
        }
        else{
            return "First";
        }
    }
    else{
        if(a>b){
            return "First";
        }
        else{
            return "Second";
        }
    }
}

void solution(int test) {
    while (test--) {
        lint a, b, c;
        cin >> a >> b >> c;
        string ans = solveFunction(a, b, c);
        print(ans);
    }
}

int main() {
    int test;
    cin >> test;
    solution(test);
    return 0;
}