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

lint solveFunction(vector<lint>& check, lint l1, lint l2, lint r1, lint r2) {
    lint cnt=0;
    forloop(0,check.size()){
        lint divby = check[i];
        lint minX=l2/divby;
        lint maxX=r2/divby;
        if(l2%divby!=0){minX=1+(l2/divby);}
        lint numbersBetween = max(0LL,min(r1,maxX)-max(minX,l1) + 1);
        cnt+=numbersBetween;
    }
    return cnt;
}

void solution(int test) {
    while (test--) {
        lint k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        vector<lint> check;
        lint mul = 1;
        while (mul <= r2) {
            check.push_back(mul);
            mul *= k;
        }
        lint ans = solveFunction(check, l1, l2, r1, r2);
        print(ans);
    }
}

int main() {
    int test;
    cin >> test;
    solution(test);
}