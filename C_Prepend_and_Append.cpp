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
    lint left=0;
    lint right=s.size()-1;
    while(left<s.size() && right>=0){
        if(s[left]!=s[right]){
            left++;
            right--;
        }else{
            return right-left+1;
        }
    }
    return 0;

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